#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include "glwidget.h"
#include "cursor.h"
#include "canvas.h"

GLWidget* gGLWidget;


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent), mLeftMousePressed(false), mRightMousePressed(false),
    mScreenWidth(1), mScreenHeight(1)
{
    gGLWidget = this;
    setMouseTracking(true);
    setEnabled(true);
    setFocusPolicy(Qt::StrongFocus);
}


void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0,0,0,1);
    mMainShader.load("shaders/main.vert", "shaders/main.frag");
    initialiseQuad();

    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);

    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    mCanvas = std::auto_ptr<Canvas>(new Canvas());
    mCursor = std::auto_ptr<Cursor>(new Cursor());

}


void GLWidget::beginDraw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    mMainShader.set();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), NULL);
}

void GLWidget::drawWithState()
{
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void GLWidget::endDraw()
{
    int error = glGetError();
    std::ostringstream stream;
    stream << error;
    if(error!=0)
        Error(stream.str());
}

void GLWidget::paintGL()
{
    beginDraw();
    mCanvas->draw();
    mCursor->draw(mCanvas->mCamera.matrix());

    gGLWidget->endDraw();
}

void GLWidget::resizeGL(int w, int h)
{
    mScreenWidth = w;
    mScreenHeight = h;
    mCanvas->resizeViewport(w,h);
    glViewport(0,0,w,h);
}


void GLWidget::initialiseQuad()
{
    mQuad.quad[0] = Vertex2D(-1.f, -1.f, 0.f, 0.f);
    mQuad.quad[1] = Vertex2D(1.f, -1.f, 1.f, 0.f);
    mQuad.quad[2] = Vertex2D(-1.f, 1.f, 0.f, 1.f);
    mQuad.quad[3] = Vertex2D(-1.f, 1.f, 0.f, 1.f),
    mQuad.quad[4] = Vertex2D(1.f, -1.f, 1.f, 0.f);
    mQuad.quad[5] = Vertex2D(1.f, 1.f, 1.f, 1.f);
    mQuad.VBO = ~0u;

    glGenBuffers(1, &mQuad.VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mQuad.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex2D) * 6, mQuad.quad, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), NULL);
}

void GLWidget::mousePressEvent(QMouseEvent * event)
{
    event->accept();
    switch(event->button())
    {
    case Qt::LeftButton:
    {
        mLeftMousePressed = true;
    } break;

    case Qt::RightButton:
    {
        mRightMousePressed = true;
    } break;
    default:
        break;
    }
}


void GLWidget::mouseReleaseEvent(QMouseEvent * event)
{
    event->accept();
    switch(event->button())
    {
    case Qt::LeftButton:
    {
        mLeftMousePressed = false;
    } break;

    case Qt::RightButton:
    {
       mRightMousePressed = false;
    } break;
    default:
        break;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent * event)
{
    event->accept();
    math::vec2i position = math::vec2i(event->x(), event->y());
    math::vec2 delta = math::vec2(position.x, position.y)-
            math::vec2(mLastMousePosition.x,mLastMousePosition.y);

    //This is not wrong. The second part accounts for aspect ratio ^.^
    delta/=mScreenWidth/2.f;

    if(mRightMousePressed) //panning has priority.
    {
        mCanvas->pan(delta.x, delta.y);
    }
    else if (mLeftMousePressed)
    {
        mCanvas->applyBrush(mCursor->globalPos());
    }

    mLastMousePosition = math::vec2i(event->x(), event->y());
    mNormalisedMousePosition = math::vec2(((float)mLastMousePosition.x/mScreenWidth-0.5f)*2,
                                          ((float)mLastMousePosition.y/mScreenHeight-0.5f)*-2);
    mCursor->globalPos(mNormalisedMousePosition, mCanvas->mCamera.matrix());

    update();

}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    event->accept();
    Inform("Key pressed.");
    update();
}

void GLWidget::wheelEvent(QWheelEvent * event)
{
    event->accept();
    mCanvas->zoom(event->delta()/2000.f);
    update();
}
