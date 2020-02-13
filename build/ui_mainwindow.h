/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *fieldLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *FNField;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *LNField;
    QLabel *label;
    QLineEdit *AgeField;
    QLineEdit *UserNumField;
    QLineEdit *EmpNumField;
    QVBoxLayout *buttonLayout;
    QCheckBox *EmpCheckBox;
    QPushButton *SearchUserButton;
    QPushButton *CreateUserButton;
    QVBoxLayout *consoleLayout;
    QListWidget *taskOutput;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        fieldLayout = new QGridLayout();
        fieldLayout->setObjectName(QStringLiteral("fieldLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        fieldLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        fieldLayout->addWidget(label_4, 6, 0, 1, 1);

        FNField = new QLineEdit(centralwidget);
        FNField->setObjectName(QStringLiteral("FNField"));

        fieldLayout->addWidget(FNField, 1, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        fieldLayout->addWidget(label_3, 4, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        fieldLayout->addWidget(label_5, 8, 0, 1, 1);

        LNField = new QLineEdit(centralwidget);
        LNField->setObjectName(QStringLiteral("LNField"));

        fieldLayout->addWidget(LNField, 3, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        fieldLayout->addWidget(label, 0, 0, 1, 1);

        AgeField = new QLineEdit(centralwidget);
        AgeField->setObjectName(QStringLiteral("AgeField"));

        fieldLayout->addWidget(AgeField, 5, 0, 1, 1);

        UserNumField = new QLineEdit(centralwidget);
        UserNumField->setObjectName(QStringLiteral("UserNumField"));

        fieldLayout->addWidget(UserNumField, 7, 0, 1, 1);

        EmpNumField = new QLineEdit(centralwidget);
        EmpNumField->setObjectName(QStringLiteral("EmpNumField"));

        fieldLayout->addWidget(EmpNumField, 9, 0, 1, 1);


        gridLayout_2->addLayout(fieldLayout, 1, 0, 1, 1);

        buttonLayout = new QVBoxLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        EmpCheckBox = new QCheckBox(centralwidget);
        EmpCheckBox->setObjectName(QStringLiteral("EmpCheckBox"));

        buttonLayout->addWidget(EmpCheckBox);

        SearchUserButton = new QPushButton(centralwidget);
        SearchUserButton->setObjectName(QStringLiteral("SearchUserButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SearchUserButton->sizePolicy().hasHeightForWidth());
        SearchUserButton->setSizePolicy(sizePolicy1);
        SearchUserButton->setAutoDefault(false);
        SearchUserButton->setFlat(false);

        buttonLayout->addWidget(SearchUserButton);

        CreateUserButton = new QPushButton(centralwidget);
        CreateUserButton->setObjectName(QStringLiteral("CreateUserButton"));
        sizePolicy1.setHeightForWidth(CreateUserButton->sizePolicy().hasHeightForWidth());
        CreateUserButton->setSizePolicy(sizePolicy1);
        CreateUserButton->setFlat(false);

        buttonLayout->addWidget(CreateUserButton);


        gridLayout_2->addLayout(buttonLayout, 1, 1, 1, 1);

        consoleLayout = new QVBoxLayout();
        consoleLayout->setSpacing(6);
        consoleLayout->setObjectName(QStringLiteral("consoleLayout"));
        consoleLayout->setSizeConstraint(QLayout::SetMinimumSize);
        taskOutput = new QListWidget(centralwidget);
        taskOutput->setObjectName(QStringLiteral("taskOutput"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(taskOutput->sizePolicy().hasHeightForWidth());
        taskOutput->setSizePolicy(sizePolicy2);

        consoleLayout->addWidget(taskOutput);


        gridLayout_2->addLayout(consoleLayout, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        SearchUserButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Last Name", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "User Number", nullptr));
        FNField->setPlaceholderText(QApplication::translate("MainWindow", "First Name Field", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Age", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Employee Number", nullptr));
        LNField->setPlaceholderText(QApplication::translate("MainWindow", "Last Name Field", nullptr));
        label->setText(QApplication::translate("MainWindow", "First Name", nullptr));
        AgeField->setPlaceholderText(QApplication::translate("MainWindow", "Age Field", nullptr));
        UserNumField->setPlaceholderText(QApplication::translate("MainWindow", "User Identification Number Field", nullptr));
        EmpNumField->setPlaceholderText(QApplication::translate("MainWindow", "Employee Number Identification Field", nullptr));
        EmpCheckBox->setText(QApplication::translate("MainWindow", "Employee", nullptr));
        SearchUserButton->setText(QApplication::translate("MainWindow", "Search User", nullptr));
        CreateUserButton->setText(QApplication::translate("MainWindow", "Create User", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
