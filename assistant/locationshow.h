#ifndef LOCATIONSHOW_H
#define LOCATIONSHOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include "inquire.h"
#include "stdlib.h"
#include <QGraphicsOpacityEffect>

class LocationShow : public QWidget
{
    Q_OBJECT
public:
    explicit LocationShow(QWidget *parent = nullptr);
    QGridLayout *layout;
    QPushButton *flashing;
    QPushButton *buttonA;
    QPushButton *buttonB;
    QLabel *location;
    QLabel *name;
    QComboBox *number;
    QGraphicsOpacityEffect *op;
    QMouseEvent *event;

    msgNameLocation result;

signals:

public slots:
    void buttonAClicked();
    void buttonBClicked();
    void updateUi();
};

#endif // LOCATIONSHOW_H
