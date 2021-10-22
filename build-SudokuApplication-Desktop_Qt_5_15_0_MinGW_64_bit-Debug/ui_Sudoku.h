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
    QRadioButton *radioButtonEasy;
    QRadioButton *radioButtonNormal;
    QRadioButton *radioButtonHard;
    QPushButton *pushButtonGenerate;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Sudoku)
    {
        if (Sudoku->objectName().isEmpty())
            Sudoku->setObjectName(QString::fromUtf8("Sudoku"));
        Sudoku->resize(732, 450);
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
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setMinimumSectionSize(20);
        tableView->horizontalHeader()->setDefaultSectionSize(65);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setMinimumSectionSize(20);
        tableView->verticalHeader()->setDefaultSectionSize(65);

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
        radioButtonEasy = new QRadioButton(groupBox);
        radioButtonEasy->setObjectName(QString::fromUtf8("radioButtonEasy"));
        radioButtonEasy->setChecked(true);

        verticalLayout_2->addWidget(radioButtonEasy);

        radioButtonNormal = new QRadioButton(groupBox);
        radioButtonNormal->setObjectName(QString::fromUtf8("radioButtonNormal"));

        verticalLayout_2->addWidget(radioButtonNormal);

        radioButtonHard = new QRadioButton(groupBox);
        radioButtonHard->setObjectName(QString::fromUtf8("radioButtonHard"));

        verticalLayout_2->addWidget(radioButtonHard);


        verticalLayout->addWidget(groupBox);

        pushButtonGenerate = new QPushButton(Sudoku);
        pushButtonGenerate->setObjectName(QString::fromUtf8("pushButtonGenerate"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(pushButtonGenerate->sizePolicy().hasHeightForWidth());
        pushButtonGenerate->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pushButtonGenerate);

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
        radioButtonEasy->setText(QCoreApplication::translate("Sudoku", "Easy", nullptr));
        radioButtonNormal->setText(QCoreApplication::translate("Sudoku", "Normal", nullptr));
        radioButtonHard->setText(QCoreApplication::translate("Sudoku", "Hard", nullptr));
        pushButtonGenerate->setText(QCoreApplication::translate("Sudoku", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sudoku: public Ui_Sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
