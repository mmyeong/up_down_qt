#include "Qt_do_it.h"
#include <chrono>
Qt_do_it::Qt_do_it(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    generator.seed(chrono::system_clock::now().time_since_epoch().count());
    mt19937_64 randomEngine(generator());
    uniform_int_distribution<int> distribution(1, 50);
    answer = distribution(randomEngine);
}

int Qt_do_it::input_correct(int input)
{
    
    int result = -1;
    if (input <= answer + 1 && input >= answer - 1){
        if (input == answer)
        {
            //정답일 경우
            process_correct();
            result = 0;
        }
        else {
            //가까울 경우
            process_close();
            result = 1;
        }
        
    }
    else {
        if (input < answer) {
            //up
            process_up();
            result =2;
        }
        else if (input >= (max + 1)) {
            process_wrong();
        }
        else {
            //down
            process_down();
            result = 3;
        }
    }
    
    
    leftChance = leftChance -1;
    string status= string("남은 기회는") + to_string(leftChance) + string("번입니다.");
    ui.label_status->setText(QString::fromLocal8Bit(status.c_str()));
    
   
    if (leftChance == 0) {
        string status = string("패배 ");
        ui.label_status->setText(QString::fromLocal8Bit(status.c_str()));
        process_reset();
        leftChance = 6;
    }
    
   

    return result;
}


void Qt_do_it::process_correct()
{
    
        string message("정답입니다!");
        ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));
        ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/correct.jpg"));
       
}

void Qt_do_it::process_close()
{
    string message("가깝습니다!");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));

    ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/close.png"));
}
void Qt_do_it::process_up()
{
    string message("업!");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));

    ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/up.jpg"));
}

void Qt_do_it::process_down()
{
    string message("다운!");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));

    ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/down.jpg"));
}
void Qt_do_it::process_reset()
{
    string message("게임을 다시 시작하겠습니다.");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));
    

}
void Qt_do_it::process_wrong()
{
    string message("xx잘못된 입력xx");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));


}
void Qt_do_it::judge_input()
{
    QString inputText = ui.lineEdit->text();
    int inputNumber = inputText.toInt();
    int result = input_correct(inputNumber);
    
}