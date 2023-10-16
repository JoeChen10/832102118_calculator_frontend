#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlQuery>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <qsqldatabase.h>
void open(void);
void find_table(void);
void find_line(int num);
void find_line(void);
void add(void);
void create_database(void);
void create_table(void);
void add_table(QString s);
void delete_table(QString s);
void delete_all(void);
void modify_data(int id);
extern QSqlDatabase database;//建立套接字，建议设置从全局变量。
extern int table_size;
extern QString line_data;
#endif // MYSQL_H
