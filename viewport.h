#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGLWidget>
#include "ast.h"

class Viewport : public QGLWidget
{
    Q_OBJECT
public:
    explicit Viewport(QWidget *parent = 0);
    ~Viewport();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    bool drawAxes;
    Color* backgroundColor;

signals:

public slots:

};

#endif // VIEWPORT_H
