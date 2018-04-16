#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *testbutton1 = new QPushButton(this);
    testbutton1->setGeometry(20,20,100,20);
    testbutton1->setText("Knopf1");

    QPushButton *testbutton2 = new QPushButton(this);
    testbutton2->setGeometry(120,20,100,20);
    testbutton2->setText("Knopf2");

    QPushButton *testbutton3 = new QPushButton(this);
    testbutton3->setGeometry(220,20,100,20);
    testbutton3->setText("Knopf3");

}

Widget::~Widget()
{
    delete ui;
}
