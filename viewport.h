#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGLWidget>
#include <QString>
#include <QHash>

class ITransform;
class Color;
class Renderer;
class Root;
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

    void addRenderer(QString id, Renderer* renderer);
    void setBackgroundColor(Color* c);
    void addDraw(QString id,Color* c);
    void addFill(QString id,Color* c);
    void addTransform(QString id,ITransform* t);

    bool drawAxes;
    bool is2d;
    Color* backgroundColor;
    QHash<QString,Renderer*> renderers;

signals:

public slots:

};

#endif // VIEWPORT_H
