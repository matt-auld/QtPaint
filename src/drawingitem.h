#ifndef DRAWINGITEM_H
#define DRAWINGITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QList>
#include <QPoint>

class drawingItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    drawingItem(int width, int height);
private:
    bool pressed;
    int toolType;
    QPointF pointStart;
    QImage *drawingLayer;
    QRectF boundingRect() const;

    QPainter *layer;
    QPen *pen;
    QList<QPointF> pixelList;
    QList<QPointF> pathlList;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void toolTypeUpdate(int);
    void setAnti(bool);
};

#endif // DRAWINGITEM_H
