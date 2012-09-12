#include "toolbutton.h"

toolButton::toolButton(const char *n, int t)
    : QPushButton(n)
{
    type = t;
    setCheckable(true);
}

void toolButton::mousePressEvent(QMouseEvent *e)
{
    emit clicked(type);
    QPushButton::mousePressEvent(e);
}
