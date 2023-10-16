#ifndef MYCAL_H
#define MYCAL_H
#include <QString>
#include <QStack>
#include <QQueue>
#include <QDebug>

class myCal
{
public:
    QQueue<QString> getMid(const QString& exp);             //得到中缀队列
    QQueue<QString> getPost(QQueue<QString>& exp);          //得到后缀队列
    QString calExp(QQueue<QString>& exp);                   //得到后缀队列结果
    QString calTwoOper(QString& l,QString& p,QString& r ); //双操作数运算结果
    QString resultCorrect(QString str);                     //检查结果的合法性
    myCal();
    QString getResult(const QString& exp);      //调用函数得到计算结果
};

#endif // MYCAL_H
