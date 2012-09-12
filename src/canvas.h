#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QtGui>
#include <iostream>

#include "customview.h"

class canvasItem;
class drawingItem;

class canvas : public QWidget
{
    Q_OBJECT
public:
    canvas(QWidget *parent = 0);
    ~canvas();

    int selectedTool;

    QVBoxLayout *layout;
    QGraphicsScene *scene;
    customView *view;
    drawingItem *drawingLayer;

    void addImage(QString&, MainWindow*);


signals:
    
public slots:
    void updateSelected(int, int, int);
    void effect(int);
    void saveImage();
};

#endif // CANVAS_H
