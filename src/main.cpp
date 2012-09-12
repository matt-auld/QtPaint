#include <QtGui/QApplication>
#include "mainwindow.h"
#include "canvasItem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();

    QColor red(255, 0, 0);
    QColor blue(0, 0, 255);

    canvasItem *item1 = new canvasItem(100, 100, red, 40, 40, w);
    canvasItem *item2 = new canvasItem(200, 100, blue, 100, 100, w);

    item1->image->fill(red);
    item2->image->fill(blue);

    w->mainWidget->canvasArea->scene->addItem(item1);
    w->mainWidget->canvasArea->scene->addItem(item2);

    w->show();
    
    return a.exec();
}
