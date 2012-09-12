#ifndef CANVASITEM_H
#define CANVASITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QImage>
#include <QWidget>

#include "mainwindow.h"
#include "canvasItem.h"

#define NONE -1

#define CENTER 0
#define RIGHT 1
#define LEFT 2
#define BOTTOM 3
#define TOP 4

#define CENTER_DRAG 5
#define RIGHT_DRAG 6
#define LEFT_DRAG 7
#define BOTTOM_DRAG 8
#define TOP_DRAG 9

class canvasItem : public QGraphicsItem
{
public:
    enum { Type = UserType + 1 };
    // Enable the use of qgraphicsitem_cast with this item.
    int type() const
    {
           return Type;
    }
    canvasItem();
    canvasItem(char*);
    canvasItem(QString&, MainWindow*);
    canvasItem(int, int, QColor&, int, int, MainWindow*);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool pressed, selected;
    int firstKey, secondKey; // Needed for multple key presses e.g ctrl+arrow
    int dragDistance;
    int maxZVal, prevZVal;
    int posCursor, dragType;
    QImage *image;
    MainWindow* parent;

    void gradientFill(const QColor&, const QColor&);
    void fill(const QColor&);
    void greyscale();
    void resizeBilinear(int newWidth, int newHeight);
    void horizontalBlur();
    void contrastExtreme();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // CANVASITEM_H
