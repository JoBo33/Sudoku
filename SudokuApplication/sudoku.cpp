#include "sudoku.h"
#include <QtWidgets>
#include <QRandomGenerator>
#include <QPair>


/*
 * Sudoku difficulties:
 * easy : 38 cells filled
 * normal: 30 cells filled
 * hard: 23 cells filled
 */

Sudoku::Sudoku(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    //QAbstractItemModel *mod = tableView->model();
    //mod->insertColumns(mod->columnCount(),9);
    //mod->insertRows(mod->rowCount(),9);
    //tableView->setModel(mod);
    model = new QStandardItemModel();
    tableView->setModel(model);
    QList<QStandardItem*> rowData { new QStandardItem ("")};
    for(int i =0; i<8; i++){
        model->appendRow(rowData);
        model->appendColumn(rowData);
        model->setHorizontalHeaderItem(i, new QStandardItem(QString:: number(i+1) + ". Column"));
        model->setVerticalHeaderItem(i, new QStandardItem(QString:: number(i+1) + ". Row"));
    }

    connect(pushButtonGenerate, SIGNAL (clicked()), this, SLOT(generateSudoku()));
}

void Sudoku::generateSudoku(){
    int filledCells = 0;
    if(radioButtonEasy->isChecked()){
        filledCells = 38;
    }
    else if(radioButtonNormal->isChecked()){
        filledCells = 30;
    }
    else if(radioButtonNormal->isChecked()){
        filledCells = 23;
    }
    for(int i = 0; i<filledCells; i++){
        int begin = 1;
        int end = 9;
        //std::seed_seq sseq(&begin, &end);
        int row = QRandomGenerator::global()->bounded(1, 9);
        int column = QRandomGenerator::global()->bounded(1, 9);
        int content = QRandomGenerator::global()->bounded(1, 9);

        //QRandomGenerator rnd(sseq);
        //int row = rnd.generate();
        //int column = rnd.generate();
        //int content = rnd.generate();

        tableView->model()->index(row, column).data(content);
    }
}


















