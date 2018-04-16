#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QTextEdit>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *testbutton1 = new QPushButton(this);
    testbutton1->setGeometry(20,20,100,20);
    testbutton1->setText("Knopf1");

    QTextEdit *Textfeld = new QTextEdit(this);
    Textfeld->setGeometry(20,70,100,20);

    QLineEdit *LineEdit = new QLineEdit(this);
    LineEdit->setGeometry(20,120,100,20);

    QLabel *Label = new QLabel(this);
    Label->setGeometry(20,170,100,20);
    Label->setText("Hallo");


}

Widget::~Widget()
{
    delete ui;
}




