/********************************************************************************
** Form generated from reading UI file 'ImageStisch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESTISCH_H
#define UI_IMAGESTISCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_ImageStischClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *title_widget_btn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *title_hsapcer_1;
    QPushButton *title_btn_menu;
    QPushButton *title_btn_min;
    QPushButton *title_btn_max;
    QPushButton *title_btn_close;
    QWidget *widgetBase_GrayBackground;
    QHBoxLayout *horizontalLayout_13;
    QWidget *ResWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *widgetBase_whiteBackground;
    QVBoxLayout *verticalLayout_3;
    GraphicsView *m_Vectorview;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_1;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnReadFile;
    QTableView *ImageList;
    QPushButton *btnSetup;
    QPushButton *btnStart;
    QPushButton *btnSave;
    QLabel *lblRes;

    void setupUi(QMainWindow *ImageStischClass)
    {
        if (ImageStischClass->objectName().isEmpty())
            ImageStischClass->setObjectName(QStringLiteral("ImageStischClass"));
        ImageStischClass->resize(1060, 700);
        centralWidget = new QWidget(ImageStischClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        title_widget_btn = new QWidget(centralWidget);
        title_widget_btn->setObjectName(QStringLiteral("title_widget_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title_widget_btn->sizePolicy().hasHeightForWidth());
        title_widget_btn->setSizePolicy(sizePolicy);
        title_widget_btn->setMinimumSize(QSize(0, 35));
        title_widget_btn->setMaximumSize(QSize(16777215, 35));
        title_widget_btn->setAutoFillBackground(false);
        title_widget_btn->setStyleSheet(QStringLiteral("QWidget{color:#FFFFFF; background: #2e83f1;}"));
        horizontalLayout_5 = new QHBoxLayout(title_widget_btn);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(title_widget_btn);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setKerning(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);

        title_hsapcer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(title_hsapcer_1);

        title_btn_menu = new QPushButton(title_widget_btn);
        title_btn_menu->setObjectName(QStringLiteral("title_btn_menu"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(title_btn_menu->sizePolicy().hasHeightForWidth());
        title_btn_menu->setSizePolicy(sizePolicy2);
        title_btn_menu->setMinimumSize(QSize(34, 26));
        title_btn_menu->setMaximumSize(QSize(34, 26));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        title_btn_menu->setFont(font1);
#ifndef QT_NO_TOOLTIP
        title_btn_menu->setToolTip(QString::fromUtf8("\350\217\234\345\215\225"));
#endif // QT_NO_TOOLTIP
        title_btn_menu->setStyleSheet(QLatin1String("QPushButton{background:url(:/Resource/Resources/icon_menu_1.png);border:0;}\n"
"QPushButton::hover{background:url(:/Resource/Resources/icon_menu_2.png);}\n"
"QPushButton::pressed{background:url(:/Resource/Resources/icon_menu_3.png);}"));
        title_btn_menu->setShortcut(QStringLiteral(""));

        horizontalLayout_5->addWidget(title_btn_menu);

        title_btn_min = new QPushButton(title_widget_btn);
        title_btn_min->setObjectName(QStringLiteral("title_btn_min"));
        sizePolicy2.setHeightForWidth(title_btn_min->sizePolicy().hasHeightForWidth());
        title_btn_min->setSizePolicy(sizePolicy2);
        title_btn_min->setMinimumSize(QSize(34, 26));
        title_btn_min->setMaximumSize(QSize(34, 26));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        title_btn_min->setFont(font2);
#ifndef QT_NO_TOOLTIP
        title_btn_min->setToolTip(QString::fromUtf8("\346\234\200\345\260\217\345\214\226"));
#endif // QT_NO_TOOLTIP
        title_btn_min->setStyleSheet(QLatin1String("QPushButton{background:url(:/Resource/Resources/icon_min_1.png);border:0;}\n"
"QPushButton::hover{background:url(:/Resource/Resources/icon_min_2.png);}\n"
"QPushButton::pressed{background:url(:/Resource/Resources/icon_min_3.png);}"));
        title_btn_min->setShortcut(QStringLiteral(""));

        horizontalLayout_5->addWidget(title_btn_min);

        title_btn_max = new QPushButton(title_widget_btn);
        title_btn_max->setObjectName(QStringLiteral("title_btn_max"));
        sizePolicy2.setHeightForWidth(title_btn_max->sizePolicy().hasHeightForWidth());
        title_btn_max->setSizePolicy(sizePolicy2);
        title_btn_max->setMinimumSize(QSize(34, 26));
        title_btn_max->setMaximumSize(QSize(34, 26));
        title_btn_max->setFont(font1);
#ifndef QT_NO_TOOLTIP
        title_btn_max->setToolTip(QString::fromUtf8("\346\234\200\345\244\247\345\214\226"));
#endif // QT_NO_TOOLTIP
        title_btn_max->setStyleSheet(QLatin1String("QPushButton{background:url(:/Resource/Resources/icon_max_1.png);border:0;}\n"
"QPushButton::hover{background:url(:/Resource/Resources/icon_max_2.png);}\n"
"QPushButton::pressed{background:url(:/Resource/Resources/icon_max_3.png);}"));
        title_btn_max->setShortcut(QStringLiteral(""));

        horizontalLayout_5->addWidget(title_btn_max);

        title_btn_close = new QPushButton(title_widget_btn);
        title_btn_close->setObjectName(QStringLiteral("title_btn_close"));
        sizePolicy2.setHeightForWidth(title_btn_close->sizePolicy().hasHeightForWidth());
        title_btn_close->setSizePolicy(sizePolicy2);
        title_btn_close->setMinimumSize(QSize(34, 26));
        title_btn_close->setMaximumSize(QSize(34, 26));
        title_btn_close->setFont(font2);
#ifndef QT_NO_TOOLTIP
        title_btn_close->setToolTip(QString::fromUtf8("\345\205\263\351\227\255"));
#endif // QT_NO_TOOLTIP
        title_btn_close->setStyleSheet(QLatin1String("QPushButton{background:url(:/Resource/Resources/icon_close_1.png);border:0;}\n"
"QPushButton::hover{background:url(:/Resource/Resources/icon_close_2.png);}\n"
"QPushButton::pressed{background:url(:/Resource/Resources/icon_close_3.png);}"));
        title_btn_close->setShortcut(QStringLiteral(""));

        horizontalLayout_5->addWidget(title_btn_close);


        verticalLayout->addWidget(title_widget_btn);

        widgetBase_GrayBackground = new QWidget(centralWidget);
        widgetBase_GrayBackground->setObjectName(QStringLiteral("widgetBase_GrayBackground"));
        widgetBase_GrayBackground->setStyleSheet(QLatin1String("background-color: rgb(220, 220, 220);\n"
"color:rgb(80, 80, 80);"));
        horizontalLayout_13 = new QHBoxLayout(widgetBase_GrayBackground);
        horizontalLayout_13->setSpacing(20);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_13->setContentsMargins(10, 10, 10, 10);
        ResWidget = new QWidget(widgetBase_GrayBackground);
        ResWidget->setObjectName(QStringLiteral("ResWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ResWidget->sizePolicy().hasHeightForWidth());
        ResWidget->setSizePolicy(sizePolicy3);
        ResWidget->setCursor(QCursor(Qt::ArrowCursor));
        ResWidget->setStyleSheet(QStringLiteral("QWidget#ResWidget{background:#cdcdcd;}"));
        verticalLayout_5 = new QVBoxLayout(ResWidget);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widgetBase_whiteBackground = new QWidget(ResWidget);
        widgetBase_whiteBackground->setObjectName(QStringLiteral("widgetBase_whiteBackground"));
        widgetBase_whiteBackground->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_3 = new QVBoxLayout(widgetBase_whiteBackground);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_Vectorview = new GraphicsView(widgetBase_whiteBackground);
        m_Vectorview->setObjectName(QStringLiteral("m_Vectorview"));
        m_Vectorview->setStyleSheet(QStringLiteral("background-color: rgb(230, 230, 230);"));

        verticalLayout_3->addWidget(m_Vectorview);


        verticalLayout_5->addWidget(widgetBase_whiteBackground);


        horizontalLayout_13->addWidget(ResWidget);

        widget_4 = new QWidget(widgetBase_GrayBackground);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(250, 0));
        widget_4->setMaximumSize(QSize(250, 16777215));
        widget_4->setCursor(QCursor(Qt::ArrowCursor));
        widget_4->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_1 = new QWidget(widget_4);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_1->sizePolicy().hasHeightForWidth());
        widget_1->setSizePolicy(sizePolicy4);
        widget_1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_6 = new QVBoxLayout(widget_1);
        verticalLayout_6->setSpacing(15);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(20, -1, 20, 10);
        btnReadFile = new QPushButton(widget_1);
        btnReadFile->setObjectName(QStringLiteral("btnReadFile"));
        sizePolicy.setHeightForWidth(btnReadFile->sizePolicy().hasHeightForWidth());
        btnReadFile->setSizePolicy(sizePolicy);
        btnReadFile->setMinimumSize(QSize(0, 50));
        btnReadFile->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnReadFile->setFont(font3);
        btnReadFile->setStyleSheet(QLatin1String("QPushButton{border-radius:5px; color:white; background: #00ade6;}\n"
"QPushButton::hover{background: #0079ba;}\n"
"QPushButton::pressed{background:#00ade6;}\n"
"QPushButton::disabled{background: #cccccc; color:#eeeeee;}"));
        btnReadFile->setText(QString::fromUtf8("\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271"));

        verticalLayout_6->addWidget(btnReadFile);

        ImageList = new QTableView(widget_1);
        ImageList->setObjectName(QStringLiteral("ImageList"));

        verticalLayout_6->addWidget(ImageList);

        btnSetup = new QPushButton(widget_1);
        btnSetup->setObjectName(QStringLiteral("btnSetup"));
        sizePolicy.setHeightForWidth(btnSetup->sizePolicy().hasHeightForWidth());
        btnSetup->setSizePolicy(sizePolicy);
        btnSetup->setMinimumSize(QSize(0, 50));
        btnSetup->setMaximumSize(QSize(16777215, 50));
        btnSetup->setFont(font3);
        btnSetup->setStyleSheet(QLatin1String("QPushButton{border-radius:5px;background: #16c4bb; color:white;}\n"
"QPushButton::hover{background: #11a39b;}\n"
"QPushButton::pressed{background: #0e7e78;}\n"
"QPushButton::disabled{background: #cccccc; color:#eeeeee;}"));
        btnSetup->setText(QString::fromUtf8("\345\217\202\346\225\260\350\256\276\347\275\256"));

        verticalLayout_6->addWidget(btnSetup);

        btnStart = new QPushButton(widget_1);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        sizePolicy.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy);
        btnStart->setMinimumSize(QSize(0, 50));
        btnStart->setMaximumSize(QSize(16777215, 50));
        btnStart->setFont(font3);
        btnStart->setStyleSheet(QLatin1String("QPushButton{border-radius: 3px;background: #f46666; color:white;}\n"
"QPushButton::hover{ background: #c55050; }\n"
"QPushButton::pressed{ background: #923c3c;}\n"
"QPushButton::disabled{ background: #cccccc; color:#eeeeee; }"));
        btnStart->setText(QString::fromUtf8("\345\274\200\345\247\213\346\213\274\346\216\245"));

        verticalLayout_6->addWidget(btnStart);

        btnSave = new QPushButton(widget_1);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMinimumSize(QSize(0, 50));
        btnSave->setMaximumSize(QSize(16777215, 50));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(46, 217, 77, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(238, 238, 238, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QBrush brush3(QColor(204, 204, 204, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        btnSave->setPalette(palette);
        btnSave->setFont(font3);
        btnSave->setStyleSheet(QLatin1String("QPushButton{border-radius:5px;background: #2ED94D; color:white;}\n"
"QPushButton::hover{background: #179C2F;}\n"
"QPushButton::pressed{background: #0F641E;}\n"
"QPushButton::disabled{background: #cccccc; color:#eeeeee;}"));
        btnSave->setText(QString::fromUtf8("\344\277\235\345\255\230\347\273\223\346\236\234"));

        verticalLayout_6->addWidget(btnSave);

        lblRes = new QLabel(widget_1);
        lblRes->setObjectName(QStringLiteral("lblRes"));
        sizePolicy.setHeightForWidth(lblRes->sizePolicy().hasHeightForWidth());
        lblRes->setSizePolicy(sizePolicy);
        lblRes->setMinimumSize(QSize(0, 80));
        lblRes->setMaximumSize(QSize(16777215, 80));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        lblRes->setFont(font4);
        lblRes->setStyleSheet(QStringLiteral("QLabel{background:#000000; border-radius:5px; color:white;}"));
        lblRes->setText(QStringLiteral(""));
        lblRes->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lblRes);


        verticalLayout_4->addWidget(widget_1);


        horizontalLayout_13->addWidget(widget_4);

        horizontalLayout_13->setStretch(0, 3);
        horizontalLayout_13->setStretch(1, 1);

        verticalLayout->addWidget(widgetBase_GrayBackground);


        horizontalLayout->addLayout(verticalLayout);

        ImageStischClass->setCentralWidget(centralWidget);

        retranslateUi(ImageStischClass);

        QMetaObject::connectSlotsByName(ImageStischClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageStischClass)
    {
        ImageStischClass->setWindowTitle(QApplication::translate("ImageStischClass", "ImageStisch", Q_NULLPTR));
        label->setText(QApplication::translate("ImageStischClass", "\346\230\276 \345\276\256 \345\233\276 \345\203\217 \346\213\274 \346\216\245  ", Q_NULLPTR));
        title_btn_menu->setText(QString());
        title_btn_min->setText(QString());
        title_btn_max->setText(QString());
        title_btn_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageStischClass: public Ui_ImageStischClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESTISCH_H
