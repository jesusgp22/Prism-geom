#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <viewport.h>
class Root;
namespace Ui {
class Viewer;
}

class Viewer : public QWidget
{
    Q_OBJECT
    
public:
    explicit Viewer(QWidget *parent = 0);
    ~Viewer();
    Viewport* getViewport();
    
private:
    Ui::Viewer *ui;
};

#endif // VIEWER_H
