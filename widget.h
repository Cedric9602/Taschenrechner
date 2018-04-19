#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ui_widget.h"
#include<QPushButton>
#include<QTextEdit>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget{

    Q_OBJECT

    private:    QVBoxLayout *vbox;
                QLineEdit *ledit;
                QLabel *text;
                QPushButton *neuerknopf;
                Ui::Widget *ui;

    public:     Widget();
                ~Widget();
};

#endif // WIDGET_H
