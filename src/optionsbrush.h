#ifndef OPTIONSBRUSH_H
#define OPTIONSBRUSH_H

#include <QWidget>
#include <QtGui>

class optionsBrush : public QWidget
{
    Q_OBJECT
public:
    explicit optionsBrush(QWidget *parent = 0);
    QCheckBox *anti;
private:
    QVBoxLayout *layout;
    QLabel *title;

signals:
    
public slots:
    
};

#endif // OPTIONSBRUSH_H
