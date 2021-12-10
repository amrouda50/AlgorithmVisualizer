/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QFrame *line_2;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QSlider *horizontalSlider;
    QLabel *label;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;
    QPushButton *addToDatasetButton;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *clearDatasetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 624);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(220, 50, 121, 20));
        QFont font;
        font.setPointSize(10);
        checkBox->setFont(font);
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(350, 50, 151, 20));
        checkBox_2->setFont(font);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(190, 0, 20, 541));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(0, 0, 201, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(10);
        commandLinkButton->setFont(font1);
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(0, 40, 201, 41));
        commandLinkButton_2->setFont(font1);
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName(QString::fromUtf8("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(0, 80, 201, 41));
        commandLinkButton_3->setFont(font1);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(520, 50, 211, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 10, 131, 31));
        label->setFont(font);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(220, 90, 561, 351));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(222, 470, 111, 31));
        lineEdit->setDragEnabled(false);
        addToDatasetButton = new QPushButton(centralwidget);
        addToDatasetButton->setObjectName(QString::fromUtf8("addToDatasetButton"));
        addToDatasetButton->setGeometry(QRect(340, 470, 121, 31));
        addToDatasetButton->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(470, 470, 221, 31));
        comboBox->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(700, 470, 81, 31));
        pushButton_2->setFont(font);
        clearDatasetButton = new QPushButton(centralwidget);
        clearDatasetButton->setObjectName(QString::fromUtf8("clearDatasetButton"));
        clearDatasetButton->setGeometry(QRect(340, 510, 121, 31));
        clearDatasetButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 815, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Show values", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Show animation", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "Visualizer", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("MainWindow", "Import/Export", nullptr));
        commandLinkButton_3->setText(QCoreApplication::translate("MainWindow", "Tutorial", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Animation speed", nullptr));
        addToDatasetButton->setText(QCoreApplication::translate("MainWindow", "Add to dataset", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select algorithm", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Insertion sort", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Selection sort", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Bubble sort", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Quick sort", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Merge sort", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Shell sort", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Go!", nullptr));
        clearDatasetButton->setText(QCoreApplication::translate("MainWindow", "Clear dataset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
