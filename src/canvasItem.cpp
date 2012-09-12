#include "canvasItem.h"

#include <QCursor>
#include <iostream>
#include <QGraphicsSceneHoverEvent>
#include <cmath>

canvasItem::canvasItem()
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    selected = pressed = false;
    image = new QImage("/home/matthew/test2/sean-connery.ppm");
    setAcceptHoverEvents(true);
    dragType = posCursor = NONE;
}

canvasItem::canvasItem(char *file)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    selected = pressed = false;
    image = new QImage(file);
    setAcceptHoverEvents(true);
    dragType = posCursor = NONE;
}

canvasItem::canvasItem(QString &file, MainWindow *p)
{
    pressed = selected = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemIsFocusable);

    image = new QImage(file);
    setAcceptHoverEvents(true);
    dragType = posCursor = NONE;

    firstKey = -1;
    maxZVal = 1;
    prevZVal;
    parent = p;
}

canvasItem::canvasItem(int width, int height, QColor &color, int x, int y, MainWindow* p)
{
    pressed = selected = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemIsFocusable);
    image = new QImage(width, height, QImage::Format_RGB888);
    image->fill(color);
    setAcceptHoverEvents(true);
    setPos(x, y);
    dragType = posCursor = NONE;

    firstKey = -1;
    maxZVal = 1;
    prevZVal;
    parent = p;
}

QRectF canvasItem::boundingRect() const
{
    return QRectF(0, 0, image->width(), image->height());
}

void canvasItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QPen pen(QColor(50, 50, 20));
    pen.setWidth(3);
    pen.setStyle(Qt::DashLine);

    painter->drawImage(rec, *image);
    painter->setPen(pen);

    if (posCursor == LEFT)
    {
        painter->drawLine(rec.topLeft(), rec.bottomLeft());
    }
    else if (posCursor == RIGHT)
    {
        painter->drawLine(rec.topRight(), rec.bottomRight());
    }
    else if (posCursor == TOP)
    {
        painter->drawLine(rec.topLeft(), rec.topRight());
    }
    else if (posCursor == BOTTOM)
    {
        painter->drawLine(rec.bottomLeft(), rec.bottomRight());
    }
    else if (isSelected())
    {
        QPen selectedItem(QColor(18, 21, 39));
        selectedItem.setStyle(Qt::SolidLine);
        selectedItem.setWidth(3);
        painter->setPen(selectedItem);

        painter->drawLine(rec.topLeft(), rec.bottomLeft());
        painter->drawLine(rec.topRight(), rec.bottomRight());
        painter->drawLine(rec.bottomLeft(), rec.bottomRight());
        painter->drawLine(rec.topLeft(), rec.topRight());
    }
    else if (posCursor == CENTER && !isSelected())
    {
        painter->drawLine(rec.topLeft(), rec.bottomLeft());
        painter->drawLine(rec.topRight(), rec.bottomRight());
        painter->drawLine(rec.bottomLeft(), rec.bottomRight());
        painter->drawLine(rec.topLeft(), rec.topRight());
    }
}

void canvasItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
    parent->mainWidget->propertyPanel->imageWidth->setText(QString::number(image->width()));
    parent->mainWidget->propertyPanel->imageHeight->setText(QString::number(image->height()));
    parent->mainWidget->propertyPanel->widgetTitle->setText("Object");
    parent->mainWidget->propertyPanel->show();

    if (posCursor == TOP)
    {
        dragType = TOP_DRAG;
    }
    else if (posCursor == BOTTOM)
    {
        dragType = BOTTOM_DRAG;
    }
    else if (posCursor == LEFT)
    {
        dragType = LEFT_DRAG;
    }
    else if (posCursor == RIGHT)
    {
        dragType = RIGHT_DRAG;
    }
    else
    {
        dragType = NONE;
    }

    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void canvasItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (dragType == TOP_DRAG)
    {
        resizeBilinear(image->width(), image->height() - dragDistance);
        QPointF p = pos();
        setY(p.y() + dragDistance);
    }
    else if (dragType == LEFT_DRAG)
    {

        resizeBilinear(image->width() - dragDistance, image->height());
        QPointF p = pos();
        setX(p.x() + dragDistance);
    }
    else if (dragType == RIGHT_DRAG)
    {
        resizeBilinear(image->width() - dragDistance, image->height());
        QPointF p = pos();
        setX(p.x() + 0.00001); // Force Update
    }
    else if (dragType == BOTTOM_DRAG)
    {
        resizeBilinear(image->width(), image->height() - dragDistance);
        QPointF p = pos();
        setX(p.x() + 0.00001); //Force Update
    }
    pressed = false;
    dragType = NONE;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void canvasItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    dragType = posCursor = NONE;
    update();
    QGraphicsItem::hoverLeaveEvent(event);
}

void canvasItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QPointF p = event->pos();

    if (p.x() <= 3)
    {
        posCursor = LEFT;
        setCursor(Qt::SizeHorCursor);
        update();
    }
    else if (p.y() <= 3)
    {
        posCursor = TOP;
        setCursor(Qt::SizeVerCursor);
        update();
    }
    else if (p.x() >= (image->width() - 3) )
    {
        posCursor = RIGHT;
        setCursor(Qt::SizeHorCursor);
        update();
    }
    else if (p.y() >= (image->height() - 3) )
    {
        posCursor = BOTTOM;
        setCursor(Qt::SizeVerCursor);
        update();
    }
    else
    {
        setCursor(Qt::OpenHandCursor);
        posCursor = CENTER;
        update();
    }
}

void canvasItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (dragType == LEFT_DRAG)
    {
        QPointF p = event->pos();
        dragDistance = p.x();
        update();
    }
    else if (dragType == RIGHT_DRAG)
    {
        QPointF p = event->pos();
        dragDistance = image->width() - p.x();
        update();
    }
    else if (dragType == TOP_DRAG)
    {
        QPointF p = event->pos();
        dragDistance = p.y();
        update();
    }
    else if (dragType == BOTTOM_DRAG)
    {
        QPointF p = event->pos();
        dragDistance = image->height() - p.y();
        update();
    }
    else
    {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void canvasItem::keyPressEvent(QKeyEvent *event)
{
    int keyPress = event->key();

    if (firstKey == Qt::Key_Control)
    {
        int zVal = zValue();
        if (keyPress == Qt::Key_Up)
        {
            if (zVal < maxZVal) {
                setZValue(maxZVal++);
            }
        }
        else if (keyPress == Qt::Key_Down)
        {
            if (zVal > 0)
                setZValue(zVal - 1);
        }
    }
    else
    {
        firstKey = keyPress;

        if (keyPress == Qt::Key_Left)
        {
            QPointF p = pos();
            setX(p.x() - 1);
        }
        else if (keyPress == Qt::Key_Up)
        {
            QPointF p = pos();
            setY(p.y() - 1);
        }
        else if (keyPress == Qt::Key_Right)
        {
            QPointF p = pos();
            setX(p.x() + 1);
        }
        else if (keyPress == Qt::Key_Down)
        {
            QPointF p = pos();
            setY(p.y() + 1);
        }
    }
}

void canvasItem::keyReleaseEvent(QKeyEvent *event)
{
    if (firstKey == event->key())
    {
        firstKey = -1;
    }
}

void canvasItem::gradientFill(const QColor &startColor, const QColor &endColor)
{
    int red, green, blue;
    double percent;
    QRgb value;
    int HEIGHT = image->height(), WIDTH = image->width();

    for (unsigned int x = 0; x < HEIGHT; ++x)
    {
        for (unsigned int y = 0; y < WIDTH; ++y)
        {
            percent = y / (double)WIDTH;

            red = startColor.red() + (int)(percent * (endColor.red() - startColor.red()));
            green = startColor.green() + (int)(percent * (endColor.green() - startColor.green()));
            blue = startColor.blue() + (int)(percent * (endColor.blue() - startColor.blue()));

            value = qRgb(red, green, blue);

            image->setPixel(y, x, value);
        }
    }
}

void canvasItem::fill(const QColor& color)
{
    QRgb value;

    for (unsigned int x = 0; x < image->height(); ++x)
    {
        for (unsigned int y = 0; y < image->width(); ++y)
        {
            value = qRgb(color.red(), color.green(), color.blue());

            image->setPixel(y, x, value);
        }
    }
}

void canvasItem::greyscale()
{
    QRgb value;
    for (unsigned int x = 0; x < image->height(); ++x)
    {
        for (unsigned int y = 0; y < image->width(); ++y)
        {
            value = image->pixel(y, x);
            QColor p(value);
            unsigned short int avg = (p.red() + p.green() + p.blue()) / 3;

            value = qRgb(avg, avg, avg);
            image->setPixel(y, x, value);
        }
    }
}

void canvasItem::horizontalBlur()
{
    unsigned int avgRed, avgGreen, avgBlue, count, y, end;

    const int WIDTH = image->width();

    for (unsigned int x = 0; x < image->height(); ++x)
    {
        end = y = avgRed = avgGreen = avgBlue = count = 0;

        while (end < WIDTH)
        {
            avgRed   = (qRed(image->pixel(y, x)) + qRed(image->pixel(y + 1, x)) + qRed(image->pixel(y + 2, x))) / 3;
            avgGreen = (qGreen(image->pixel(y, x)) + qGreen(image->pixel(y + 1, x)) + qGreen(image->pixel(y + 2, x))) / 3;
            avgBlue  = (qBlue(image->pixel(y, x)) + qBlue(image->pixel(y + 1, x)) + qBlue(image->pixel(y + 2, x))) / 3;

            end = y + 3;

            image->setPixel(y, x, qRgb(avgRed, avgGreen, avgBlue));
            image->setPixel(y + 1, x, qRgb(avgRed, avgGreen, avgBlue));
            image->setPixel(y + 2, x, qRgb(avgRed, avgGreen, avgBlue));

            y++;
        }
    }
}

void canvasItem::contrastExtreme()
{
    const unsigned short int MID = 255 / 0.5;
    short int red, green, blue;

    for (unsigned int x = 0; x < image->height(); ++x)
    {
        for (unsigned int y = 0; y < image->width(); ++y)
        {
            if ((red = qRed(image->pixel(y, x))) < MID )
                red = 0;
            else if (red > MID)
                red = 255;

            if ((green = qGreen(image->pixel(y, x))) < MID)
                green = 0;
            else if (green > MID)
                green = 255;

            if ((blue = qBlue(image->pixel(y, x))) < MID)
                blue = 0;
            else if (blue > MID)
                blue = 255;

            image->setPixel(y, x, qRgb(red, green, blue));
        }
    }
}

void canvasItem::resizeBilinear(int newWidth, int newHeight)
{
    QImage *newImage = new QImage(newWidth, newHeight,  QImage::Format_RGB888);
    double xRatio = ((double)(image->width() -1)) / newWidth;
    double yRatio = ((double)(image->height() -1)) / newHeight;

    QRgb a, b, c, d;
    unsigned int x, y;
    double xDiff, yDiff;
    int red, green, blue;

    for (int i = 0; i < newHeight; i++)
    {
        for (int j = 0; j < newWidth; j++)
        {
            x = (int)(xRatio * j);
            y = (int)(yRatio * i);

            xDiff = (xRatio * j) - x;
            yDiff = (yRatio * i) - y;

            a = image->pixel(x, y);
            b = image->pixel(x + 1, y);
            c = image->pixel(x + 1, y + 1) ;
            d = image->pixel(x, y + 1);

            // Yb = Ab(1-w)(1-h) + Bb(w)(1-h) + Cb(h)(1-w) + Db(wh)
            red = qRed(a) * (1 - xDiff) * (1 - yDiff) + qRed(b) *  xDiff * (1 - yDiff) +
                  qRed(c) * yDiff * (1 - xDiff) + qRed(d) * (xDiff * yDiff);

            // Yg = Ag(1-w)(1-h) + Bg(w)(1-h) + Cg(h)(1-w) + Dg(wh)
            green = qGreen(a) * (1 - xDiff) * (1 - yDiff) + qGreen(b) * xDiff * (1 - yDiff) +
                    qGreen(c) * yDiff * (1 - xDiff) + qGreen(d) * (xDiff * yDiff);

            // Yr = Ar(1-w)(1-h) + Br(w)(1-h) + Cr(h)(1-w) + Dr(wh)
            blue = qBlue(a) * (1 - xDiff) * (1 - yDiff) + qBlue(b) * xDiff * (1 - yDiff) +
                   qBlue(c) * yDiff * (1 - xDiff) + qBlue(d) * (xDiff * yDiff);

            newImage->setPixel(j, i, qRgb(red, green, blue));
        }
    }

    image->swap(*newImage);
    delete newImage;
}
