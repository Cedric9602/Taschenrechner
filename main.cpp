#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}


/*
 // Basic.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

struct Zeichen {
    string Art;
    double Zahl;
    char Operand;
};

vector<Zeichen> Aufteilen(string S);
double Rechnen(vector<Zeichen> V);
bool Klammern(vector<Zeichen> V);
bool Wurzel(vector<Zeichen> V);

double Rechenfunktion(string S);


int main()
{

    //string test = "((((sqrt(5*5)))))";
    //cout << test << endl;

    //double t = stod(test, NULL);
    //auto check = Aufteilen(test);

    //double ende = Rechnen(check);

    cout << Rechenfunktion("(2+3)*(5+(4*sqrt(4*4)))+100") << endl;

    system("pause");
    return 0;
}

double Rechenfunktion(string S) {
    return(Rechnen(Aufteilen(S)));
}




vector<Zeichen> Aufteilen(string str) {

    string s = "";
    for (int64_t i = 0; i < str.size(); i++) {

        if ((str.at(i) == 's') && (str.at(i + 1) == 'q') && (str.at(i + 2) == 'r') && (str.at(i + 3) == 't') && (str.at(i + 4) == '(')) {

            s.push_back('s');
            s.push_back('(');
            i += 4;

        }
        else {
            s.push_back(str.at(i));
            }

    }




    //Temp Variablen
    bool letzteZahl = false;
    string TmpZahl = "";
    double TmpDouble = 0;
    Zeichen TmpZeichen;

    string Operatoren = "+-/^(*)s";


    vector <Zeichen> Zerteilt;

    //Durch String iterieren

    for (int64_t i = 0; i < s.size(); i++) {

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
        if ((Operatoren.find(s.at(i)))!=string::npos)  {
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
    double Erg;

    bool eins;
    int16_t KVorne = -1;
    int16_t KHinten = -1;



    while (Klammern(vect)) {
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


        for (auto i = 0; i < vect.size(); i++) {

            if ((vect.at(i).Operand == 's') && (vect.at(i + 1).Operand != '(')) {

                TmpZeichen.Art = "Zahl";
                TmpZeichen.Operand = '#';
                TmpZeichen.Zahl = sqrt(vect.at(i + 1).Zahl);
                helpvect.push_back(TmpZeichen);

                ZwischenErg = 0;
                TmpZeichen.Art = "";
                TmpZeichen.Zahl = 0;
                TmpZeichen.Operand = '#';
                helpvect.push_back(vect.at(i+1));
                i++;

            }
            else {
                helpvect.push_back(vect.at(i));
            }

        }
        vect = helpvect;
        helpvect.clear();






        for (auto i = 0; i < KVorne; i++) {
            helpvect.push_back(vect.at(i));
        }



        ZwischenErg = vect.at(KVorne + 1).Zahl;

        for (auto i = KVorne + 2; i < KHinten - 1; i += 2) {

            if (vect.at(i).Operand == 's') {

            }
            else {
                switch (vect.at(i).Operand) {

                case '+': ZwischenErg = ZwischenErg + vect.at(i + 1).Zahl; break;
                case '-': ZwischenErg = ZwischenErg - vect.at(i + 1).Zahl; break;
                case '*': ZwischenErg = ZwischenErg * vect.at(i + 1).Zahl; break;
                case '/': ZwischenErg = ZwischenErg / vect.at(i + 1).Zahl; break;
                case '^': ZwischenErg = pow(ZwischenErg, vect.at(i + 1).Zahl); break;
                }
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



        for (auto i = (KHinten + 1); i < vect.size(); i++) {
            helpvect.push_back(vect.at(i));
        }

        vect = helpvect;
        helpvect.clear();


    }

    if (!Klammern(vect)) {
        bool über = false;
        while (Wurzel(vect)) {
            for (auto i = 0; i < vect.size(); i++) {
                if (vect.at(i).Operand == 's') {

                    TmpZeichen.Art = "Zahl";
                    TmpZeichen.Operand = '#';
                    TmpZeichen.Zahl = sqrt(vect.at(i + 1).Zahl);
                    helpvect.push_back(TmpZeichen);

                    ZwischenErg = 0;
                    TmpZeichen.Art = "";
                    TmpZeichen.Zahl = 0;
                    TmpZeichen.Operand = '#';
                    über = true;
                    }

                else {
                    helpvect.push_back(vect.at(i));
                }

                if (über == true) {
                    über = false;
                    i++;
                }

            }
            vect = helpvect;
            helpvect.clear();
        }


            ZwischenErg = vect.at(0).Zahl;

            for (auto i = 1; i < vect.size(); i += 2) {
                switch (vect.at(i).Operand) {

                case '+': ZwischenErg = ZwischenErg + vect.at(i + 1).Zahl; break;
                case '-': ZwischenErg = ZwischenErg - vect.at(i + 1).Zahl; break;
                case '*': ZwischenErg = ZwischenErg * vect.at(i + 1).Zahl; break;
                case '/': ZwischenErg = ZwischenErg / vect.at(i + 1).Zahl; break;
                case '^': ZwischenErg = pow(ZwischenErg, vect.at(i + 1).Zahl); break;
                }


            }
            Erg = ZwischenErg;
            ZwischenErg = 0;

            return Erg;
    }

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
 */
