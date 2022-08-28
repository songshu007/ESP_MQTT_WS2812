#ifndef MY_COLORSHOW_H
#define MY_COLORSHOW_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QGradient>
#include <QPixmap>

class My_ColorShow : public QWidget
{
    Q_OBJECT
public:
    explicit My_ColorShow(QWidget *parent = nullptr);
    void setColor(QColor color);

signals:

protected:
     void paintEvent(QPaintEvent * event);

private:
     QColor m_color;

};

#endif // MY_COLORSHOW_H
