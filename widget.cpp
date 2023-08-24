#include "widget.h"
#include "ui_widget.h"
#include<QPoint>
#include<QMouseEvent>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

