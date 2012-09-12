#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QPushButton>

class toolButton : public QPushButton
{
    Q_OBJECT

private:
    int type;

public:
    toolButton(const char*,int);

protected:
    void mousePressEvent(QMouseEvent *e);

signals:
    void clicked(int);
};

#endif // TOOLBUTTON_H
