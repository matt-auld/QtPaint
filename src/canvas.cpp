#include "canvas.h"
#include "canvasItem.h"
#include "drawingitem.h"
#include <QGraphicsItem>

canvas::canvas(QWidget *parent) :
    QWidget(parent)
{
    selectedTool = -1;

    drawingLayer = new drawingItem(600, 600);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    view = new customView(scene, parent);

    view->setFixedSize(600, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setSceneRect(0, 0, 600, 600);
    view->show();

    scene->addItem(drawingLayer);

    layout = new QVBoxLayout();
    layout->addWidget(view);

    this->setLayout(layout);
}



void canvas::updateSelected(int r, int g, int b)
{
    canvasItem *tmp;
    QList<QGraphicsItem *> items = scene->selectedItems();

    for (int i = 0; i < items.size(); ++i)
    {
        tmp = qgraphicsitem_cast<canvasItem *>(items.value(i));
        tmp->image->fill(QColor(r, g, b));
        tmp->update();
    }
}

void canvas::effect(int i)
{
    if (i == 1)
    {
        canvasItem *tmp;
        QList<QGraphicsItem *> items = scene->selectedItems();

        for (int i = 0; i < items.size(); ++i)
        {
            tmp = qgraphicsitem_cast<canvasItem *>(items.value(i));
            tmp->greyscale();
            tmp->update();
        }
    }
    else if (i == 3)
    {
        canvasItem *tmp;
        QList<QGraphicsItem *> items = scene->selectedItems();

        for (int i = 0; i < items.size(); ++i)
        {
            tmp = qgraphicsitem_cast<canvasItem *>(items.value(i));
            tmp->horizontalBlur();
            tmp->update();
        }
    }
    else if (i == 2)
    {
        canvasItem *tmp;
        QList<QGraphicsItem *> items = scene->selectedItems();

        for (int i = 0; i < items.size(); ++i)
        {
            tmp = qgraphicsitem_cast<canvasItem *>(items.value(i));
            tmp->contrastExtreme();
            tmp->update();
        }
    }
}

canvas::~canvas()
{

}

void canvas::addImage(QString &file, MainWindow *p)
{
    canvasItem *newImage = new canvasItem(file, p);
    scene->addItem(newImage);
}

void canvas::saveImage()
{
    QString FilePath = QFileDialog::getSaveFileName(this);

    if(FilePath.isEmpty())
        return;

    QImage newImage(600, 600, QImage::Format_RGB888);
    QPainter painter(&newImage);
    scene->render(&painter);
    newImage.save(FilePath);
}
