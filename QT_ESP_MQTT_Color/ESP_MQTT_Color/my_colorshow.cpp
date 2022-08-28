#include "my_colorshow.h"

My_ColorShow::My_ColorShow(QWidget *parent)
    : QWidget{parent}
{
    this->m_color = Qt::black;
}

void My_ColorShow::setColor(QColor color)
{
    this->m_color = color;
}

void My_ColorShow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPen pen;
    pen.setColor(this->m_color);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(this->m_color);
    painter.drawRect(0, 0, QWidget::size().width() - 1, QWidget::size().height() - 1);

    this->update();
}
