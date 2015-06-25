#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <memory>
#include "mainshader.h"
#include "vertex.h"
//#include "canvas.h"

class Canvas;
class Cursor;
class QMouseEvent;
class QKeyEvent;
class QWheelEvent;

class GLWidget : public QGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

private:
    MainShader mMainShader;
    std::auto_ptr<Canvas> mCanvas;
    math::vec2i mLastMousePosition;
    math::vec2 mNormalisedMousePosition;
    std::auto_ptr<Cursor> mCursor;
    int mScreenWidth, mScreenHeight;
    bool mLeftMousePressed, mRightMousePressed;
public:
    explicit GLWidget(QWidget *parent = 0);


    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    struct
    {
        Vertex2D quad[6];
        GLuint VBO;
    } mQuad;


    void initialiseQuad();

    void beginDraw();
    void drawWithState();
    void endDraw();

    virtual void mousePressEvent(QMouseEvent * event) override;
    virtual void mouseReleaseEvent(QMouseEvent * event) override;
    virtual void mouseMoveEvent(QMouseEvent * event) override;

    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void wheelEvent(QWheelEvent * event) override;

    MainShader& shader() {return mMainShader;}
signals:

public slots:

};

extern GLWidget* gGLWidget;

#endif // GLWIDGET_H
