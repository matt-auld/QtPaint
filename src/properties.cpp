#include "properties.h"
#include "widgetcontainer.h"

properties::properties(WidgetContainer *parent) :
    QWidget((QWidget*)parent)
{
    widgetTitle = new QLabel();

    imageWidth = new QLabel();
    imageHeight = new QLabel();

    redSlider = new QSlider(Qt::Horizontal);
    redSlider->setMaximum(255);

    greenSlider = new QSlider(Qt::Horizontal);
    greenSlider->setMaximum(255);

    blueSlider = new QSlider(Qt::Horizontal);
    blueSlider->setMaximum(255);

    redValue = new QLabel(tr("0"));
    greenValue = new QLabel(tr("0"));
    blueValue = new QLabel(tr("0"));

    colorlabel = new colorLabel();

    comboEffects = new QComboBox();
    comboEffects->addItem(tr("None"));
    comboEffects->addItem(tr("Greyscale"));
    comboEffects->addItem(tr("Extreme Contrast"));
    comboEffects->addItem(tr("Vertical Blur"));

    layout = new QFormLayout();

    layout->addRow(widgetTitle);
    layout->addRow(tr("&Width:"), imageWidth);
    layout->addRow(tr("&Height:"), imageHeight);

    layout->addRow(tr("&Red:"), redValue);
    layout->addRow(redSlider);

    layout->addRow(tr("&Green:"), greenValue);
    layout->addRow(greenSlider);

    layout->addRow(tr("&Blue:"), blueValue);
    layout->addRow(blueSlider);

    layout->addRow(colorlabel);

    layout->addRow(tr("Effects"), comboEffects);

    connect(redSlider, SIGNAL(valueChanged(int)), redValue, SLOT(setNum(int)));
    connect(greenSlider, SIGNAL(valueChanged(int)), greenValue, SLOT(setNum(int)));
    connect(blueSlider, SIGNAL(valueChanged(int)), blueValue, SLOT(setNum(int)));

    connect(redSlider, SIGNAL(valueChanged(int)), colorlabel, SLOT(setRed(int)));
    connect(greenSlider, SIGNAL(valueChanged(int)), colorlabel, SLOT(setGreen(int)));
    connect(blueSlider, SIGNAL(valueChanged(int)), colorlabel, SLOT(setBlue(int)));

    connect(colorlabel, SIGNAL(clicked(int, int, int)), parent->canvasArea, SLOT(updateSelected(int, int, int)));

    connect(comboEffects, SIGNAL(activated(int)), parent->canvasArea, SLOT(effect(int)));

    this->setLayout(layout);
}

properties::~properties()
{
    delete imageWidth;
    delete imageHeight;
    delete redSlider;
    delete greenSlider;
    delete blueSlider;
    delete layout;
}

void properties::echo()
{
    //std::cout << red << "," << green << "," << blue << "\n";
}
