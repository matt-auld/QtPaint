#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QWidget>
#include <QtGui>
#include <QImage>
#include <iostream>

#include "colorlabel.h"

class WidgetContainer;

class properties : public QWidget
{
    Q_OBJECT

public:
    explicit properties(WidgetContainer *parent = 0);
    ~properties();
    QFormLayout *layout;

    QLabel *widgetTitle;
    QLabel *imageWidth;
    QLabel *imageHeight;
    QLabel *redValue, *greenValue, *blueValue;

    QSlider *redSlider;
    QSlider *greenSlider;
    QSlider *blueSlider;

    colorLabel *colorlabel;

    QComboBox *comboEffects;

signals:
    
public slots:
    void echo();

};

#endif // PROPERTIES_H
