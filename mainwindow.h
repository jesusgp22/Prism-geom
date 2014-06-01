#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include "viewer.h"
#include "viewport.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Viewer* viewer;
    Viewport *viewport;

private slots:
    void on_pushButton_clicked();

    void on_actionNuevo_triggered();

    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_actionCerrar_triggered();

    void on_actionCopiar_triggered();

    void on_actionCortar_triggered();

    void on_actionPegar_triggered();

    void on_actionGuardar_Como_triggered();

    void on_textEdit_cursorPositionChanged();


private:
    Ui::MainWindow *ui;
    QString mArchivo;
};

#endif // MAINWINDOW_H
