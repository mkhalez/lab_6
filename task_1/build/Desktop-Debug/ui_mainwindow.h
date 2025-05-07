/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *resultLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *explicitEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *populationEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *GDPEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *firstLetterEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *warEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *firstTaxEdit;
    QLineEdit *secondTexEdit;
    QLineEdit *thirdTaxEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *pointerEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *userEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *refEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(638, 470);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(540, 0, 81, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 220, 491, 28));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        resultLineEdit = new QLineEdit(layoutWidget);
        resultLineEdit->setObjectName("resultLineEdit");
        resultLineEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(resultLineEdit);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 260, 491, 28));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        explicitEdit = new QLineEdit(layoutWidget1);
        explicitEdit->setObjectName("explicitEdit");
        explicitEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(explicitEdit);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 0, 518, 200));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        populationEdit = new QLineEdit(layoutWidget2);
        populationEdit->setObjectName("populationEdit");

        horizontalLayout->addWidget(populationEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        GDPEdit = new QLineEdit(layoutWidget2);
        GDPEdit->setObjectName("GDPEdit");

        horizontalLayout_2->addWidget(GDPEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        firstLetterEdit = new QLineEdit(layoutWidget2);
        firstLetterEdit->setObjectName("firstLetterEdit");

        horizontalLayout_3->addWidget(firstLetterEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        warEdit = new QLineEdit(layoutWidget2);
        warEdit->setObjectName("warEdit");

        horizontalLayout_4->addWidget(warEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        nameEdit = new QLineEdit(layoutWidget2);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout_5->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        firstTaxEdit = new QLineEdit(layoutWidget2);
        firstTaxEdit->setObjectName("firstTaxEdit");

        horizontalLayout_6->addWidget(firstTaxEdit);

        secondTexEdit = new QLineEdit(layoutWidget2);
        secondTexEdit->setObjectName("secondTexEdit");

        horizontalLayout_6->addWidget(secondTexEdit);

        thirdTaxEdit = new QLineEdit(layoutWidget2);
        thirdTaxEdit->setObjectName("thirdTaxEdit");

        horizontalLayout_6->addWidget(thirdTaxEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 300, 491, 28));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        horizontalLayout_9->addWidget(label_9);

        pointerEdit = new QLineEdit(widget);
        pointerEdit->setObjectName("pointerEdit");
        pointerEdit->setReadOnly(true);

        horizontalLayout_9->addWidget(pointerEdit);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(20, 340, 491, 28));
        horizontalLayout_10 = new QHBoxLayout(widget1);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget1);
        label_10->setObjectName("label_10");

        horizontalLayout_10->addWidget(label_10);

        userEdit = new QLineEdit(widget1);
        userEdit->setObjectName("userEdit");

        horizontalLayout_10->addWidget(userEdit);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(20, 380, 491, 28));
        horizontalLayout_11 = new QHBoxLayout(widget2);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget2);
        label_11->setObjectName("label_11");

        horizontalLayout_11->addWidget(label_11);

        refEdit = new QLineEdit(widget2);
        refEdit->setObjectName("refEdit");

        horizontalLayout_11->addWidget(refEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 638, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add state", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "state with line initialization", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "sate with explicit initialization", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "population:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "GDP:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "first letter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "in war:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "name:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "type texes", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "state with pointer", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "user input:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "state with ref:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
