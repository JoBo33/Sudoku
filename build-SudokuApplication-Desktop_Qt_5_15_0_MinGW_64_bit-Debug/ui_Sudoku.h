/********************************************************************************
** Form generated from reading UI file 'Sudoku.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKU_H
#define UI_SUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sudoku
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Sudoku)
    {
        if (Sudoku->objectName().isEmpty())
            Sudoku->setObjectName(QString::fromUtf8("Sudoku"));
        Sudoku->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sudoku->sizePolicy().hasHeightForWidth());
        Sudoku->setSizePolicy(sizePolicy);
        Sudoku->setMinimumSize(QSize(600, 450));
        horizontalLayout = new QHBoxLayout(Sudoku);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(Sudoku);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Sudoku);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);


        verticalLayout->addWidget(groupBox);

        pushButton = new QPushButton(Sudoku);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(200, 300, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Sudoku);

        QMetaObject::connectSlotsByName(Sudoku);
    } // setupUi

    void retranslateUi(QWidget *Sudoku)
    {
        Sudoku->setWindowTitle(QCoreApplication::translate("Sudoku", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Sudoku", "Difficulty", nullptr));
        radioButton->setText(QCoreApplication::translate("Sudoku", "Easy", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Sudoku", "Normal", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Sudoku", "Hard", nullptr));
        pushButton->setText(QCoreApplication::translate("Sudoku", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sudoku: public Ui_Sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
