#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_do_it.h"
#include <string>
#include <random>
using namespace std;


class Qt_do_it : public QMainWindow
{
    Q_OBJECT

public:
    Qt_do_it(QWidget *parent = Q_NULLPTR);

    int input_correct(int input); 
 
    void process_correct();
    void process_close();
    void process_up();
    void process_down();
    void process_reset();
    void process_wrong();

private:
    Ui::Qt_do_itClass ui;
    
    int answer = 10;
    int leftChance = 5;
    int max = 50;

    default_random_engine generator;

public slots:
    void judge_input();
};
