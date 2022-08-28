#ifndef MY_QCOLOR_H
#define MY_QCOLOR_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QGradient>
#include <QPixmap>

class My_QColor : public QWidget
{
    Q_OBJECT
public:
    explicit My_QColor(QWidget *parent = nullptr);
    QColor getColor();

signals:
    void colorChange();

protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent *event);   // 重写按下事件
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPushButton* m_btn;
    int m_chooseX;
    QScreen* screen;
    QColor m_color;

    QRgb getPointColor(QPoint point);
    void onMouseMoveOrPress(QMouseEvent *event);

};

#endif // MY_QCOLOR_H
