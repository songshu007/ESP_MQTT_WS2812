#include "my_qcolor.h"
#include "qapplication.h"
#include "QDebug"

My_QColor::My_QColor(QWidget *parent)
    : QWidget{parent}
{

}

QColor My_QColor::getColor()
{
    return this->m_color;
}

void My_QColor::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPen pen;   // 画笔
    pen.setColor(Qt::black);
    pen.setWidth(1);

    QLinearGradient LinearGradient = QLinearGradient(QPointF(0, QWidget::size().height() * 0.5),
                                                     QPointF(QWidget::size().width(), QWidget::size().height() * 0.5)); // 渐变
    LinearGradient.setColorAt(0, Qt::red);
    LinearGradient.setColorAt(0.16, Qt::magenta);
    LinearGradient.setColorAt(0.16 * 2, Qt::blue);
    LinearGradient.setColorAt(0.16 * 3, QColor(0, 128, 128));
    LinearGradient.setColorAt(0.16 * 4, Qt::green);
    LinearGradient.setColorAt(0.16 * 5, Qt::yellow);
    LinearGradient.setColorAt(1, Qt::red);

    QBrush brush(LinearGradient);   // 画刷

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, QWidget::size().width() - 1, QWidget::size().height() - 1);

    QPainter painter2(this);
    painter2.setRenderHint(QPainter::Antialiasing);
    pen.setWidth(4);
    painter2.setPen(pen);
    painter2.drawEllipse(QPoint(this->m_chooseX, QWidget::size().height()), 3, 3);
    this->update();
}

void My_QColor::mousePressEvent(QMouseEvent *event)
{
    this->onMouseMoveOrPress(event);
}

void My_QColor::mouseMoveEvent(QMouseEvent *event)
{
    this->onMouseMoveOrPress(event);
}

QRgb My_QColor::getPointColor(QPoint point)
{
    this->screen = QApplication::primaryScreen();
    const QPixmap pixmap = screen->grabWindow(this->winId(), 0, 0, -1, -1);
    const QImage img = pixmap.toImage();
    return img.pixel(point.x(), point.y());
}

void My_QColor::onMouseMoveOrPress(QMouseEvent *event)
{
    this->m_chooseX = event->pos().x();

    if(event->pos().x() >= QWidget::size().width())
        this->m_chooseX = QWidget::size().width() - 1;
    if(event->pos().x() < 0)
        this->m_chooseX = 0;

    this->m_color = this->getPointColor(QPoint(this->m_chooseX, QWidget::size().height() * 0.5));
    emit(this->colorChange());
}
