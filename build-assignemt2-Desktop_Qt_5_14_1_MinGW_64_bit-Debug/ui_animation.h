/********************************************************************************
** Form generated from reading UI file 'animation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATION_H
#define UI_ANIMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_animation
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *animation)
    {
        if (animation->objectName().isEmpty())
            animation->setObjectName(QString::fromUtf8("animation"));
        animation->resize(800, 600);
        centralwidget = new QWidget(animation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(70, 81, 621, 431));
        animation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(animation);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        animation->setMenuBar(menubar);
        statusbar = new QStatusBar(animation);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        animation->setStatusBar(statusbar);

        retranslateUi(animation);

        QMetaObject::connectSlotsByName(animation);
    } // setupUi

    void retranslateUi(QMainWindow *animation)
    {
        animation->setWindowTitle(QCoreApplication::translate("animation", "animation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class animation: public Ui_animation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATION_H
