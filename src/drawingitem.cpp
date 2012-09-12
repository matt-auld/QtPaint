#include "drawingitem.h"
#include <iostream>

drawingItem::drawingItem(int width, int height)
{
    drawingLayer = new QImage(600, 600, QImage::Format_ARGB6666_Premultiplied);
    drawingLayer->fill(QColor(255, 255, 255, 0));

    layer = new QPainter(drawingLayer);

    pen = new QPen();

    toolType = -1;
    pressed = false;

    setFlag(ItemIsSelectable);
    setFlag(ItemIsFocusable);

    setAcceptHoverEvents(true);
}

QRectF drawingItem::boundingRect() const
{
    return QRectF(0, 0, 600, 600);
}

void drawingItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QPainterPath path;

    if (pathlList.size() > 1)
    {
        pen->setColor(QColor(100, 19, 55));
        pen->setWidth(3);

        layer->setPen(*pen);
        path.moveTo(pathlList.first());

        for (int i = 1; i < pathlList.size(); ++i)
        {
            path.lineTo(pathlList.at(i));
        }

        layer->drawPath(path);
        painter->drawImage(rec, *drawingLayer);
        return;
    }

    if (pixelList.size() > 1)
    {
        layer->setPen(*pen);
        if (toolType == 0)
        {
            pen->setColor(QColor(0, 0, 0));
            pen->setWidth(1);
        }
        else if (toolType == 4)
        {
            pen->setColor(QColor(255, 19, 55));
            pen->setWidth(3);
        }
        else  if (toolType == 2)
        {
            pen->setColor(QColor(0, 0, 0, 1));
            pen->setWidth(4);
        }
        else
        {
            painter->drawImage(rec, *drawingLayer);
            return;
        }
        // Draw points in pixel list, as path
        path.moveTo(pixelList.first());

        for (int i = 1; i < pixelList.size(); ++i)
        {
            path.lineTo(pixelList.at(i));
        }
        layer->drawPath(path);
    }
    painter->drawImage(rec, *drawingLayer);
}

void drawingItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (toolType == 3)
    {
        pathlList << event->pos();
    }
    else
    {
        pathlList.clear();
    }
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void drawingItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    pixelList.clear();
    QGraphicsItem::mouseReleaseEvent(event);
}

void drawingItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (toolType != 3 && pressed)
    {
        pixelList << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void drawingItem::toolTypeUpdate(int t)
{
    toolType = t;
}

void drawingItem::setAnti(bool checked)
{
    layer->setRenderHint(QPainter::Antialiasing, checked);
}
