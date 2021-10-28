#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include "ui_Sudoku.h"
#include "mymodel.h"


class QTableView;
QT_FORWARD_DECLARE_CLASS(QTableView)
QT_FORWARD_DECLARE_CLASS(QAbstractTableModel)
QT_FORWARD_DECLARE_CLASS(QStandardItemModel)

class Sudoku : public QWidget, private Ui::Sudoku
{
    Q_OBJECT
public:
    explicit Sudoku(QWidget *parent = nullptr);
    void generateSudoku(int checkedRadioButton);
    bool findEmptyCells(int& row, int& column);
    bool checkValue(int row, int column, int content);
    bool numberPartOfRowOrColumn(int row, int column, int content);
    bool numberPartOfSmallGrid(int row, int column, int content);
    void fillValues();
    void fillDiagonalGrids();
    bool fillRemaining(int i, int j = 3);
    void removeEntries();
signals:

private slots:
    void generateSudoku();
    bool solveSudoku();

private:
    MyModel model;
    QStandardItemModel *mod;
};

#endif // SUDOKU_H
