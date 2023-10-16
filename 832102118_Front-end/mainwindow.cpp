#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycal.h"
#include "history.h"
#include <QMessageBox>
#include "Mysql.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input->setAlignment(Qt::AlignRight);        //输入框右对齐
    ui->formula->setAlignment(Qt::AlignRight);      //表达式框右对齐
    ui->histoyText->setAlignment(Qt::AlignRight);   //历史记录框右对齐
    ui->input->setText("0");                        //输入框初始值显示0
    ui->histoyText->setText("Empty history");          //历史记录初始值设置
    clearall = false;   //清除标志
    eq = false;         //是否有历史记录
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_one_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"1");
}

void MainWindow::on_two_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"2");
}

void MainWindow::on_three_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"3");
}

void MainWindow::on_four_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"4");
}

void MainWindow::on_five_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"5");
}

void MainWindow::on_six_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"6");
}

void MainWindow::on_seven_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"7");
}

void MainWindow::on_eight_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"8");
}

void MainWindow::on_nine_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"9");
}


void MainWindow::on_zero_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    QString s = ui->formula->text();
    int n = s.length();
    if(n != 0 && s[n - 1] == ')') //数字前不能出现右括号
    {
        QMessageBox::information(NULL, "错误","数字前不能为右括号!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->input->setText(ui->input->text()+"0");
}

void MainWindow::on_pushButton_3_clicked()  //小数点
{
    QString s = ui->input->text();    //获取之前输入的数字
    int n = s.length();
    if(n != 0 && (s[n - 1] > '9' || s[n - 1] < '0')) //小数点前没有数字
    {
        QMessageBox::information(NULL, "错误","小数点前应输入数字!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    else if(n == 0) //不能小数点开头
    {
        QMessageBox::information(NULL, "错误","小数点前为空!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }

    for(int i = 0; i < n; ++ i)
    {
        if(s[i] == '.') //这个数字前是否还有小数点
        {
            QMessageBox::information(NULL, "错误","只能有一个小数点!",
                                     QMessageBox::Yes,QMessageBox::Yes);
            return;
            break;
        }
    }
    ui->input->setText(ui->input->text()+".");
}


void MainWindow::on_symbol_clicked()    //正负号
{
    if(ui->input->text()[0] == '-') //是负数
    {
        QString str = ui->input->text();
        QString s;
        for(int i = 1, j = 0; i < str.length(); ++i, ++j)
            s[j] = str[i];  //去掉负号，变为正数
        ui->input->setText(s);
    }
    else ui->input->setText("-"+ui->input->text()); //为正数，加上负号
}

void MainWindow::on_rightB_clicked()    //左括号
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    QString s = ui->formula->text();
    int n = s.length();
    //左括号前不能有右括号，数字和小数点出现
    if(n != 0 &&(s[n - 1] == ')' || s[n - 1] == '.' || (s[n - 1] >= '0' && s[n - 1] <= '9')))
    {
        QMessageBox::information(NULL, "错误","括号前输入非法!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->formula->setText(ui->formula->text() + "(");
    ui->input->setText("0");
}

void MainWindow::on_LeftB_clicked()     //右括号
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    QString s = ui->formula->text();
    int n = s.length();
    if(n == 0)
    {
        QMessageBox::information(NULL, "错误","右括号前不能为空!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->formula->setText(ui->formula->text() + ")");
    ui->input->setText("0");
}

void MainWindow::on_add_clicked()   //加法
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    QString s = ui->formula->text();    //已有表达式
    int n = s.length(); //表达式长度
    if(n != 0 && s[n - 1] == '.')
    {
        QMessageBox::information(NULL, "错误","加号前不能有小数点!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->formula->setText(ui->formula->text()+"+");
    ui->input->setText("0");
}

void MainWindow::on_minus_clicked()     //减法
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    QString s = ui->formula->text();    //已有表达式
    int n = s.length(); //表达式长度
    if(n != 0 && s[n - 1] == '.')
    {
        QMessageBox::information(NULL, "错误","减号前不能有小数点!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->formula->setText(ui->formula->text() +"-");
    ui->input->setText("0");
}

void MainWindow::on_multiply_clicked()  //乘法
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    QString s = ui->formula->text();    //已有表达式
    int n = s.length(); //表达式长度
    if(n != 0 && s[n - 1] == '.')
    {
        QMessageBox::information(NULL, "错误","乘、号前不能有小数点!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->formula->setText(ui->formula->text() +"*");
    ui->input->setText("0");
}

void MainWindow::on_divide_clicked()    //除法
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    QString s = ui->formula->text();    //已有表达式
    int n = s.length(); //表达式长度
    if(n != 0 && s[n - 1] == '.')
    {
        QMessageBox::information(NULL, "错误","除号前不能有小数点!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    ui->formula->setText(ui->formula->text() +"/");
    ui->input->setText("0");
}

void MainWindow::on_equal_clicked() //等于，计算结果
{
    if(ui->input->text() != "0")    //输入框里有数字
        ui->formula->setText(ui->formula->text() + ui->input->text());  //加入到表达式当中
    myCal res;      //计算表达式的对象
    QString re = res.getResult(ui->formula->text());   //调用类中的计算结果函数，传入表达式
    if(re == NULL)
    {
        QMessageBox::information(NULL, "错误","除数为0!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    else if(re == "wrong")
    {
        QMessageBox::information(NULL, "错误","输入非法!",
                                 QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    QString R = ui->formula->text() + "=" + re;     //将表达式与结果连接起来
    ui->formula->setText(R);    //显示结果
    ui->input->setText(re);
    if(table_size < 10)     //之前没有历史记录
    {
        add_table(R);
        find_table();
    }
    else
    {   //将已有历史记录下移两行便于新记录插入
        delete_table("1");
        for(int i = 2; i <= 10; i++)
            modify_data(i);
        add_table(R);
        find_table();
    }


}

void MainWindow::on_clearOne_clicked()  //清除一个字符的按钮
{
    QString str = ui->input->text();
    QString s;
    for(int i = 0, j = 0; i < str.length() - 1; ++i, ++j)
        s[j] = str[i];
    ui->input->setText(s);
}

void MainWindow::on_clearBut_clicked()  //清除按钮
{
    if(clearall == true)
    {
        ui->formula->clear();
        clearall = false;
    }
    else
    {
        ui->input->clear();
        clearall = true;
    }
}

void MainWindow::on_mod_clicked()   // 取模运算
{
    ui->formula->setText(ui->formula->text() + ui->input->text());
    QString snum = ui->input->text();
    int num = snum.toInt();
    ui->formula->setText(ui->formula->text() + "%");
    ui->input->setText("0");
}

void MainWindow::on_ln_clicked()    //以e为底的对数
{
    QString snum = ui->input->text();
    double num = snum.toDouble();
    double res = log(num);
    QString str;
    str.sprintf("%.10lf", res);
    ui->formula->setText(ui->formula->text() + str);
    if(eq == false)     //之前没有历史记录
    {
        ui->histoyText->clear();    //将“尚无历史记录”几个字清空
        eq = true;                  //设置标志为true表示有历史记录了
    }
    else
    {   //将已有历史记录下移两行便于新记录插入
        ui->histoyText->setText("\n\n"+ ui->histoyText->toPlainText());
    }
    ui->histoyText->setText("ln(" + snum + ") = " + str + ui->histoyText->toPlainText()); //插入到历史记录文本框
    ui->input->setText("0");
}

void MainWindow::on_log_clicked()   //以10为底的对数
{
    QString snum = ui->input->text();
    double num = snum.toDouble();
    double res = log10(num);
    QString str;
    str.sprintf("%.10lf", res);
    ui->formula->setText(ui->formula->text() + str);
    if(eq == false)     //之前没有历史记录
    {
        ui->histoyText->clear();    //将“尚无历史记录”几个字清空
        eq = true;                  //设置标志为true表示有历史记录了
    }
    else
    {   //将已有历史记录下移两行便于新记录插入
        ui->histoyText->setText("\n\n"+ ui->histoyText->toPlainText());
    }
    ui->histoyText->setText("log(" + snum + ") = " + str + ui->histoyText->toPlainText()); //插入到历史记录文本框
    ui->input->setText("0");
}

void MainWindow::on_cube_clicked()  //立方
{
    QString snum = ui->input->text();
    double num = snum.toDouble();
    double res = num * num * num;
    QString str;
    str.sprintf("%.10lf", res);
    ui->formula->setText(ui->formula->text() + str);
    ui->input->setText("0");
}

void MainWindow::on_square_clicked()    //平方
{
    QString snum = ui->input->text();
    double num = snum.toDouble();
    double res = num * num;
    QString str;
    str.sprintf("%.10lf", res);
    if(!ui->formula->text().isEmpty())
        ui->formula->setText(ui->formula->text() + "+");
    ui->formula->setText(ui->formula->text() + str);
    ui->input->setText("0");
}

void MainWindow::on_abs_clicked()   //计算绝对值
{
    if(!ui->formula->text().isEmpty())
    {
        QChar beg = ui->formula->text()[ui->formula->text().length() - 1];
        if(beg == '-')
        {
            QString s = ui->formula->text();
            ui->formula->setText(s.remove(ui->formula->text().length() - 1, 1));
        }
    }
    QString str = ui->input->text();
    ui->formula->setText(ui->formula->text() + str);
    ui->input->setText("0");
}

void MainWindow::on_re_clicked()    //计算倒数
{
    History *win = new History(this);
    win->show();
    this->hide();
}

void MainWindow::on_factorial_clicked()
{
    QString str = ui->input->text();
    int num = str.toInt();
    int res = 1;
    for(int i = 1; i <= num ; ++i)
        res *= i;
    str.sprintf("%d", res);
    ui->formula->setText(ui->formula->text() + str);
    ui->input->setText("0");
}

void MainWindow::on_exp_clicked()   //指数运算
{
    if(ui->input->text()!="0")
        ui->formula->setText(ui->formula->text() + ui->input->text());
    ui->formula->setText(ui->formula->text() +"^");
    ui->input->setText("0");
}

void MainWindow::on_ln_2_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    ui->input->setText(ui->input->text()+"A");
}

void MainWindow::on_ln_3_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    ui->input->setText(ui->input->text()+"B");
}

void MainWindow::on_ln_4_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    ui->input->setText(ui->input->text()+"C");
}

void MainWindow::on_ln_5_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    ui->input->setText(ui->input->text()+"D");
}

void MainWindow::on_ln_6_clicked()
{
    if(ui->input->text() == "0")
    {
        ui->input->clear();
    }
    ui->input->setText(ui->input->text()+"E");
}

void MainWindow::on_trigBox_currentIndexChanged(int index)  //三角函数计算
{
    index = ui->trigBox->currentIndex();
    QString op = ui->trigBox->currentText();
    QString R;  //完整表达式

    if(op == "sin")             //选择计算sin(X)
    {
        QString snum = ui->input->text();
        double x = snum.toDouble(); //获取计算的数字
        double num = sin(x);        //得到计算结果
        QString res;
        res.sprintf("%lf", num);    //将计算结果转换为字符串类型
        //re =
        ui->formula->setText(ui->formula->text() + res); //将结果插入到表达式中
        R = op + "("+snum + ") = " + res;   //得到完整计算式
        ui->input->clear();         //清除输入框
    }
    else if(op == "cos")        //选择计算cos(X)
    {
        QString snum = ui->input->text();
        double x = snum.toDouble();
        double num = cos(x);
        QString res;
        res.sprintf("%lf", num);
        ui->formula->setText(ui->formula->text() + res);
        R = op + "("+snum + ") = " + res;
        ui->input->clear();
    }
    else if(op == "tan")        //选择计算tan(X)
    {
        QString snum = ui->input->text();
        double x = snum.toDouble();
        double num = tan(x);
        QString res;
        res.sprintf("%lf", num);
        ui->formula->setText(ui->formula->text() + res);
        R = op + "("+snum + ") = " + res;
        ui->input->clear();
    }

    if(eq == false)     //之前没有历史记录
    {
        ui->histoyText->clear();    //将“尚无历史记录”几个字清空
        eq = true;                  //设置标志为true表示有历史记录了
    }
    else
    {   //将已有历史记录下移两行便于新记录插入
        ui->histoyText->setText("\n\n"+ ui->histoyText->toPlainText());
    }
    ui->histoyText->setText(R + ui->histoyText->toPlainText()); //插入到历史记录文本框

    ui->trigBox->setCurrentIndex(0);
}

