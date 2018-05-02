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

    Ans = Colored_Button("", QColor(Qt::white));
    connect(Ans, SIGNAL(clicked()), this, SLOT(button_clicked()));


    /*--------------- Buttons ---------------*/
    zahl0 = Colored_Button("0", QColor(Qt::lightGray));
    connect(zahl0, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl1 = Colored_Button("1", QColor(Qt::lightGray));
    connect(zahl1, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl2 = Colored_Button("2", QColor(Qt::lightGray));
    connect(zahl2, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl3 = Colored_Button("3", QColor(Qt::lightGray));
    connect(zahl3, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl4 = Colored_Button("4", QColor(Qt::lightGray));
    connect(zahl4, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl5 = Colored_Button("5", QColor(Qt::lightGray));
    connect(zahl5, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl6 = Colored_Button("6", QColor(Qt::lightGray));
    connect(zahl6, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl7 = Colored_Button("7", QColor(Qt::lightGray));
    connect(zahl7, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl8 = Colored_Button("8", QColor(Qt::lightGray));
    connect(zahl8, SIGNAL(clicked()), this, SLOT(button_clicked()));

    zahl9 = Colored_Button("9", QColor(Qt::lightGray));
    connect(zahl9, SIGNAL(clicked()), this, SLOT(button_clicked()));


    k_auf = Colored_Button("(", QColor(Qt::gray));
    connect(k_auf, SIGNAL(clicked()), this, SLOT(button_clicked()));

    k_zu = Colored_Button(")", QColor(Qt::gray));
    connect(k_zu, SIGNAL(clicked()), this, SLOT(button_clicked()));

    wurzel = Colored_Button("sqrt(", QColor(Qt::gray));
    connect(wurzel, SIGNAL(clicked()), this, SLOT(button_clicked()));

    potenz = Colored_Button("^(", QColor(Qt::gray));
    connect(potenz, SIGNAL(clicked()), this, SLOT(button_clicked()));

    komma = Colored_Button(".", QColor(Qt::gray));
    connect(komma, SIGNAL(clicked()), this, SLOT(button_clicked()));

    add = Colored_Button("+", QColor(Qt::gray));
    connect(add, SIGNAL(clicked()), this, SLOT(button_clicked()));

    sub = Colored_Button("-", QColor(Qt::gray));
    connect(sub, SIGNAL(clicked()), this, SLOT(button_clicked()));

    mult = Colored_Button("*", QColor(Qt::gray));
    connect(mult, SIGNAL(clicked()), this, SLOT(button_clicked()));

    div = Colored_Button("/", QColor(Qt::gray));
    connect(div, SIGNAL(clicked()), this, SLOT(button_clicked()));


    DEL = Colored_Button("DEL", QColor(Qt::darkCyan));
    connect(DEL, SIGNAL(clicked()), this, SLOT(DEL_clicked()));

    AC = Colored_Button("AC", QColor(Qt::darkCyan));
    connect(AC, SIGNAL(clicked()), this, SLOT(AC_clicked()));

    calc = Colored_Button("=", QColor(Qt::gray));
    connect(calc, SIGNAL(clicked()), this, SLOT(calc_clicked()));


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



/*--------------- Funktionen ---------------*/

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


void Widget::button_clicked(){
    int pos = Eingabetext->cursorPosition();
    QString a = Eingabetext->text();
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString str = button->text();
    a.insert(pos, str);
    Eingabetext->setText(a);

    if(Eingabetext->text().at(pos) == 's') { pos+=4; }
    if(Eingabetext->text().at(pos) == '^') { pos+=1; }

    Eingabetext->setCursorPosition(pos+1);
}


void Widget::DEL_clicked(){
    Eingabetext->backspace();
}


void Widget::AC_clicked(){
    Eingabetext->setText("");
}


void Widget::calc_clicked(){
    string eingabe = Eingabetext->text().toStdString();
    if(Str_Korrekt(Aufteilen(eingabe))){
        double ergebnis = Rechenfunktion(eingabe);
        Ans->setText(QString::number(ergebnis));
    }
    else{ Ans->setText("ERROR"); }
}


bool Str_Korrekt(vector<Zeichen> V) {
    bool Error = false;
    int16_t Klammern = 0;
    bool Zahl = false;

    for (auto i = 1; i < (V.size() - 1); i++) {           //Klammer Check
        if (V.at(i).Operand == '(') { Klammern++; }
        if (V.at(i).Operand == ')') { Klammern--; }
        if (Klammern < 0) { Error = true; }

//Zeichen Check
        if ((V.at(i).Operand == '(')|| (V.at(i).Operand == ')')|| (V.at(i).Operand == '+')|| (V.at(i).Operand == '*')|| (V.at(i).Operand == '/')|| (V.at(i).Operand == '-')|| (V.at(i).Operand == 's')|| (V.at(i).Operand == '^')|| (V.at(i).Operand == '#')){ }
        else{ Error = true; }

//Auf min 1 zahl überprüfen
        if (V.at(i).Art == "Zahl") { Zahl = true; }
    }

    if (Klammern != 0) { Error = true; }
    if (Zahl == false) { Error = true; }

    return !Error;
}


double Rechenfunktion(string S) {
    return(Rechnen(Aufteilen(S)));
}

vector<Zeichen> Aufteilen(string str) {

    string s = "";
    for (uint64_t i = 0; i < str.size(); i++) {

        if ((str.at(i) == 's') && (str.at(i + 1) == 'q') && (str.at(i + 2) == 'r') && (str.at(i + 3) == 't') && (str.at(i + 4) == '(')) {
            s.push_back('s');
            s.push_back('(');
            i += 4;
        }
        else if(str.at(i) == ','){ s.push_back('.'); }
        else { s.push_back(str.at(i)); }
    }

    s = '(' + s + ')';


    //Temp Variablen
    bool letzteZahl = false;
    string TmpZahl = "";
    double TmpDouble = 0;
    Zeichen TmpZeichen;

    string Operatoren = "+-/^(*)s";


    vector <Zeichen> Zerteilt;

    //Durch String iterieren

    for (uint64_t i = 0; i < s.size(); i++) {

        //Zahlen erkennen
        if (((s.at(i) >= '0') && (s.at(i) <= '9')) || (s.at(i) == '.')) {
            letzteZahl = true;

            if (letzteZahl == true) {
                TmpZahl.push_back(s.at(i));
            }
            else {
                TmpZahl = s.at(i);
            }

        }
        //keine Zahl mehr
        else if ((letzteZahl == true)) {
            letzteZahl = false;
            TmpDouble = stod(TmpZahl, NULL);

            TmpZeichen.Art = "Zahl";
            TmpZeichen.Operand = '#';
            TmpZeichen.Zahl = TmpDouble;
            Zerteilt.push_back(TmpZeichen);

            TmpZahl = "";
            TmpDouble = 0;
            TmpZeichen.Art = "";
            TmpZeichen.Zahl = 0;
            TmpZeichen.Operand = '#';
        }

        //Letztes Element eine Zahl
        if ((((s.at(i) >= '0') && (s.at(i) <= '9')) || (s.at(i) == '.')) && (i == s.size() - 1)) {
            letzteZahl = false;
            TmpDouble = stod(TmpZahl, NULL);

            TmpZeichen.Art = "Zahl";
            TmpZeichen.Operand = '#';
            TmpZeichen.Zahl = TmpDouble;
            Zerteilt.push_back(TmpZeichen);

            TmpZahl = "";
            TmpDouble = 0;
            TmpZeichen.Art = "";
            TmpZeichen.Zahl = 0;
            TmpZeichen.Operand = '#';


        }



        //Operator erkennen
        if ((Operatoren.find(s.at(i))) != string::npos) {
            TmpZeichen.Art = "Operator";
            TmpZeichen.Operand = s.at(i);
            TmpZeichen.Zahl = 0;

            Zerteilt.push_back(TmpZeichen);

            TmpZahl = "";
            TmpDouble = 0;
            TmpZeichen.Art = "";
            TmpZeichen.Zahl = 0;
            TmpZeichen.Operand = '#';

        }
    }

    return Zerteilt;
}




double Rechnen(vector<Zeichen> V) {
    vector<Zeichen> vect = V;
    vector<Zeichen> helpvect;

    Zeichen TmpZeichen;
    double ZwischenErg = 0;

    bool eins;
    int16_t KVorne;
    int16_t KHinten;
    bool Rechnung = false;


    while (vect.size() >1) {


        //Wurzel berechnen
        Rechnung = false;
        for (auto i = 0; i < vect.size()-1; i++) {

            if ((vect.at(i).Operand == 's') && (vect.at(i + 1).Art == "Zahl")) {
                Rechnung = true;
                TmpZeichen.Art = "Zahl";
                TmpZeichen.Operand = '#';
                TmpZeichen.Zahl = sqrt(vect.at(i + 1).Zahl);
                helpvect.push_back(TmpZeichen);

                TmpZeichen.Art = "";
                TmpZeichen.Zahl = 0;
                TmpZeichen.Operand = '#';

                i++;

            }
            else {
                helpvect.push_back(vect.at(i));
            }

        }

        helpvect.push_back(vect.back());
        if (Rechnung) {
            vect = helpvect;
            Rechnung = false;
        }
        helpvect.clear();




        //Potenz berechnen
        for (auto i = 0; i < vect.size()-1; i++) {
            if ((vect.at(i + 1).Operand == '^')) {
                if ((vect.at(i).Art == "Zahl") && (vect.at(i + 1).Operand == '^') && (vect.at(i + 2).Art == "Zahl")) {
                    Rechnung = true;
                    TmpZeichen.Art = "Zahl";
                    TmpZeichen.Operand = '#';
                    TmpZeichen.Zahl = pow(vect.at(i).Zahl, vect.at(i + 2).Zahl);
                    helpvect.push_back(TmpZeichen);

                    ZwischenErg = 0;
                    TmpZeichen.Art = "";
                    TmpZeichen.Zahl = 0;
                    TmpZeichen.Operand = '#';

                    i += 2;

                }
                else {
                    helpvect.push_back(vect.at(i));
                }
            }
            else {
                helpvect.push_back(vect.at(i));
            }
        }
        helpvect.push_back(vect.back());
        if (Rechnung) {
            vect = helpvect;
            Rechnung = false;
        }
        helpvect.clear();





        //klammern suchen
        eins = true;
        for (auto hinten = 0; (hinten < vect.size()); hinten++) {
            if (vect.at(hinten).Operand == ')') {

                for (auto vorne = hinten; eins == true; vorne--) {

                    if (vect.at(vorne).Operand == '(') {
                        eins = false;
                        KVorne = vorne;
                        KHinten = hinten;
                        break;

                    }
                }
            }

            if (eins == false) {
                break;
            }
        }




        //Vor Klammer
        for (auto i = 0; i < KVorne; i++) {
            helpvect.push_back(vect.at(i));
        }


        //Einzelne zahl in klammer
        if ((KHinten - KVorne) == 2) {

            ZwischenErg = vect.at(KVorne + 1).Zahl;
            TmpZeichen.Art = "Zahl";
            TmpZeichen.Operand = '#';
            TmpZeichen.Zahl = ZwischenErg;
            helpvect.push_back(TmpZeichen);

            ZwischenErg = 0;
            TmpZeichen.Art = "";
            TmpZeichen.Zahl = 0;
            TmpZeichen.Operand = '#';

        }

        if ((KHinten - KVorne) > 2) {
            ZwischenErg = vect.at(KVorne + 1).Zahl;

            for (auto i = KVorne+1; i < KHinten-2; i++) {

                switch (vect.at(i+1).Operand) {

                case '+': ZwischenErg = ZwischenErg + vect.at(i + 2).Zahl; break;
                case '-': ZwischenErg = ZwischenErg - vect.at(i + 2).Zahl; break;
                case '*': ZwischenErg = ZwischenErg * vect.at(i + 2).Zahl; break;
                case '/': ZwischenErg = ZwischenErg / vect.at(i + 2).Zahl; break;
                }

            }


            TmpZeichen.Art = "Zahl";
            TmpZeichen.Operand = '#';
            TmpZeichen.Zahl = ZwischenErg;
            helpvect.push_back(TmpZeichen);

            ZwischenErg = 0;
            TmpZeichen.Art = "";
            TmpZeichen.Zahl = 0;
            TmpZeichen.Operand = '#';


        }


        //nach Klammer

        for (auto i = (KHinten + 1); i < vect.size(); i++) {
            helpvect.push_back(vect.at(i));
        }

        vect = helpvect;
        helpvect.clear();


    }

    return vect.at(0).Zahl;
}


bool Klammern(vector<Zeichen> V) {
    bool out = false;
    for (auto i = 0; i < V.size(); i++) {
        if (V.at(i).Operand == ')') {
            out = true;
            break;
        }
    }
    return out;
}


bool Wurzel(vector<Zeichen> V) {
    bool out = false;
    for (auto i = 0; i < V.size(); i++) {
        if (V.at(i).Operand == 's') {
            out = true;
            break;
        }
    }
    return out;
}

