#include "mainwindow.h"
#include <QApplication>
#include <Mysql.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    create_database();
    open();
    delete_all();
    create_table();

    return a.exec();
}
