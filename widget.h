#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ui_widget.h"
#include<QPushButton>
#include<QTextEdit>
#include<QLineEdit>
#include<QLabel>
#include<QGridLayout>


namespace Ui {
class Widget;
}

class Widget : public QWidget{

    Q_OBJECT

    private:    QLineEdit *Eingabetext;
                QLabel *text1;

                QGridLayout *layout;

                QPushButton *zahl1;
                QPushButton *zahl2;
                QPushButton *zahl3;
                QPushButton *zahl4;
                QPushButton *zahl5;
                QPushButton *zahl6;
                QPushButton *zahl7;
                QPushButton *zahl8;
                QPushButton *zahl9;

                Ui::Widget *ui;

    public:     Widget();
                ~Widget();
};

#endif // WIDGET_H
