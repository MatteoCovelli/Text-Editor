#ifndef DIALOGFIND_H
#define DIALOGFIND_H

#include <QDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class DialogFind;
}

class DialogFind : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFind(QWidget *parent = nullptr);
    ~DialogFind();

    QString getCerca();
    void sendPointer(QTextEdit*);
    bool isChecked();
    void reject();


private slots:


    void on_btnClose_clicked();

    void on_btnFind_clicked();







private:
    Ui::DialogFind *ui;

    QTextEdit *text;

};

#endif // DIALOGFIND_H
