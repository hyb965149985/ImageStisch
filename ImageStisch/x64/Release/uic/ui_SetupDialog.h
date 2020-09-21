/********************************************************************************
** Form generated from reading UI file 'SetupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPDIALOG_H
#define UI_SETUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QRadioButton *rbtn8z1;
    QRadioButton *rbtn8z3;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_13;
    QComboBox *cboxFuse;
    QComboBox *cboxFeature;
    QLabel *label_16;
    QLabel *label_10;
    QPushButton *btnMore;
    QRadioButton *rbtn8z2;
    QLabel *label_17;
    QLabel *label_14;
    QLabel *label_18;
    QRadioButton *rbtn5Yes;
    QSpinBox *sboxRegion;
    QRadioButton *rbtn1z2;
    QRadioButton *rbtn1z1;
    QRadioButton *rbtn1z3;
    QLabel *label_2;
    QRadioButton *rbtn5No;
    QRadioButton *rbtn6No;
    QRadioButton *rbtn6Yes;
    QRadioButton *rbtn7No;
    QRadioButton *rbtn7Yes;
    QWidget *qwidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnConfirm;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *SetupDialog)
    {
        if (SetupDialog->objectName().isEmpty())
            SetupDialog->setObjectName(QStringLiteral("SetupDialog"));
        SetupDialog->resize(625, 568);
        SetupDialog->setStyleSheet(QStringLiteral("QDialog{background: #555555;}"));
        verticalLayout = new QVBoxLayout(SetupDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetupDialog);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(0, 500));
        widget_2->setMaximumSize(QSize(16777215, 800));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        rbtn8z1 = new QRadioButton(widget_2);
        rbtn8z1->setObjectName(QStringLiteral("rbtn8z1"));
        rbtn8z1->setGeometry(QRect(280, 420, 89, 16));
        rbtn8z3 = new QRadioButton(widget_2);
        rbtn8z3->setObjectName(QStringLiteral("rbtn8z3"));
        rbtn8z3->setGeometry(QRect(490, 420, 89, 16));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(60, 60, 171, 31));
        label_12->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
"\n"
""));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 460, 181, 32));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 160, 171, 31));
        label_11->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 460, 171, 31));
        label_15->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(60, 210, 171, 31));
        label_13->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        cboxFuse = new QComboBox(widget_2);
        cboxFuse->setObjectName(QStringLiteral("cboxFuse"));
        cboxFuse->setGeometry(QRect(280, 210, 186, 32));
        cboxFuse->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;  \n"
"    min-width: 9em;  \n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
" "));
        cboxFeature = new QComboBox(widget_2);
        cboxFeature->setObjectName(QStringLiteral("cboxFeature"));
        cboxFeature->setGeometry(QRect(280, 110, 186, 32));
        cboxFeature->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;  \n"
"    min-width: 9em;  \n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
" "));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(60, 410, 171, 31));
        label_16->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 110, 171, 31));
        label_10->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        btnMore = new QPushButton(widget_2);
        btnMore->setObjectName(QStringLiteral("btnMore"));
        btnMore->setGeometry(QRect(461, 460, 31, 32));
        QFont font;
        font.setPointSize(4);
        btnMore->setFont(font);
        btnMore->setStyleSheet(QStringLiteral(""));
        rbtn8z2 = new QRadioButton(widget_2);
        rbtn8z2->setObjectName(QStringLiteral("rbtn8z2"));
        rbtn8z2->setGeometry(QRect(380, 420, 89, 16));
        label_17 = new QLabel(widget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(60, 310, 171, 31));
        label_17->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(60, 260, 171, 31));
        label_14->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(60, 360, 171, 31));
        label_18->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:5px;\n"
"color:gray; \n"
"background: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:1px solid rgb(110, 110, 110);\n"
"}\n"
""));
        rbtn5Yes = new QRadioButton(widget_2);
        rbtn5Yes->setObjectName(QStringLiteral("rbtn5Yes"));
        rbtn5Yes->setGeometry(QRect(280, 270, 71, 16));
        sboxRegion = new QSpinBox(widget_2);
        sboxRegion->setObjectName(QStringLiteral("sboxRegion"));
        sboxRegion->setGeometry(QRect(280, 160, 81, 32));
        QFont font1;
        font1.setPointSize(13);
        sboxRegion->setFont(font1);
        sboxRegion->setAlignment(Qt::AlignCenter);
        rbtn1z2 = new QRadioButton(widget_2);
        rbtn1z2->setObjectName(QStringLiteral("rbtn1z2"));
        rbtn1z2->setGeometry(QRect(380, 70, 89, 16));
        rbtn1z1 = new QRadioButton(widget_2);
        rbtn1z1->setObjectName(QStringLiteral("rbtn1z1"));
        rbtn1z1->setGeometry(QRect(280, 70, 89, 16));
        rbtn1z3 = new QRadioButton(widget_2);
        rbtn1z3->setObjectName(QStringLiteral("rbtn1z3"));
        rbtn1z3->setGeometry(QRect(480, 70, 89, 16));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 10, 201, 41));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        rbtn5No = new QRadioButton(widget_2);
        rbtn5No->setObjectName(QStringLiteral("rbtn5No"));
        rbtn5No->setGeometry(QRect(380, 270, 71, 16));
        rbtn6No = new QRadioButton(widget_2);
        rbtn6No->setObjectName(QStringLiteral("rbtn6No"));
        rbtn6No->setGeometry(QRect(380, 320, 71, 16));
        rbtn6Yes = new QRadioButton(widget_2);
        rbtn6Yes->setObjectName(QStringLiteral("rbtn6Yes"));
        rbtn6Yes->setGeometry(QRect(280, 320, 71, 16));
        rbtn7No = new QRadioButton(widget_2);
        rbtn7No->setObjectName(QStringLiteral("rbtn7No"));
        rbtn7No->setGeometry(QRect(380, 370, 71, 16));
        rbtn7Yes = new QRadioButton(widget_2);
        rbtn7Yes->setObjectName(QStringLiteral("rbtn7Yes"));
        rbtn7Yes->setGeometry(QRect(280, 370, 71, 16));

        verticalLayout_2->addWidget(widget_2);

        qwidget1 = new QWidget(widget);
        qwidget1->setObjectName(QStringLiteral("qwidget1"));
        qwidget1->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        horizontalLayout = new QHBoxLayout(qwidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnConfirm = new QPushButton(qwidget1);
        btnConfirm->setObjectName(QStringLiteral("btnConfirm"));
        btnConfirm->setMinimumSize(QSize(100, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        btnConfirm->setFont(font3);
        btnConfirm->setStyleSheet(QLatin1String("QPushButton{border-radius:5px; color:white; background: #00ade6;}\n"
"QPushButton::hover{background: #0079ba;}\n"
"QPushButton::pressed{background:#00ade6;}\n"
"QPushButton::disabled{background: #cccccc; color:#eeeeee;}"));

        horizontalLayout->addWidget(btnConfirm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(qwidget1);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setEnabled(true);
        btnCancel->setMinimumSize(QSize(100, 35));
        btnCancel->setFont(font3);
        btnCancel->setStyleSheet(QLatin1String("QPushButton{border-radius:5px; color:white; background: #00ade6;}\n"
"QPushButton::hover{background: #0079ba;}\n"
"QPushButton::pressed{background:#00ade6;}\n"
"QPushButton::disabled{background: #cccccc; color:#eeeeee;}"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(qwidget1);


        verticalLayout->addWidget(widget);


        retranslateUi(SetupDialog);

        QMetaObject::connectSlotsByName(SetupDialog);
    } // setupUi

    void retranslateUi(QDialog *SetupDialog)
    {
        SetupDialog->setWindowTitle(QApplication::translate("SetupDialog", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        rbtn8z1->setText(QApplication::translate("SetupDialog", ".jpg", Q_NULLPTR));
        rbtn8z3->setText(QApplication::translate("SetupDialog", ".bmp", Q_NULLPTR));
        label_12->setText(QApplication::translate("SetupDialog", "  \345\233\276\345\203\217\346\216\222\345\210\227\346\226\271\345\274\217", Q_NULLPTR));
        label->setText(QApplication::translate("SetupDialog", "../result/", Q_NULLPTR));
        label_11->setText(QApplication::translate("SetupDialog", "  \345\242\236\351\225\277\345\214\272\345\237\237\345\210\235\345\247\213\345\200\274", Q_NULLPTR));
        label_15->setText(QApplication::translate("SetupDialog", "  \350\276\223\345\207\272\350\267\257\345\276\204", Q_NULLPTR));
        label_13->setText(QApplication::translate("SetupDialog", "  \345\233\276\345\203\217\350\236\215\345\220\210\347\256\227\346\263\225", Q_NULLPTR));
        cboxFuse->clear();
        cboxFuse->insertItems(0, QStringList()
         << QApplication::translate("SetupDialog", "\350\246\206\347\233\226\350\236\215\345\220\210\347\256\227\346\263\225", Q_NULLPTR)
         << QApplication::translate("SetupDialog", "\345\235\207\345\200\274\350\236\215\345\220\210\347\256\227\346\263\225", Q_NULLPTR)
         << QApplication::translate("SetupDialog", "\346\234\200\345\244\247\345\200\274\350\236\215\345\220\210\347\256\227\346\263\225(\346\216\250\350\215\220)", Q_NULLPTR)
        );
        cboxFeature->clear();
        cboxFeature->insertItems(0, QStringList()
         << QApplication::translate("SetupDialog", "Sift\347\256\227\345\255\220(error)", Q_NULLPTR)
         << QApplication::translate("SetupDialog", "Surf\347\256\227\345\255\220", Q_NULLPTR)
         << QApplication::translate("SetupDialog", "Fast\347\256\227\345\255\220", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("SetupDialog", "  \350\276\223\345\207\272\346\240\274\345\274\217", Q_NULLPTR));
        label_10->setText(QApplication::translate("SetupDialog", "  \347\211\271\345\276\201\347\202\271\346\217\220\345\217\226\347\256\227\345\255\220", Q_NULLPTR));
        btnMore->setText(QApplication::translate("SetupDialog", "\302\267\302\267\302\267\302\267", Q_NULLPTR));
        rbtn8z2->setText(QApplication::translate("SetupDialog", ".png", Q_NULLPTR));
        label_17->setText(QApplication::translate("SetupDialog", "  \345\233\276\345\203\217\345\242\236\345\274\272", Q_NULLPTR));
        label_14->setText(QApplication::translate("SetupDialog", "  GPU", Q_NULLPTR));
        label_18->setText(QApplication::translate("SetupDialog", "  \344\272\256\345\272\246\345\235\207\350\241\241", Q_NULLPTR));
        rbtn5Yes->setText(QApplication::translate("SetupDialog", "\346\230\257", Q_NULLPTR));
        rbtn1z2->setText(QApplication::translate("SetupDialog", "\344\273\216\344\270\212\345\210\260\344\270\213", Q_NULLPTR));
        rbtn1z1->setText(QApplication::translate("SetupDialog", "\350\207\252\347\224\261\346\216\222\345\210\227", Q_NULLPTR));
        rbtn1z3->setText(QApplication::translate("SetupDialog", "\344\273\216\345\267\246\345\210\260\345\217\263", Q_NULLPTR));
        label_2->setText(QApplication::translate("SetupDialog", "\345\217\202 \346\225\260 \350\256\276 \347\275\256", Q_NULLPTR));
        rbtn5No->setText(QApplication::translate("SetupDialog", "\345\220\246", Q_NULLPTR));
        rbtn6No->setText(QApplication::translate("SetupDialog", "\345\220\246", Q_NULLPTR));
        rbtn6Yes->setText(QApplication::translate("SetupDialog", "\346\230\257", Q_NULLPTR));
        rbtn7No->setText(QApplication::translate("SetupDialog", "\345\220\246", Q_NULLPTR));
        rbtn7Yes->setText(QApplication::translate("SetupDialog", "\346\230\257", Q_NULLPTR));
        btnConfirm->setText(QApplication::translate("SetupDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("SetupDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetupDialog: public Ui_SetupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPDIALOG_H
