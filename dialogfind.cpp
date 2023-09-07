#include "dialogfind.h"
#include "ui_dialogfind.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include <iostream>

#include <QCloseEvent>

DialogFind::DialogFind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFind)

{
    ui->setupUi(this);
    setWindowTitle("Find");

    ui->labelNoMatch->setVisible(false);
    ui->labelNoMatch->setText("<font color='red'>Nessuna occorrenza trovata</font>");


}

DialogFind::~DialogFind()
{
    delete ui;


}

/*
 * Trigger sul bottone Close della dialog.
 * Quando viene cliccato, la dialog viene chiusa e
 * il testo selezionato in rosso dalla find ritorna
 * di colore nero
 *
 * */
void DialogFind::on_btnClose_clicked()
{

    text->setTextColor(Qt::black);  //Viene settato il colore della textEdit a nero grazie al puntatore text
    text->setText(text->toPlainText()); //Viene settato il testo della textEdit grazie al puntatore text
    //  text->setReadOnly(false);

    this->close();  //Viene chiusa la dialog find
}

/*
 * Trigger sul bottone Find della dialog, che permette
 * la ricerca di una stringa all'interno del testo.
 * Inoltre è possibile effettuare una ricerca case Sesitive
 * tramite la spunta della checkBox Match case.
 * Se la stringa non viene trovata viene visualizzato un messaggio
 * di colore rosso: "Nessuna occorrenza trovata"
 *
 * */
void DialogFind::on_btnFind_clicked()
{

    bool colorato = false;

    ui->labelNoMatch->setVisible(false);    //Imposto a non visibile il messaggio "Nessuna occorrenza trovata"


    QString searchString = ui->textEditFind->toPlainText(); //Stringa da cercare nel testo
    QTextDocument *document = text->document(); //Testo in cui si vuole cercare la stringa

    bool found = false; //Booleano che diventa true se viene trovata la stringa
    if(colorato){

        document->undo();
        colorato = false;
    }

    if (searchString.isEmpty()) {   //Se il campo per la ricerca della stringa è vuoto e si clicca su find, viene visualizzato un messaggio
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {    //Inizio la ricerca della stringa inserita dall'utente
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red); //Colore con cui evidezio le Stringhe trovate



        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {

            if(ui->checkBoxMatch->isChecked())  //Se è spuntata la checkBox Match case: viene effettuato un controllo di tipo caseSensitive
            {
                highlightCursor = document->find(searchString, highlightCursor,QTextDocument::FindCaseSensitively);

            }
            else    //Altrimenti: viene eseguito un controllo NON case sensitive
            {

                highlightCursor = document->find(searchString, highlightCursor,
                                                 QTextDocument::FindWholeWords);
            }



            if (!highlightCursor.isNull()) {
                found = true;
                colorato = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();

        if (found == false) {   //Se la Stringa non viene trovata, rendo visibile il messaggio "Nessuna occorrenza trovata"

            ui->labelNoMatch->setVisible(true);

        }


    }



}

/*
 * Funzione che mi restituisce il testo inserito nella
 * textEdit della dialog (Stringa che l'utente vuole cercare)
 *
 * */
QString DialogFind::getCerca()
{
    return ui->textEditFind->toPlainText();
}

/*
 * Funzione che mi permette di ottenere il puntatore della
 * textEdit del MainWindow
 *
 * */
void DialogFind::sendPointer(QTextEdit *txt)
{
    text = txt;

}

/*
 * Funzione che mi restituisce true se la checkbox Match case
 * è spuntata.
 * False altrimenti.
 *
 * */
bool DialogFind::isChecked()
{
    return ui->checkBoxMatch->isChecked();
}

/*
 * Funzione che mi permette di colorare il testo della textEdit (del file aperto)
 * di nero, una volta che la dialog viene chiusa tramite la X (croce in alto a destra della finestra)
 *
 * */
void DialogFind::reject()
{
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;

    text->setTextColor(Qt::black);
    text->setText(text->toPlainText());
    text->setReadOnly(false);



    if (resBtn == QMessageBox::Yes) {
        QDialog::reject();
    }

}


