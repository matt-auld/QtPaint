#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMenu>

#include "widgetcontainer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    WidgetContainer *mainWidget;
public slots:
    void insert();

};

#endif // MAINWINDOW_H
