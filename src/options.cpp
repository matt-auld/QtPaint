#include "options.h"
#include "widgetcontainer.h"
#include "drawingitem.h"

options::options(WidgetContainer *parent) :
    QWidget((QWidget*)parent)
{
    title = new QLabel("Tools");
    pencilButton = new toolButton("", 0);
    pencilButton->setIcon(QIcon("icons/pen.png"));

    linePenButton = new toolButton("", 4);
    linePenButton->setIcon(QIcon("icons/linepen.png"));

    selectButton = new toolButton("", 1);
    selectButton->setIcon(QIcon("icons/select.png"));

    rubberButton = new toolButton("", 2);
    rubberButton->setIcon(QIcon("icons/eraser.png"));

    scaleButton = new toolButton("", 3);
    scaleButton->setIcon(QIcon("icons/scale.png"));

    brushOptions = new optionsBrush(this);

    layout = new QGridLayout();
    layout->addWidget(title, 0, 0);
    layout->addWidget(selectButton, 1, 0);
    layout->addWidget(pencilButton, 1, 1);
    layout->addWidget(linePenButton, 2, 0);
    layout->addWidget(rubberButton, 2, 1);
    layout->addWidget(scaleButton, 3, 0);
    layout->addWidget(brushOptions, 10, 0, 1, 4);

    connect(pencilButton,  SIGNAL(clicked(int)), parent->canvasArea->view, SLOT(setCursorType(int)));
    connect(selectButton,  SIGNAL(clicked(int)), parent->canvasArea->view, SLOT(setCursorType(int)));
    connect(rubberButton,  SIGNAL(clicked(int)), parent->canvasArea->view, SLOT(setCursorType(int)));
    connect(linePenButton, SIGNAL(clicked(int)), parent->canvasArea->view, SLOT(setCursorType(int)));
    connect(scaleButton,   SIGNAL(clicked(int)), parent->canvasArea->view, SLOT(setCursorType(int)));

    connect(pencilButton,  SIGNAL(clicked(int)), this, SLOT(showPanel()));
    connect(selectButton,  SIGNAL(clicked(int)), this, SLOT(hidePanel()));
    connect(rubberButton,  SIGNAL(clicked(int)), this, SLOT(showPanel()));
    connect(linePenButton, SIGNAL(clicked(int)), this, SLOT(showPanel()));
    connect(scaleButton,   SIGNAL(clicked(int)), this, SLOT(hidePanel()));

    connect(brushOptions->anti, SIGNAL(clicked(bool)), parent->canvasArea->drawingLayer, SLOT(setAnti(bool)));

    connect(pencilButton,  SIGNAL(clicked(int)), parent->canvasArea->drawingLayer, SLOT(toolTypeUpdate(int)));
    connect(selectButton,  SIGNAL(clicked(int)), parent->canvasArea->drawingLayer, SLOT(toolTypeUpdate(int)));
    connect(rubberButton,  SIGNAL(clicked(int)), parent->canvasArea->drawingLayer, SLOT(toolTypeUpdate(int)));
    connect(linePenButton, SIGNAL(clicked(int)), parent->canvasArea->drawingLayer, SLOT(toolTypeUpdate(int)));
    connect(scaleButton,   SIGNAL(clicked(int)), parent->canvasArea->drawingLayer, SLOT(toolTypeUpdate(int)));

    this->setLayout(layout);
}

void options::showPanel()
{
    brushOptions->show();
}

void options::hidePanel()
{
    brushOptions->hide();
}
