#include "colorlabel.h"

colorLabel::colorLabel()
{
    red = green = blue = 0;
    color = new QImage(50, 50, QImage::Format_RGB888);
    color->fill(QColor(0, 0, 0));
    setPixmap(QPixmap::fromImage(*color));
}

void colorLabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked(red, green, blue);
}

void colorLabel::setRed(int r)
{
    color->fill(QColor(r, green, blue));
    setPixmap(QPixmap::fromImage(*color));
    red = r;
}

void colorLabel::setGreen(int g)
{
    color->fill(QColor(red, g, blue));
    setPixmap(QPixmap::fromImage(*color));
    green = g;
}

void colorLabel::setBlue(int b)
{
    color->fill(QColor(red, green, b));
    setPixmap(QPixmap::fromImage(*color));
    blue = b;
}


