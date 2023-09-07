#include "mainwindow.h"
#include "ui_mainwindow.h"



//Per la open
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

//Per mandare il messaggio di errore a schermo(es: file non aperto)
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setCentralWidget(ui->textEdit);   //Per centrare la text per scrivere nella finestra



}

MainWindow::~MainWindow()
{
    delete ui;

}


/*
 * Trigger che sul bottone new. Viene creato un nuovo documento
 * di testo
 *
 * */
void MainWindow::on_actionNew_triggered()
{

    setWindowTitle("Nuovo Documento di testo"); //Viene settato il titolo della window
    filePath = "";  //Inizializzo il filePath
    ui->textEdit->setText("");  //Imposto la textEdit senza testo (textEdit vuota)
}

/*
 * Trigger sul bottone open. Permette di aprire un nuovo documento di testo
 *
 * */
void MainWindow::on_actionOpen_triggered()
{
    QString nomeFile = QFileDialog::getOpenFileName(this,"Apri");   //File che devo aprire
    QFile file(nomeFile);   //creo un nuovo file
    filePath = nomeFile;    //path del file

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        //  QMessageBox::warning(this,"Errore: ","File non aperto");
        return;
    }

    setWindowTitle(nomeFile);   //Setto il nome della window
    QTextStream in(&file);
    QString text = in.readAll();    //In text metto lo stream del file
    ui->textEdit->setText(text);    //metto il testo nella text edit per visualizzarlo
    file.close();   //chiudo il file

}

/*
 * Trigger sul bottone Save, che mi permette di salvare un file aperto oppure
 * che mi permette di salvare un file già salvato con nome.
 *
 * */
void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);   //creo il file
    if(!file.open(QFile::WriteOnly | QFile::Text))  //if che mi restituisce un errore se cerco di salvare un file non salvato con nome o non aperto
    {
        QMessageBox::warning(this,"Errore: ","Aprire un file oppure Salvare il file con nome");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText(); //ottengo il testo dalla text edit
    out << text;
    //  file.flush();
    file.close();   //chiudo il file



}

/*
 * Trigger sul bottone Save_as, che mi permette di
 * salvare con nome un file.
 *
 * */
void MainWindow::on_actionSave_as_triggered()
{
    QString nomeFile = QFileDialog::getSaveFileName(this,"Salva");
    QFile file(nomeFile);   //creo il file
    filePath = nomeFile;    //setto il filePath

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        //   QMessageBox::warning(this,"Errore: ","File non aperto/File non salvato");
        return;
    }

    setWindowTitle(nomeFile);   //imposto il nome della window con il nome del file/path
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText(); //ottengo il testo dalla textEdit
    out << text;
    //   file.flush();
    file.close();   //chiudo il file



}

/*
 * Trigger sul bottone Cut, che mi permette di tagliare
 * il testo selezionato
 *
 * */
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

/*
 * Triggger sul bottone Copy, che mi permette di copiare
 * il testo selezionato
 *
 * */
void MainWindow::on_actionCopy_triggered()
{
    //Quando il bottone viene premuto viene fatta una chiamata ad una funzione che esegue l'operazione, in questo caso la copia
    ui->textEdit->copy();
}

/*
 * Trigger sul bottone Paste, che mi permette di incollare
 * il testo selezionato
 *
 * */
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

/*
 * Trigger sul bottone Redo, che mi permette di
 *
 * */
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

/*
 * Trigger sul bottone Undo, che mi permette di
 *
 * */
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

/*
 * Trigger sul bottone Find, che mi permette di
 * effettuare la ricerca di una parola
 *
 * */
void MainWindow::on_actionFind_triggered()
{
    //  ui->textEdit->setReadOnly(true);

    DialogFind *dialog = new DialogFind;    //Inizializzo la dialog

    dialog->show(); //Visualizzo la dialog

    dialog->sendPointer(ui->textEdit);  //Invio il puntatore della textEdit alla dialog per permettere la ricerca della parlona nel testo

}


/*
 * Funzione che mi permette di effettuare una
 * get sulla textEdit.
 *
 * */
QString MainWindow::getText1()
{
    return ui->textEdit->toPlainText(); //Restituisco il testo della textEdit
}


/*
 * Funzione che viene eseguita al cambio del testo.
 *
 * */
void MainWindow::on_textEdit_textChanged()
{
    ui->textEdit->setTextColor(Qt::black);  //Viene settato il colore del testo a nero

}



