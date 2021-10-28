#include "sudoku.h"
#include <QtWidgets>
#include <QRandomGenerator>
#include <QPair>


/*
 * Sudoku difficulties:
 * easy : 45 cells filled
 * normal: 37 cells filled
 * hard: 30 cells filled
 */

Sudoku::Sudoku(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    mod = new QStandardItemModel(this);
    tableView->setModel(mod);

    QList<QStandardItem*> rowData { new QStandardItem ("")};
    for(int i =0; i<9; i++){

        mod->appendRow(rowData);
        mod->setVerticalHeaderItem(i, new QStandardItem(QString:: number(i+1) + ". Row"));
        if(i==0){continue;}
        mod->appendColumn(rowData);
        mod->setHorizontalHeaderItem(i, new QStandardItem(QString:: number(i+1) + ". Column"));

    }

    connect(pushButtonGenerate, SIGNAL (clicked()), this, SLOT(generateSudoku()));
    connect(pushButtonSolve,SIGNAL(clicked()), this, SLOT(solveSudoku()));
}

void Sudoku::generateSudoku(){
    pushButtonSolve->setEnabled(true);
    for(int i = 0; i< mod->columnCount(); i++){
        for (int j = 0; j < mod->rowCount(); j++){
            mod->clearItemData(mod->index(j,i));
        }
    }

    fillValues();

}

bool Sudoku::checkValue(int row, int column, int content){
    bool isCorrect = true;
    if(numberPartOfRowOrColumn(row, column, content) || numberPartOfSmallGrid(row, column, content)){//||
            // !tableView->model()->data(tableView->model()->index(row,column)).isNull()){
        isCorrect = false;
    }

    return isCorrect;
}
bool Sudoku::findEmptyCells(int& row, int& column)
{
    for (row = 0; row < mod->rowCount(); row++)
        for (column = 0; column < mod->columnCount(); column++)
            if (tableView->model()->data(mod->index(row,column)) == "")
                return true;
    return false;
}
bool Sudoku::numberPartOfRowOrColumn(int row, int column, int content){
    bool isPart = false;
    for(int i = 0; i < 9; i++){
        if(tableView->model()->data(tableView->model()->index(row,i)) == content ||
                tableView->model()->data(tableView->model()->index(i, column)) == content){
            isPart = true;
        }
    }
    return isPart;
}

bool Sudoku::numberPartOfSmallGrid(int row, int column, int content){
    bool isPart = false;
    int startRow = row - row%3;
    int startColumn = column - column%3;
    for (int i = 0; i < 3; i++)
           for (int j = 0; j < 3; j++)
               if (tableView->model()->data(mod->index(i + startRow,j + startColumn)) == content)
                   isPart = true;;
    return isPart;
}


bool Sudoku::solveSudoku(){
    int row, column;

    if(!findEmptyCells(row, column)){
        return true;
    }

    for (int num = 1; num <= 9; num++)
        {

            // Check if looks promising
            if (checkValue(row, column, num))
            {

                // Make tentative assignment
                tableView->model()->setData(tableView->model()->index(row,column), num, Qt::DisplayRole);

                // Return, if success
                if (solveSudoku())
                    return true;

                // Failure, unmake & try again
                tableView->model()->setData(tableView->model()->index(row,column), "", Qt::DisplayRole);
            }
        }

        // This triggers backtracking
        return false;
}

void Sudoku::fillValues(){
    fillDiagonalGrids();

    fillRemaining(0);
    //solveSudoku();

    removeEntries();
}


void Sudoku:: fillDiagonalGrids(){
    int content;
    // c = top-left corner of diagonal grids
    for(int c = 0; c < 9; c+=3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int row = c + i;
                int col = c + j;
                do{
                content = QRandomGenerator::global()->bounded(1, 10);
                }
                while(numberPartOfSmallGrid(row, col,content));

                tableView->model()->setData(tableView->model()->index(row,col), content, Qt::DisplayRole);
            }
        }
    }

}

bool Sudoku::fillRemaining(int i, int j){
    {
           //  System.out.println(i+" "+j);
           if (j>=9 && i<8)
           {
               i = i + 1;
               j = 0;
           }
           if (i>=9 && j>=9)
               return true;

           if (i < 3)
           {
               if (j < 3)
                   j = 3;
           }
           else if (i < 6)
           {
               if (j==(int)(i/3)*3)
                   j =  j + 3;
           }
           else
           {
               if (j == 6)
               {
                   i = i + 1;
                   j = 0;
                   if (i>=9)
                       return true;
               }
           }

           for (int num = 1; num<=9; num++)
           {
               if (checkValue(i, j, num))
               {
                   tableView->model()->setData(tableView->model()->index(i, j), num, Qt::DisplayRole);
                   if (fillRemaining(i, j+1))
                       return true;

                   tableView->model()->setData(tableView->model()->index(i, j), "", Qt::DisplayRole);
               }
           }
           return false;
       }
}

void Sudoku::removeEntries(){
    int filledCells = 0;
    if(radioButtonEasy->isChecked()){
        filledCells = 45;
    }
    else if(radioButtonNormal->isChecked()){
        filledCells = 37;
    }
    else if(radioButtonHard->isChecked()){
        filledCells = 30;
    }

    // zu remove umwandeln
    for(int i = 0; i<81-filledCells; i++){
        int row = QRandomGenerator::global()->bounded(0, 9);
        int column = QRandomGenerator::global()->bounded(0, 9);
        if(tableView->model()->data(mod->index(row, column)) != "")
        {
            tableView->model()->setData(tableView->model()->index(row,column), "", Qt::DisplayRole);
        }
        else{
            i--;
        }
    }
}





