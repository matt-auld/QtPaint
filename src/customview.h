#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QGraphicsView>

class MainWindow;

class customView : public QGraphicsView
{
    Q_OBJECT

public:
    customView(QGraphicsScene*, QWidget*);
    MainWindow *parent;
protected:
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void setCursorType(int);
};

#endif // CUSTOMVIEW_H
