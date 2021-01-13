#include "locationshow.h"
#include "iostream"
#include <QTimer>

#define BIASX 445
#define BIASY 250

int flag = 0;

LocationShow::LocationShow(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    layout->setMargin(0);
    buttonA = new QPushButton(this);
    buttonB = new QPushButton(this);
    location = new QLabel(this);
    name = new QLabel(this);
    number = new QComboBox(this);

    //创建红点闪烁，提醒电极位置
    flashing = new QPushButton(this->location);
    flashing->setEnabled(false);
    flashing->setFixedSize(QSize(50, 50));
    flashing->setStyleSheet("background: red; border-radius:25");
    op = new QGraphicsOpacityEffect();
    op->setOpacity(0.6);
    flashing->setGraphicsEffect(op);
    flashing->setAutoFillBackground(true);

    name->setFont(QFont("Times NewRoman", 135));
    name->setAlignment(Qt::AlignCenter);

    buttonA->setText("A");
    buttonA->setFixedSize(QSize(150, 30));
    buttonA->setFont(QFont("Times NewRoman", 15));
    buttonA->setStyleSheet("color: black; border-radius: 8px; background-color: #F07C82");

    buttonB->setText("B");
    buttonB->setFixedSize(QSize(150, 30));
    buttonB->setFont(QFont("Times NewRoman", 15));
    buttonB->setStyleSheet("color: black;  border-radius: 7px; background-color: white");

    number->setFixedHeight(30);
    number->setStyleSheet("color: black;  border-radius: 1px; background-color: white");
    number->setFont(QFont("Times NewRoman", 17));

    location->setStyleSheet("background-image: url(D:/RSVP-platform/LiEEG/resources/eeg.png); border:none");
    location->setFixedSize(QSize(683, 683));

    layout->addWidget(buttonA, 6, 8, 1, 2);
    layout->addWidget(buttonB, 6, 11, 1, 2);
    layout->addWidget(location, 0, 0, 10, 7);
    layout->addWidget(name, 0, 7, 5, 7);
    layout->addWidget(number, 8, 8, 1, 5);

    // 初始化
    number->clear();
    flashing->move(292-BIASX, 147-BIASY);
    buttonA->setStyleSheet("color: black; border-radius: 8px; background-color: #F07C82");
    buttonB->setStyleSheet("color: black; border-radius: 8px; background-color: white");
    for(int i = 0; i< 32; i++)
    {
        number->addItem("1");
        char index[5];
        itoa(i+1, index, 10);
        index[2] = index[1];
        index[1] = index[0];
        index[0]='A';
        number->setItemText(i, index);
    }

    result = getFindResult(number->currentText().toStdString());
    name->setText(result.eegName.c_str());

    connect(buttonA, SIGNAL(clicked()),
            this, SLOT(buttonAClicked()));
    connect(buttonB, SIGNAL(clicked()),
            this, SLOT(buttonBClicked()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUi()));
    timer->start(50);

}

void LocationShow::buttonAClicked()
{
    // 表示A列被选中
    number->clear();
    buttonA->setStyleSheet("color: black; border-radius: 8px; background-color: #F07C82");
    buttonB->setStyleSheet("color: black; border-radius: 8px; background-color: white");
    for(int i = 0; i<32; i++)
    {
        number->addItem("1");
        char index[5];
        itoa(i+1, index, 10);
        index[2] = index[1];
        index[1] = index[0];
        index[0]='A';
        number->setItemText(i, index);
    }
}

void LocationShow::buttonBClicked()
{
    // 表示B列被选中
    number->clear();
    buttonB->setStyleSheet("color: black; border-radius: 8px; background-color: #F07C82");
    buttonA->setStyleSheet("color: black; border-radius: 8px; background-color: white");
    for(int i = 0; i<32; i++)
    {
        number->addItem("1");
        char index[5];
        itoa(i+1, index, 10);
        index[2] = index[1];
        index[1] = index[0];
        index[0]='B';
        number->setItemText(i, index);
    }
    update();
}

void LocationShow::updateUi()
{
    if(flag < 7)
    {
        flashing->setVisible(true);
        flag ++;
    }
    else if(flag < 14){
        flashing->setVisible(false);
        flag ++;
    }
    else {
        flag = 0;
    }
    result = getFindResult(number->currentText().toStdString());
    name->setText(result.eegName.c_str());
    flashing->move(result.eegLocationX-BIASX, result.eegLocationY-BIASY);
}


