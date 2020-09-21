/********************************************************************************
** Form generated from reading UI file 'ReminderWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERWIDGET_H
#define UI_REMINDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReminderWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *ReminderWidget)
    {
        if (ReminderWidget->objectName().isEmpty())
            ReminderWidget->setObjectName(QStringLiteral("ReminderWidget"));
        ReminderWidget->resize(300, 50);
        QFont font;
        font.setPointSize(9);
        ReminderWidget->setFont(font);
        ReminderWidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        verticalLayout = new QVBoxLayout(ReminderWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ReminderWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(300, 50));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(ReminderWidget);

        QMetaObject::connectSlotsByName(ReminderWidget);
    } // setupUi

    void retranslateUi(QWidget *ReminderWidget)
    {
        ReminderWidget->setWindowTitle(QApplication::translate("ReminderWidget", "Form", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReminderWidget: public Ui_ReminderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERWIDGET_H
