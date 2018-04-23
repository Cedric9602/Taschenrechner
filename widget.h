#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ui_widget.h"
#include<QPushButton>
#include<QTextEdit>
#include<QLineEdit>
#include<QLabel>
#include<QGridLayout>

QPushButton *Colored_Button(QString text, QColor color);


namespace Ui {
class Widget;
}

class Widget : public QWidget{

    Q_OBJECT

    private:    QLineEdit *Eingabetext;
                QLabel *Ausgabe;

                QGridLayout *layout;

                QPushButton *zahl0;
                QPushButton *zahl1;
                QPushButton *zahl2;
                QPushButton *zahl3;
                QPushButton *zahl4;
                QPushButton *zahl5;
                QPushButton *zahl6;
                QPushButton *zahl7;
                QPushButton *zahl8;
                QPushButton *zahl9;

                QPushButton *DEL;
                QPushButton *AC;
                QPushButton *k_auf;
                QPushButton *k_zu;
                QPushButton *wurzel;
                QPushButton *potenz;
                QPushButton *komma;
                QPushButton *add;
                QPushButton *sub;
                QPushButton *mult;
                QPushButton *div;
                QPushButton *calc;

                Ui::Widget *ui;

    public:     Widget();
                ~Widget();
};

#endif // WIDGET_H
