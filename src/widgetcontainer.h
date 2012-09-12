#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <QWidget>

#include "properties.h"
#include "options.h"
#include "canvas.h"

class WidgetContainer : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetContainer(QWidget *p = 0);
    options *toolPanel;
    properties *propertyPanel;
    canvas *canvasArea;
    QGridLayout *layout;

    QWidget *parent;

signals:
    
public slots:
    
};

#endif // WIDGETCONTAINER_H
