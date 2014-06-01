#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<stdio.h>
#include<QDebug>
#include<iostream>
#include"ast.h"

    extern int yyparse();
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    extern int line;
    extern int errors;
    extern QString tokens;
    extern QString syntax;
    extern Root* root;
    extern QHash<QString, Identifier*> symbols;
    extern void reestart();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNuevo_triggered()
{
    mArchivo = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionAbrir_triggered()
{
    QString archivo = QFileDialog ::getOpenFileName(this,"Abrir un Archivo");

    if(!archivo.isEmpty())
    {
        QFile sArchivo(archivo);
        if(sArchivo.open(QFile::ReadOnly | QFile::Text))
        {
            mArchivo = archivo;
            QTextStream in(&sArchivo);
            QString text = in.readAll();
            sArchivo.close();
            ui->textEdit->setPlainText(text);
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    symbols.clear();
    this->ui->tableWidget->setRowCount(0);
    ui->consola->append("Comenzando analisis...");
    on_actionGuardar_triggered();
    reestart();
    yyin = fopen(mArchivo.toLocal8Bit().data(), "r" );
    line = 0;
    do
    {
        yyparse();
    }
    while (!feof(yyin));

    ui->consola->append("TOKEN,LEXEMA");
    ui->consola->append(tokens);
    ui->consola->append(syntax);
    tokens.clear();
    syntax.clear();



    if(errors==0){
        QHash<QString, Identifier*>::const_iterator i = symbols.constBegin();
        int row = 0;
        while (i != symbols.constEnd()) {
            this->ui->tableWidget->insertRow(row);
            this->ui->tableWidget->setItem(row,0,new QTableWidgetItem(i.key()));
            QString type = i.value()->dimension_string();
            type += i.value()->type_string();
            this->ui->tableWidget->setItem(row,1,new QTableWidgetItem(type));
            QString value = i.value()->value->getValueString();
            this->ui->tableWidget->setItem(row,2,new QTableWidgetItem(value));
            if(!i.value()->referenced){

                // save old color
                int fw = ui->consola->fontWeight();
                QColor tc = ui->consola->textColor();

                // append
                ui->consola->setFontWeight( QFont::DemiBold );
                ui->consola->setTextColor( QColor( "yellow" ) );
                this->ui->consola->append("Advertencia: Variable \"" + i.value()->name + "\" declarada pero nunca se usa");

                // restore old color
                ui->consola->setFontWeight( fw );
                ui->consola->setTextColor( tc );
            }
            //cout << i.key() << ": " << i.value()-> << endl;
            ++i;
            ++row;
        }

        viewer = new Viewer();
        viewport = viewer->getViewport();

        for(int i=0;i<root->sentence_list->size();i++){
            root->sentence_list->at(i)->GenerateCode(viewport);
        }

        viewer->show();
    }else{

        QString m = "Analisis finalizo con ";
        m+=QString::number(errors);
        m+=" error(es)";

        // save old color
        int fw = ui->consola->fontWeight();
        QColor tc = ui->consola->textColor();

        // append
        ui->consola->setFontWeight( QFont::DemiBold );
        ui->consola->setTextColor( QColor( "red" ) );
        ui->consola->append(m);

        // restore old color
        ui->consola->setFontWeight( fw );
        ui->consola->setTextColor( tc );


    }
    errors = 0;

}



void MainWindow::on_actionGuardar_triggered()
{
    if(mArchivo == ""){
        on_actionGuardar_Como_triggered();
    }
    else{
        QFile sArchivo(mArchivo);
        if(sArchivo.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream salida(&sArchivo);
            salida << ui->textEdit->toPlainText();
            sArchivo.flush();
            sArchivo.close();
        }
    }
}

void MainWindow::on_actionCerrar_triggered()
{
    close();
}

void MainWindow::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCortar_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPegar_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionGuardar_Como_triggered()
{
    QString archivo = QFileDialog ::getSaveFileName(this,"Guardar el Archivo");

    if(!archivo.isEmpty())
    {
        mArchivo = archivo;
        on_actionGuardar_triggered();

    }
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    int y = cursor.blockNumber() +1 ;
    int x = cursor.columnNumber() +1;
    QString text="Linea: "+QString::number(y)+", Col: "+QString::number(x);
    this->ui->positionLabel->setText(text);
}
