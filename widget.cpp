#include "widget.h"


Widget::Widget():ui(new Ui::Widget)
{
    ui->setupUi(this);

//    text1=new QLabel(this);
//    text1->setText("Rechnung:");
//    text1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    /*--------------- Zahlen ---------------*/

    zahl1=new QPushButton("1");
    zahl1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl2=new QPushButton("2");
    zahl2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl3=new QPushButton("3");
    zahl3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl4=new QPushButton("4");
    zahl4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl5=new QPushButton("5");
    zahl5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl6=new QPushButton("6");
    zahl6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl7=new QPushButton("7");
    zahl7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl8=new QPushButton("8");
    zahl8->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    zahl9=new QPushButton("9");
    zahl9->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);



    Eingabetext=new QLineEdit();
    Eingabetext->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    /*--------------- Ausgabe ---------------*/
    layout = new QGridLayout;

    layout->addWidget(Eingabetext, 0, 0, 1, 3);    // xpos, ypos, höhe, breite

    layout->addWidget(zahl7, 1, 0);
    layout->addWidget(zahl8, 1, 1);
    layout->addWidget(zahl9, 1, 2);

    layout->addWidget(zahl4, 2, 0);
    layout->addWidget(zahl5, 2, 1);
    layout->addWidget(zahl6, 2, 2);

    layout->addWidget(zahl1, 3, 0);
    layout->addWidget(zahl2, 3, 1);
    layout->addWidget(zahl3, 3, 2);

    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}




