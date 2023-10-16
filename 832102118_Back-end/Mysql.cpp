#include <Mysql.h>

QSqlDatabase database;
int table_size = 0;
QString line_data;
void create_database()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database.setDatabaseName("MyDataBase.db");
    }
}

void open()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "Open successfully";
    }
}

void create_table()
{
    // 用于执行sql语句的对象
    QSqlQuery sqlQuery(database);
    // 构建创建数据库的sql语句字符串
    // 执行sql语句
    if(!sqlQuery.exec("create table history (ID int primary key,expression varchar)"))
    {
        qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Table created!";
    }
}

void add_table(QString s)
{
    QSqlQuery sql_query(database);
    sql_query.prepare("insert into history values(:ID,:expression)");
    if(table_size < 10)
        sql_query.bindValue(":ID", ++table_size);
    else
        sql_query.bindValue(":ID", 10);
    sql_query.bindValue(":expression", s);

    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to add. " << sql_query.lastError();
    }
}

void find_table()
{
    QSqlQuery sql_query(database);
    int id;
    sql_query.exec("select * from history");
     if(!sql_query.exec())
     {
         qDebug()<<sql_query.lastError();
     }
     else
     {
         while(sql_query.next())
         {
             id = sql_query.value(0).toInt();
             QString name = sql_query.value(1).toString();
             qDebug()<<id<<endl<<name;
         }
     }
}

void find_line(int num)
{
    QSqlQuery sql_query(database);
    int id;
    sql_query.exec("select * from history");
     if(!sql_query.exec())
     {
         qDebug()<<sql_query.lastError();
     }
     else
     {
         while(sql_query.next())
         {
             id = sql_query.value(0).toInt();

             QString name = sql_query.value(1).toString();
             line_data = name;

             if(num == id)
                break;
         }
     }
}


void delete_table(QString s)
{
    QSqlQuery sql_query(database);
    QString op = "delete from history where ID = " + s;
    qDebug()<<op;
    sql_query.exec("delete from history where ID = " + s);
}

void delete_all()
{
    QSqlQuery sqlQuery;

    sqlQuery.exec(QString("DROP TABLE history"));
        if(sqlQuery.exec())
        {
            qDebug() << sqlQuery.lastError();
        }
        else
        {
            qDebug() << "deleted table success";
        }
}

void modify_data(int id)
{
    QSqlQuery sql_query(database);
    sql_query.prepare("update history set ID=? where ID=?");
    sql_query.addBindValue(id - 1);
    sql_query.addBindValue(id);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "updated data success!";
    }
}
