/********************************************************************************
** Form generated from reading UI file 'dialogfind.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFIND_H
#define UI_DIALOGFIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogFind
{
public:
    QGridLayout *gridLayout;
    QLabel *labelFind;
    QTextEdit *textEditFind;
    QPushButton *btnFind;
    QCheckBox *checkBoxMatch;
    QPushButton *btnClose;
    QLabel *labelNoMatch;

    void setupUi(QDialog *DialogFind)
    {
        if (DialogFind->objectName().isEmpty())
            DialogFind->setObjectName(QString::fromUtf8("DialogFind"));
        DialogFind->resize(490, 167);
        gridLayout = new QGridLayout(DialogFind);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelFind = new QLabel(DialogFind);
        labelFind->setObjectName(QString::fromUtf8("labelFind"));

        gridLayout->addWidget(labelFind, 0, 0, 1, 1);

        textEditFind = new QTextEdit(DialogFind);
        textEditFind->setObjectName(QString::fromUtf8("textEditFind"));
        QFont font;
        font.setPointSize(11);
        textEditFind->setFont(font);

        gridLayout->addWidget(textEditFind, 0, 1, 1, 1);

        btnFind = new QPushButton(DialogFind);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));

        gridLayout->addWidget(btnFind, 0, 2, 1, 1);

        checkBoxMatch = new QCheckBox(DialogFind);
        checkBoxMatch->setObjectName(QString::fromUtf8("checkBoxMatch"));

        gridLayout->addWidget(checkBoxMatch, 1, 0, 1, 2);

        btnClose = new QPushButton(DialogFind);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 1, 2, 1, 1);

        labelNoMatch = new QLabel(DialogFind);
        labelNoMatch->setObjectName(QString::fromUtf8("labelNoMatch"));

        gridLayout->addWidget(labelNoMatch, 2, 0, 1, 2);


        retranslateUi(DialogFind);

        QMetaObject::connectSlotsByName(DialogFind);
    } // setupUi

    void retranslateUi(QDialog *DialogFind)
    {
        DialogFind->setWindowTitle(QApplication::translate("DialogFind", "Dialog", nullptr));
        labelFind->setText(QApplication::translate("DialogFind", "Find what:", nullptr));
        btnFind->setText(QApplication::translate("DialogFind", "Find", nullptr));
        checkBoxMatch->setText(QApplication::translate("DialogFind", "Match case", nullptr));
        btnClose->setText(QApplication::translate("DialogFind", "Close", nullptr));
        labelNoMatch->setText(QApplication::translate("DialogFind", "testo errore", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFind: public Ui_DialogFind {};

} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFIND_H
