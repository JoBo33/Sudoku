#include "sudoku.h"
#include <QtWidgets>
#include <QRandomGenerator>
#include <QPair>


/*
 * Sudoku difficulties:
 * easy : 45 filled cells
 * normal: 37 filled cells
 * hard: 30 filled cells
 */

Sudoku::Sudoku(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    mod = new QStandardItemModel(this);

    my = new QItemSelectionModel(mod);
    tableView->setModel(mod);
    tableView->setSelectionModel(my);

    QList<QStandardItem*> rowData { new QStandardItem ("")};
    for(int i =0; i<9; i++){

        mod->appendRow(rowData);
        mod->setVerticalHeaderItem(i, new QStandardItem(QString:: number(i+1) + ". Row"));
        if(i==0){continue;}
        mod->appendColumn(rowData);
        mod->setHorizontalHeaderItem(i, new QStandardItem(QString:: number(i+1) + ". Column"));

    }

    dyeGrid(mod);

    connect(pushButtonGenerate, SIGNAL (clicked()), this, SLOT(generateSudoku()));
    connect(pushButtonSolve,SIGNAL(clicked()), this, SLOT(solve()));
    //connect(tableView, SIGNAL(doubleClicked(const QModelIndex)), this, SLOT(reconnect()));
}

void Sudoku::solve(){
    solveSudoku(true);
}

void Sudoku::reconnect(){
    //connect(mod, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(validateUserEntry()));

}

void Sudoku::dyeGrid(QStandardItemModel * model){
    for(int i = 0; i < model->rowCount(); i++){
        for(int j = 0; j < 3; j++){
            if(i < 3 || i>5){
                model->setData(model->index(i,j),QBrush(Qt::lightGray),Qt::BackgroundRole);
            }
        }
    }
    for(int i = 3; i < 6; i++){
        for(int j = 3; j < 6; j++){
            model->setData(model->index(i,j),QBrush(Qt::lightGray),Qt::BackgroundRole);
        }
    }
    for(int i = 0; i < model->rowCount(); i++){
        for(int j = 6; j < model->columnCount(); j++){
            if(i < 3 || i>5){
                model->setData(model->index(i,j),QBrush(Qt::lightGray),Qt::BackgroundRole);
            }
        }
    }
}


void Sudoku::generateSudoku(){
    pushButtonSolve->setEnabled(true);
    for(int i = 0; i< mod->columnCount(); i++){
        for (int j = 0; j < mod->rowCount(); j++){
            mod->clearItemData(mod->index(j,i));
        }
    }

    fillValues(mod);

}

bool Sudoku::checkValue(QStandardItemModel* model, int row, int column, int content){
    bool isCorrect = true;
    if(numberPartOfRowOrColumn(model, row, column, content) || numberPartOfSmallGrid(model, row, column, content)){//||
            // !tableView->model()->data(tableView->model()->index(row,column)).isNull()){
        isCorrect = false;
    }

    return isCorrect;
}
bool Sudoku::findEmptyCells(QStandardItemModel* model, int& row, int& column)
{
    for (row = 0; row < model->rowCount(); row++)
        for (column = 0; column < model->columnCount(); column++)
            if (model->data(mod->index(row,column)) == "")
                return true;
    return false;
}
bool Sudoku::numberPartOfRowOrColumn(QStandardItemModel* model, int row, int column, int content){
    bool isPart = false;
    for(int i = 0; i < 9; i++){
        if(model->data(model->index(row,i)) == content ||
                model->data(model->index(i, column)) == content){
            isPart = true;
        }
    }
    return isPart;
}

bool Sudoku::numberPartOfSmallGrid(QStandardItemModel* model, int row, int column, int content){
    bool isPart = false;
    int startRow = row - row%3;
    int startColumn = column - column%3;
    for (int i = 0; i < 3; i++)
           for (int j = 0; j < 3; j++)
               if (model->data(model->index(i + startRow,j + startColumn)) == content)
                   isPart = true;;
    return isPart;
}

void Sudoku::setData(QStandardItemModel* model, int row, int column, QString num){
    model->setData(model->index(row,column), num, Qt::DisplayRole);
    model->item(row,column)->setTextAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(42);
    model->item(row,column)->setFont(font);
}

bool Sudoku::solveSudoku(bool fillGrid){
    int row, column;

    if(!findEmptyCells(mod, row, column)){
        return true;
    }

    for (int num = 1; num <= 9; num++)
        {

            // Check if looks promising
            if (checkValue(mod, row, column, num))
            {

                // Make tentative assignment
                setData(mod, row, column,  QString::number(num));
                // Return, if success
                if (solveSudoku(fillGrid)){
                    dyeGrid(mod);
                    if(!fillGrid){
                        mod->setData(mod->index(row,column), "", Qt::DisplayRole);
                    }
                    setNotEditable(mod, true);
                    return true;
                }

                // Failure, unmake & try again
                mod->setData(mod->index(row,column), "", Qt::DisplayRole);
            }
        }

        // This triggers backtracking
        return false;
}

void Sudoku::setNotEditable(QStandardItemModel* model, bool solved){
    for(int i = 0; i < model->rowCount(); i++){
        for(int j = 0; j < model->columnCount(); j++){
            if(model->data(model->index(i,j)) != ""){
                if(solved){
                    model->item(i,j)->setEditable(false);
                }
                else{
                    model->item(i,j)->setEnabled(false);
                }
            }
        }
    }
}

void Sudoku::fillValues(QStandardItemModel* model){
    fillDiagonalGrids(model);

    fillRemaining(model, 0);

    removeEntries(model);

    dyeGrid(model);

    setNotEditable(model, false);

    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(validateUserEntry()));
}


void Sudoku:: fillDiagonalGrids(QStandardItemModel* model){
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
                while(numberPartOfSmallGrid(model, row, col,content));

                setData(model, row, col,  QString::number(content));
            }
        }
    }

}

bool Sudoku::fillRemaining(QStandardItemModel* model, int i, int j){
    {
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
               if (checkValue(model, i, j, num))
               {
                   setData(model, i, j, QString::number(num));

                   if (fillRemaining(model, i, j+1))
                       return true;

                   model->setData(model->index(i, j), "", Qt::DisplayRole);
               }
           }
           return false;
       }
}

void Sudoku::removeEntries(QStandardItemModel* model){
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
        if(model->data(model->index(row, column)) != "")
        {
            setData(model, row, column, "");

        }
        else{
            i--;
        }
    }
}

void Sudoku::copy(QStandardItemModel* from, QStandardItemModel* to)
{
   to->clear();
   for (int i = 0 ; i < from->rowCount() ; i++)
   {
      to->appendRow(from->item(i)->clone());
   }
}


void Sudoku::validateUserEntry(){
    //disconnect(mod, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(validateUserEntry()));
    //int row = my->currentIndex().row();
    //int column = my->currentIndex().column();
    //int num = tableView->model()->data(mod->index(row, column)).toInt();
    //
    //if (solveSudoku(false)) //warum immer true?????????????????????????????????????
    //{
    //    //setData(mod, row, column,  QString::number(num));
    //    mod->setData(mod->index(row,column),QBrush(Qt::red),Qt::BackgroundRole);
    //}
    //else
    //{
    //    //setData(row, column,  QString::number(num));
    //    mod->setData(mod->index(row,column),QBrush(Qt::green),Qt::BackgroundRole);
    //}

}



