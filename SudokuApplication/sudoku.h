#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include "ui_Sudoku.h"

class QTableView;
QT_FORWARD_DECLARE_CLASS(QTableView)
QT_FORWARD_DECLARE_CLASS(QAbstractTableModel)
QT_FORWARD_DECLARE_CLASS(QStandardItemModel)

class Sudoku : public QWidget, private Ui::Sudoku
{
    Q_OBJECT
public:
    explicit Sudoku(QWidget *parent = nullptr);
    void generateSudoku(QStandardItemModel* model, int checkedRadioButton);
    bool findEmptyCells(QStandardItemModel* model, int& row, int& column);
    bool checkValue(QStandardItemModel* model, int row, int column, int content);
    bool numberPartOfRowOrColumn(QStandardItemModel* model, int row, int column, int content);
    bool numberPartOfSmallGrid(QStandardItemModel* model, int row, int column, int content);
    void fillValues(QStandardItemModel* model);
    void fillDiagonalGrids(QStandardItemModel* model);
    bool fillRemaining(QStandardItemModel* model, int i, int j = 3);
    void removeEntries(QStandardItemModel* model);
    void setData(QStandardItemModel* model, int row, int column, QString num);
    void dyeGrid(QStandardItemModel* model);
    void setNotEditable(QStandardItemModel* model, bool solved);
    void copy(QStandardItemModel* from, QStandardItemModel* to);
    bool solveSudoku(bool fillGrid);

private slots:
    void generateSudoku();
    void solve();
    void validateUserEntry();
    void reconnect();

private:
    QStandardItemModel *mod;
    QItemSelectionModel *my;
};

#endif // SUDOKU_H
