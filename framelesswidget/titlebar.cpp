#include "titlebar.h"
#include <QStyleOption>
#include <QPainter>
#include <QSpacerItem>

#define RADIUS 30

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    this->setStyleSheet("background-color: #64BEFC");
    rootWindow = this->window();
    // 最右端四个按钮
    minButton = new QPushButton(this);
    minButton->setFixedSize(QSize(RADIUS, RADIUS));
    minButton->setStyleSheet("background-image: url(D:/RSVP-platform/LiEEG/resources/image.png); border:none");
    maxButton = new QPushButton(this);
    maxButton->setFixedSize(QSize(RADIUS, RADIUS));
    maxButton->setStyleSheet("background-image: url(D:/RSVP-platform/LiEEG/resources/max.png); border:none");
    normButton = new QPushButton(this);
    normButton->setVisible(false);
    normButton->setFixedSize(QSize(RADIUS, RADIUS));
    normButton->setStyleSheet("background-image: url(D:/RSVP-platform/LiEEG/resources/norm.png); border:none");
    closeButton = new QPushButton(this);
    closeButton->setFixedSize(QSize(RADIUS, RADIUS));
    closeButton->setStyleSheet("background-image: url(D:/RSVP-platform/LiEEG/resources/close.png); border:none");

    title = new QLabel(this);
    title->setText("脑电实验助手");
    title->setFont(QFont("SimSun", 14));
    title->setStyleSheet("color: white; font:bold");
    title->setFixedSize(QSize(RADIUS*10, RADIUS));

    icon = new QLabel(this);
    icon->setFixedSize(QSize(25, 25));
    icon->setStyleSheet("background-image: url(D:/RSVP-platform/LiEEG/resources/brain.png); border:none");

    layout = new QHBoxLayout(this);
    layout->addSpacerItem(new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum));
    layout->addWidget(icon);
    layout->addWidget(title);
    layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    layout->addWidget(minButton);
    layout->addWidget(maxButton);
    layout->addWidget(normButton);
    layout->addWidget(closeButton);
    layout->addSpacerItem(new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum));

    connect(minButton, SIGNAL(clicked()),
            this, SLOT(minButtonClicked()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(closeButtonClicked()));
    connect(maxButton, SIGNAL(clicked()),
            this, SLOT(maxButtonClicked()));
    connect(normButton, SIGNAL(clicked()),
            this, SLOT(normButtonClicked()));


}
void TitleBar::closeButtonClicked()
{
    rootWindow->close();
}

void TitleBar::minButtonClicked()
{
    rootWindow->showMinimized();
}


void TitleBar::maxButtonClicked()
{
    rootWindow->showMaximized();
    normButton->setVisible(true);
    maxButton->setVisible(false);
}

void TitleBar::normButtonClicked()
{
    rootWindow->showNormal();
    normButton->setVisible(false);
    maxButton->setVisible(true);
}

void TitleBar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
