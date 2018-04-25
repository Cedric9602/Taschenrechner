#include "widget.h"



Widget::Widget():ui(new Ui::Widget)
{
    ui->setupUi(this);


    Eingabetext=new QLineEdit();
    Eingabetext->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    Eingabetext->setPlaceholderText(QString("Rechnung hier einfügen..."));

    text=new QLabel();
    text->setText("Ergebnis:");
    text->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    Ans = Colored_Button("\" ERGEBNIS \"", QColor(Qt::white));        //"ERGEBNIS" mit dem berechneten String von Marcel ersetzen (=Ans-Funktion vom Taschenrechner)


    /*--------------- Buttons ---------------*/
    zahl0 = Colored_Button("0", QColor(Qt::lightGray));
    connect(zahl0, SIGNAL(clicked()), this, SLOT(zahl0_clicked()));

    zahl1 = Colored_Button("1", QColor(Qt::lightGray));
    connect(zahl1, SIGNAL(clicked()), this, SLOT(zahl1_clicked()));

    zahl2 = Colored_Button("2", QColor(Qt::lightGray));
    connect(zahl2, SIGNAL(clicked()), this, SLOT(zahl2_clicked()));

    zahl3 = Colored_Button("3", QColor(Qt::lightGray));
    connect(zahl3, SIGNAL(clicked()), this, SLOT(zahl3_clicked()));

    zahl4 = Colored_Button("4", QColor(Qt::lightGray));
    connect(zahl4, SIGNAL(clicked()), this, SLOT(zahl4_clicked()));

    zahl5 = Colored_Button("5", QColor(Qt::lightGray));
    connect(zahl5, SIGNAL(clicked()), this, SLOT(zahl5_clicked()));

    zahl6 = Colored_Button("6", QColor(Qt::lightGray));
    connect(zahl6, SIGNAL(clicked()), this, SLOT(zahl6_clicked()));

    zahl7 = Colored_Button("7", QColor(Qt::lightGray));
    connect(zahl7, SIGNAL(clicked()), this, SLOT(zahl7_clicked()));

    zahl8 = Colored_Button("8", QColor(Qt::lightGray));
    connect(zahl8, SIGNAL(clicked()), this, SLOT(zahl8_clicked()));

    zahl9 = Colored_Button("9", QColor(Qt::lightGray));
    connect(zahl9, SIGNAL(clicked()), this, SLOT(zahl9_clicked()));


    k_auf = Colored_Button("(", QColor(Qt::gray));
    connect(k_auf, SIGNAL(clicked()), this, SLOT(k_auf_clicked()));

    k_zu = Colored_Button(")", QColor(Qt::gray));
    connect(k_zu, SIGNAL(clicked()), this, SLOT(k_zu_clicked()));

    wurzel = Colored_Button("sqrt(", QColor(Qt::gray));
    connect(wurzel, SIGNAL(clicked()), this, SLOT(wurzel_clicked()));

    potenz = Colored_Button("^(", QColor(Qt::gray));
    connect(potenz, SIGNAL(clicked()), this, SLOT(potenz_clicked()));

    DEL = Colored_Button("DEL", QColor(Qt::darkCyan));
    connect(DEL, SIGNAL(clicked()), this, SLOT(DEL_clicked()));

    AC = Colored_Button("AC", QColor(Qt::darkCyan));
    connect(AC, SIGNAL(clicked()), this, SLOT(AC_clicked()));

    komma = Colored_Button(",", QColor(Qt::gray));
    connect(komma, SIGNAL(clicked()), this, SLOT(komma_clicked()));

    add = Colored_Button("+", QColor(Qt::gray));
    connect(add, SIGNAL(clicked()), this, SLOT(add_clicked()));

    sub = Colored_Button("-", QColor(Qt::gray));
    connect(sub, SIGNAL(clicked()), this, SLOT(sub_clicked()));

    mult = Colored_Button("*", QColor(Qt::gray));
    connect(mult, SIGNAL(clicked()), this, SLOT(mult_clicked()));

    div = Colored_Button("/", QColor(Qt::gray));
    connect(div, SIGNAL(clicked()), this, SLOT(div_clicked()));

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

void Widget::zahl0_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("0");
    Eingabetext->setText(a);
}

void Widget::zahl1_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("1");
    Eingabetext->setText(a);
}

void Widget::zahl2_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("2");
    Eingabetext->setText(a);
}

void Widget::zahl3_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("3");
    Eingabetext->setText(a);
}

void Widget::zahl4_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("4");
    Eingabetext->setText(a);
}

void Widget::zahl5_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("5");
    Eingabetext->setText(a);
}

void Widget::zahl6_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("6");
    Eingabetext->setText(a);
}

void Widget::zahl7_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("7");
    Eingabetext->setText(a);
}

void Widget::zahl8_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("8");
    Eingabetext->setText(a);
}

void Widget::zahl9_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("9");
    Eingabetext->setText(a);
}

void Widget::k_auf_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("(");
    Eingabetext->setText(a);
}

void Widget::k_zu_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back(")");
    Eingabetext->setText(a);
}

void Widget::wurzel_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("sqrt(");
    Eingabetext->setText(a);
}

void Widget::potenz_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("^(");
    Eingabetext->setText(a);
}

void Widget::komma_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back(".");
    Eingabetext->setText(a);
}

void Widget::add_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("+");
    Eingabetext->setText(a);
}

void Widget::sub_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("-");
    Eingabetext->setText(a);
}

void Widget::mult_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("*");
    Eingabetext->setText(a);
}

void Widget::div_clicked(){
    QString a;
    a = Eingabetext->text();
    a.push_back("/");
    Eingabetext->setText(a);
}

void Widget::DEL_clicked(){
    QString a;
    a = Eingabetext->text();
    a = a.left(a.length() - 1);
    Eingabetext->setText(a);
}

void Widget::AC_clicked(){
    Eingabetext->setText("");
}
