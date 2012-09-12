#include "widgetcontainer.h"

WidgetContainer::WidgetContainer(QWidget *p) :
    QWidget(p)
{
    parent = p;
    canvasArea = new canvas(p);
    toolPanel = new options(this);
    propertyPanel = new properties(this);
    propertyPanel->hide();

    layout = new QGridLayout();

    layout->setColumnStretch(0, 0);
    layout->setRowStretch(0, 0);
    layout->setSpacing(0);

    layout->addWidget(toolPanel, 0, 0, 1, 1);
    layout->addWidget(canvasArea, 0, 1, 5, 3);
    layout->addWidget(propertyPanel, 0, 6, 3, 3);

    this->setLayout(layout);
}
