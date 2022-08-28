#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBox_brightness->setValue(255);
    ui->brightness->setValue(255);
    this->m_client = new QMqttClient(this);
    this->m_lastTime = 0;

    connect(ui->spinBox_R, &QSpinBox::valueChanged, this, &Widget::on_Spin_Box_change);
    connect(ui->spinBox_G, &QSpinBox::valueChanged, this, &Widget::on_Spin_Box_change);
    connect(ui->spinBox_B, &QSpinBox::valueChanged, this, &Widget::on_Spin_Box_change);
    connect(ui->spinBox_brightness, &QSpinBox::valueChanged, this, &Widget::on_Spin_Box_change);

    connect(ui->qcolor, &My_QColor::colorChange, this, &Widget::on_color_change);
    connect(ui->brightness, &QSlider::valueChanged, this, &Widget::on_color_change);

    connect(ui->brightness, &QSlider::sliderReleased, this, &Widget::on_color_change);

    connect(this->m_client, &QMqttClient::connected, this, &Widget::on_Connected);  // 连接成功 MQTTClient 会发出一个信号
    connect(this->m_client, &QMqttClient::disconnected, this, &Widget::on_DisConnected);// 断开连接 MQTTClient 会发出一个信号
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_color_change()
{
    // 加上发送速度限制，以免发送速度过快
    if(!((clock() - this->m_lastTime) > 50))
        return;

    ui->showcolor->setColor(ui->qcolor->getColor());

    ui->spinBox_R->setValue(ui->qcolor->getColor().red());
    ui->spinBox_G->setValue(ui->qcolor->getColor().green());
    ui->spinBox_B->setValue(ui->qcolor->getColor().blue());
    ui->spinBox_brightness->setValue(ui->brightness->value());

    this->publish_color(ui->spinBox_R->value(), ui->spinBox_G->value(), ui->spinBox_B->value(), ui->spinBox_brightness->value());
}

void Widget::on_Spin_Box_change()
{
    // 加上发送速度限制，以免发送速度过快
    if(!((clock() - this->m_lastTime) > 50))
        return;

    ui->showcolor->setColor(QColor(ui->spinBox_R->value(), ui->spinBox_G->value(), ui->spinBox_B->value()));
    ui->brightness->setValue(ui->spinBox_brightness->value());

    this->publish_color(ui->spinBox_R->value(), ui->spinBox_G->value(), ui->spinBox_B->value(), ui->spinBox_brightness->value());
}

void Widget::publish_color(int r, int g, int b, int brightness)
{
    //if((clock() - this->m_lastTime) > 50){
        this->m_lastTime = clock();
        QString buf;
        buf += "{\"color\": \[" + QString::number(r) + "," +
                                  QString::number(g) + "," +
                                  QString::number(b) + "]," +
                "\"brightness\":\"" + QString::number(brightness) + "\"}";
        this->m_client->publish(QString("test/color"), buf.toUtf8());
    //}
}

void Widget::on_Connected()
{
    QMessageBox::about(this, "提示", "连接成功");
}

void Widget::on_DisConnected()
{
    QMessageBox::about(this, "提示", "断开连接");
}


void Widget::on_pushButtonConnect_clicked()
{
    this->m_client->setHostname(QString("117.50.181.42"));           // 设置 MqttClient 的 ip
    this->m_client->setPort(1883);                                   // 设置 MqttClient 的 端口
    this->m_client->setClientId(QString("Win10-QT-Color-Setting"));  // 设置 MqttClient 的 客户端ID
    this->m_client->setUsername(QString("root"));                    // 设置 MqttClient 的 用户名
    this->m_client->setPassword(QString("123456"));                  // 设置 MqttClient 的 密码

    if (m_client->state() == QMqttClient::Disconnected)
        m_client->connectToHost();
}

