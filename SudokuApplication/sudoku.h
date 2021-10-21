#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include "ui_Sudoku.h"

class QTableView;
QT_FORWARD_DECLARE_CLASS(QTableView)
QT_FORWARD_DECLARE_CLASS(QAbstractTableModel)

class Sudoku : public QWidget, private Ui::Sudoku
{
    Q_OBJECT
public:
    explicit Sudoku(QWidget *parent = nullptr);

signals:

private:
    QAbstractTableModel *model;
};

#endif // SUDOKU_H
