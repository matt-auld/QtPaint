#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new WidgetContainer(this);

    setWindowTitle("Blue Ink");
    setCentralWidget(mainWidget);

    QMenu *file = menuBar()->addMenu("&File");
    QMenu *insert = menuBar()->addMenu("&Insert");

    QAction *save = new QAction("&Save", this);
    QAction *quit = new QAction("&Quit", this);
    QAction *insertImage = new QAction("&Image", this);

    insert->addAction(insertImage);
    file->addAction(save);
    file->addAction(quit);

    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(save, SIGNAL(triggered()), this->mainWidget->canvasArea, SLOT(saveImage()));
    connect(insertImage, SIGNAL(triggered()), this, SLOT(insert()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::insert()
{
    QString filename = QFileDialog::getOpenFileName(this);//getting the file name
    mainWidget->canvasArea->addImage(filename, this);
}
