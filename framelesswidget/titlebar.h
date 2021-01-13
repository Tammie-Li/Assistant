#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    QWidget *rootWindow;
    QLabel *icon;
    QLabel *title;
    QPushButton *minButton;
    QPushButton *maxButton;
    QPushButton *normButton;
    QPushButton *closeButton;


    QHBoxLayout *layout;

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void minButtonClicked();
    void normButtonClicked();
    void closeButtonClicked();
    void maxButtonClicked();
};

#endif // TITLEBAR_H
