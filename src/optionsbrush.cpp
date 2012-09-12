#include "optionsbrush.h"

optionsBrush::optionsBrush(QWidget *parent) :
    QWidget(parent)
{
    title = new QLabel("Brush Options");
    anti = new QCheckBox("Antialiasing");

    layout = new QVBoxLayout();

    layout->addWidget(title);
    layout->addWidget(anti);

    this->setLayout(layout);
    this->hide();
}
