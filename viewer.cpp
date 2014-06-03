#include "viewer.h"
#include "ui_viewer.h"
class Root;

Viewer::Viewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Viewer)
{
    ui->setupUi(this);

}

Viewer::~Viewer()
{
    delete ui;
}

Viewport* Viewer::getViewport(){
    return this->ui->viewport;
}
