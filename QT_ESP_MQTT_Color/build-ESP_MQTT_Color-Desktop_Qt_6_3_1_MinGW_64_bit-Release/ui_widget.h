/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <my_colorshow.h>
#include "my_qcolor.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    My_QColor *qcolor;
    My_ColorShow *showcolor;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBox_R;
    QLabel *label_3;
    QSpinBox *spinBox_G;
    QLabel *label_4;
    QSpinBox *spinBox_B;
    QLabel *label_5;
    QSpinBox *spinBox_brightness;
    QSlider *brightness;
    QLabel *label;
    QPushButton *pushButtonConnect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 465, 176));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        qcolor = new My_QColor(groupBox);
        qcolor->setObjectName(QString::fromUtf8("qcolor"));
        qcolor->setMinimumSize(QSize(427, 31));

        gridLayout->addWidget(qcolor, 0, 0, 1, 2);

        showcolor = new My_ColorShow(groupBox);
        showcolor->setObjectName(QString::fromUtf8("showcolor"));
        showcolor->setMinimumSize(QSize(81, 41));

        gridLayout->addWidget(showcolor, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(354, 71));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16, 21));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        spinBox_R = new QSpinBox(groupBox_2);
        spinBox_R->setObjectName(QString::fromUtf8("spinBox_R"));
        spinBox_R->setFont(font);
        spinBox_R->setMaximum(255);

        horizontalLayout->addWidget(spinBox_R);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16, 21));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        spinBox_G = new QSpinBox(groupBox_2);
        spinBox_G->setObjectName(QString::fromUtf8("spinBox_G"));
        spinBox_G->setFont(font);
        spinBox_G->setMaximum(255);

        horizontalLayout->addWidget(spinBox_G);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16, 21));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        spinBox_B = new QSpinBox(groupBox_2);
        spinBox_B->setObjectName(QString::fromUtf8("spinBox_B"));
        spinBox_B->setFont(font);
        spinBox_B->setMaximum(255);

        horizontalLayout->addWidget(spinBox_B);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        spinBox_brightness = new QSpinBox(groupBox_2);
        spinBox_brightness->setObjectName(QString::fromUtf8("spinBox_brightness"));
        spinBox_brightness->setFont(font);
        spinBox_brightness->setMaximum(255);

        horizontalLayout->addWidget(spinBox_brightness);


        gridLayout->addWidget(groupBox_2, 1, 1, 2, 1);

        brightness = new QSlider(groupBox);
        brightness->setObjectName(QString::fromUtf8("brightness"));
        brightness->setMaximum(255);
        brightness->setOrientation(Qt::Horizontal);
        brightness->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(brightness, 3, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        pushButtonConnect = new QPushButton(Widget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(520, 40, 80, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\351\242\234\350\211\262", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\211\213\345\212\250", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "R", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "G", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "B", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\344\272\256\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\272\256\345\272\246", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
