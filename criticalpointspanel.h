#ifndef CRITIALPOINTSPANEL_H
#define CRITIALPOINTSPANEL_H

#include <QWidget>
#include "ui_criticalpointspanel.h"

class CriticalPointsPanel : public QWidget
{
    Q_OBJECT

public:
    CriticalPointsPanel(QWidget *parent = 0);
    ~CriticalPointsPanel();

signals:
    void sig_methodChanged(int);
    void sig_smoothingTimesChanged(int);

private:
    Ui::CriticalPointsPanel ui;
};

#endif // CRITIALPOINTSPANEL_H
