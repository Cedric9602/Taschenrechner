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
                QLabel *text;
                QPushButton *Ans;

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

    public slots:

        void zahl0_clicked();
        void zahl1_clicked();
        void zahl2_clicked();
        void zahl3_clicked();
        void zahl4_clicked();
        void zahl5_clicked();
        void zahl6_clicked();
        void zahl7_clicked();
        void zahl8_clicked();
        void zahl9_clicked();

        void k_auf_clicked();
        void k_zu_clicked();
        void wurzel_clicked();
        void potenz_clicked();
        void komma_clicked();
        void add_clicked();
        void sub_clicked();
        void mult_clicked();
        void div_clicked();

        void DEL_clicked();
        void AC_clicked();
};

#endif // WIDGET_H
