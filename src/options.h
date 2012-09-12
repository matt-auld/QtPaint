#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QtGui>

#include "toolbutton.h"
#include "optionsbrush.h"

class WidgetContainer;

class options : public QWidget
{
    Q_OBJECT

public:
    explicit options(WidgetContainer *parent = 0);
    QGridLayout *layout;

    QLabel *title;

    toolButton *pencilButton;
    toolButton *linePenButton;
    toolButton *rubberButton;
    toolButton *scaleButton;
    toolButton *selectButton;

    optionsBrush *brushOptions;
    
signals:
    
public slots:
    void showPanel();
    void hidePanel();
    
};

#endif // OPTIONS_H
