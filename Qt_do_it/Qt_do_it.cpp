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
            //������ ���
            process_correct();
            result = 0;
        }
        else {
            //����� ���
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
    string status= string("���� ��ȸ��") + to_string(leftChance) + string("���Դϴ�.");
    ui.label_status->setText(QString::fromLocal8Bit(status.c_str()));
    
   
    if (leftChance == 0) {
        string status = string("�й� ");
        ui.label_status->setText(QString::fromLocal8Bit(status.c_str()));
        process_reset();
        leftChance = 6;
    }
    
   

    return result;
}


void Qt_do_it::process_correct()
{
    
        string message("�����Դϴ�!");
        ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));
        ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/correct.jpg"));
       
}

void Qt_do_it::process_close()
{
    string message("�������ϴ�!");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));

    ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/close.png"));
}
void Qt_do_it::process_up()
{
    string message("��!");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));

    ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/up.jpg"));
}

void Qt_do_it::process_down()
{
    string message("�ٿ�!");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));

    ui.label_image->setPixmap(QPixmap(":/Qt_do_it/Desktop/down.jpg"));
}
void Qt_do_it::process_reset()
{
    string message("������ �ٽ� �����ϰڽ��ϴ�.");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));
    

}
void Qt_do_it::process_wrong()
{
    string message("xx�߸��� �Է�xx");
    ui.label_message->setText(QString::fromLocal8Bit(message.c_str()));


}
void Qt_do_it::judge_input()
{
    QString inputText = ui.lineEdit->text();
    int inputNumber = inputText.toInt();
    int result = input_correct(inputNumber);
    
}