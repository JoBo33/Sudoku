
#include "sudoku.h"
#include <QtWidgets>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;

    Sudoku sudo;
    window.setCentralWidget(&sudo);

    window.show();


    return app.exec();
}
