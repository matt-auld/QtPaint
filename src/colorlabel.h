#ifndef COLORLABEL_H
#define COLORLABEL_H

#include <QLabel>

class colorLabel : public QLabel
{
    Q_OBJECT
public:
    colorLabel();
    int red, green, blue;
    QImage *color;

signals:
    void clicked(int, int, int);

public slots:
    void setRed(int);
    void setGreen(int);
    void setBlue(int);

protected:
    void mousePressEvent(QMouseEvent *ev);

};

#endif // COLORLABEL_H
