#include "customview.h"
#include "mainwindow.h"

#include <iostream>
#include <QMouseEvent>

customView::customView(QGraphicsScene *scene, QWidget *p)
    : QGraphicsView(scene)
{
    parent = ((MainWindow*)p);
}

void customView::mouseMoveEvent(QMouseEvent *event)
{
    parent->statusBar()->showMessage(QString::number(event->pos().x()) + "," + QString::number(event->pos().y()));
    QGraphicsView::mouseMoveEvent(event);
}

void customView::setCursorType(int type)
{
    if (type == 0 || type == 2 || type == 4)
    {
        viewport()->setCursor(Qt::CrossCursor);
        parent->mainWidget->toolPanel;
    }
    else
    {
        viewport()->setCursor(Qt::ArrowCursor);
    }
}

