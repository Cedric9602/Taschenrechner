#include "widget.h"


Widget::Widget():ui(new Ui::Widget)
{
    ui->setupUi(this);

    vbox=new QVBoxLayout;
    vbox->setSpacing(1);

    ledit=new QLineEdit(this);
    ledit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    text=new QLabel(this);
    text->setText("Ausgabe");
    text->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    neuerknopf=new QPushButton("Test",this);
    neuerknopf->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    vbox->addWidget(ledit);
    vbox->addWidget(text);
    vbox->addWidget(neuerknopf);
    setLayout(vbox);

}

Widget::~Widget()
{
    delete ui;
}




