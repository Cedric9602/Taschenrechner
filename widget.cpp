#include "widget.h"



Widget::Widget():ui(new Ui::Widget)
{
    ui->setupUi(this);


    Eingabetext=new QLineEdit();
    Eingabetext->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    text=new QLabel();
    text->setText("Ergebnis:");
    text->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    Ans = Colored_Button("\" ERGEBNIS \"", QColor(Qt::white));        //"ERGEBNIS" mit dem berechneten String von Marcel ersetzen (=Ans-Funktion vom Taschenrechner)


    /*--------------- Buttons ---------------*/
    zahl0 = Colored_Button("0", QColor(Qt::lightGray));

    zahl1 = Colored_Button("1", QColor(Qt::lightGray));

    zahl2 = Colored_Button("2", QColor(Qt::lightGray));

    zahl3 = Colored_Button("3", QColor(Qt::lightGray));

    zahl4 = Colored_Button("4", QColor(Qt::lightGray));

    zahl5 = Colored_Button("5", QColor(Qt::lightGray));

    zahl6 = Colored_Button("6", QColor(Qt::lightGray));

    zahl7 = Colored_Button("7", QColor(Qt::lightGray));

    zahl8 = Colored_Button("8", QColor(Qt::lightGray));

    zahl9 = Colored_Button("9", QColor(Qt::lightGray));


    k_auf = Colored_Button("(", QColor(Qt::gray));

    k_zu = Colored_Button(")", QColor(Qt::gray));

    wurzel = Colored_Button("sqrt(", QColor(Qt::gray));

    potenz = Colored_Button("^(", QColor(Qt::gray));

    DEL = Colored_Button("DEL", QColor(Qt::darkCyan));

    AC = Colored_Button("AC", QColor(Qt::darkCyan));

    komma = Colored_Button(",", QColor(Qt::gray));

<<<<<<< HEAD
    add = Colored_Button("+", QColor(Qt::gray));

    sub = Colored_Button("-", QColor(Qt::gray));
=======
    QLabel *Label = new QLabel(this);
    Label->setGeometry(20,170,100,20);
    Label->setText("Hallo");
//asdasd
//test
>>>>>>> test

    mult = Colored_Button("*", QColor(Qt::gray));

    div = Colored_Button("/", QColor(Qt::gray));

    calc = Colored_Button("=", QColor(Qt::gray));


    /*--------------- Ausgabe ---------------*/
    layout = new QGridLayout;

    layout->addWidget(Eingabetext, 0, 0, 1, 4);    // zeile, spalte, höhe, breite
    layout->addWidget(text, 1, 0, 1, 2);
    layout->addWidget(Ans, 1, 1, 1, 2);

    layout->addWidget(k_auf, 2, 0);
    layout->addWidget(k_zu, 2, 1);
    layout->addWidget(DEL, 2, 2);
    layout->addWidget(AC, 2, 3);

    layout->addWidget(wurzel, 3, 0);
    layout->addWidget(potenz, 3, 1);

    layout->addWidget(zahl7, 4, 0);
    layout->addWidget(zahl8, 4, 1);
    layout->addWidget(zahl9, 4, 2);

    layout->addWidget(zahl4, 5, 0);
    layout->addWidget(zahl5, 5, 1);
    layout->addWidget(zahl6, 5, 2);

    layout->addWidget(zahl1, 6, 0);
    layout->addWidget(zahl2, 6, 1);
    layout->addWidget(zahl3, 6, 2);

    layout->addWidget(zahl0, 7, 1);
    layout->addWidget(komma, 7, 0);

    layout->addWidget(div, 3, 3);
    layout->addWidget(mult, 4, 3);
    layout->addWidget(sub, 5, 3);
    layout->addWidget(add, 6, 3);
    layout->addWidget(calc, 7, 3);

    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}



QPushButton *Colored_Button(QString text, QColor color) {
    QPushButton *button = new QPushButton(text);
    button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, color);
    button->setAutoFillBackground(true);
    button->setFlat(true);
    button->setPalette(pal);



    return button;
}



