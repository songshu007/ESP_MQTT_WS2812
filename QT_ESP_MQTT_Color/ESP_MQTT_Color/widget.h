#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtMqtt/QMqttClient>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::Widget *ui;
    QMqttClient* m_client;
    clock_t m_lastTime;

    void on_color_change();
    void on_Spin_Box_change();
    void publish_color(int r, int b, int g, int brightness);
    void on_Connected();
    void on_DisConnected();
};
#endif // WIDGET_H
