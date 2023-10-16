#include "mycal.h"


myCal::myCal()
{
}

QQueue<QString> myCal::getMid(const QString& s) //分离操作数和运算符
{
    QQueue<QString> Q;  //分离后的操作数与运算符队列
    QString val="";     //操作数
    for(int i=0;i<s.length();i++)
    {
        if( (s[i]=='.') || ( (s[i]>='0') && (s[i]<='9') )) //判断小数点和数字
            val += s[i];
        else if(s[i]== '(' || s[i]== ')' || s[i]== '*' || s[i]== '/' || s[i] == '^' || s[i] == '%' )
        {
            if(!val.isEmpty()){
                Q.enqueue(val);                 //加入数字
                val.clear();                    //清空数字，等待下一个操作数
            }
            Q.enqueue(s[i]);                    //加入运算符
        }
        else if(s[i]== '+' || s[i]== '-')       //+，-号有两种情况，运算符或者正负号
        {
            if(i==0) val+= s[i];                //表达式第一个字符则是正负号
            else if(s[i-1]=='(' || s[i-1]=='+' || s[i-1]=='-' || s[i-1]=='*' || s[i-1]=='/'|| s[i-1] == '^' || s[i-1] == '%')
                val+= s[i];                     //括号或者运算符开头也是正负号
            else                                //其他情况则是加减运算符
            {
                if(!val.isEmpty())
                {
                    Q.enqueue(val);             //加入数字
                    val.clear();                //清空数字
                }
                Q.enqueue(s[i]);                //加入运算符
            }
        }
    }
    if(!val.isEmpty())                          //遍历完成，加入最后一个操作数
    {
        Q.enqueue(val);
        val.clear();
    }
    return Q;
}

QQueue<QString> myCal::getPost(QQueue<QString>& s)     //将中缀队列转换为后缀队列
{
    QStack<QString> st;
    QQueue<QString> Q;
    bool cheak;
    QString fuhao;

    while(!s.isEmpty())
    {
      fuhao = s.dequeue();      //取出一个字符
      fuhao.toDouble(&cheak);   //转换为字符串

      if(cheak==true)           //字符为数字
           st.push(fuhao);
      else if(fuhao=="+"||fuhao=="-")   //加减运算符
      {
          while(!st.isEmpty() &&(st.top()!="(")) //直到栈空或遇到左括号
              Q.enqueue(st.pop());     //由于优先级，先将其他运算符加入队列
          st.push(fuhao);        //此次运算符入栈
      }
      else if(fuhao=="*"||fuhao=="/"|| fuhao == "^" || fuhao == "%")
      {
          while(!st.isEmpty() && (st.top()!="(") && (st.top()!="+") && (st.top()!="-"))
              Q.enqueue(st.pop());//之前的同优先级运算符入队列
          st.push(fuhao);         //此次运算符入栈
      }
      else if(fuhao == "(")       //左括号入栈
         st.push(fuhao);
      else if(fuhao ==")")        //右括号
      {
          while(!st.isEmpty() && (st.top()!="("))
              Q.enqueue(st.pop());//括号里运算符入队列
          if(st.top()=="(")       //去掉左括号
            st.pop();
      }
    }
    while(!st.isEmpty()&& (st.top()!="("))//遍历完成，加入最后一个运算符
       Q.enqueue(st.pop());
    return Q;
}

QString myCal::resultCorrect(QString str)
 {
    QString num;
    if(str.indexOf(".")== -1) //判断是否小数
        return str;

    while(str.length()>1)   //避免0被去掉
    {
         num=str.right(1);
         if(num=="."||num=="0")
         {
             str.chop(1);
             if(num==".")
                 return  str;
         }
         else
             return str;
    }
    return str;
}

QString myCal::calTwoOper(QString& l,QString& op,QString& r )
{
    double left,right,res;
    QString ret="";
    left = l.toDouble();
    right = r.toDouble();
    if(op == "+")
        res = left + right;
    else if(op == "-")
        res = left - right;
    else if(op == "*")
        res = left * right;
    else if(op == "/")
    {   //除数为0
        if( (right>(-1e-10)) && (right<(1e-10))) return NULL;
        else res = left/right;
    }
    else if(op == "%")
    {
        int l = int(left);
        int r = int(right);
        res = l % r;
    }
    else if(op == "^")
    {
        res = 1;
        for(int i = 1; i <= right; ++i)
            res *=left;
    }
    ret.sprintf("%f",res);
    return ret;
}

QString myCal::calExp(QQueue<QString>& s)//计算后缀表达式
{
    QStack<QString> st;
    QString fuhao,l,r,result;
    bool check;

    while(!s.isEmpty())
    {
      fuhao = s.dequeue();      //取出一个字符串
      fuhao.toDouble(&check);
      if(check==true)           //数字则入栈等待计算
        st.push(fuhao);
      else                      //运算符则进行计算
      {
          if(st.size()<2) return "wrong";//操作数不足两个
          r= st.pop();          //取出两个数字进行计算
          l= st.pop();
          result = calTwoOper(l,fuhao,r );//得到计算结果
          if(result==NULL) return result; //除数为零
          st.push(result);      //加入计算结果，等待后续计算
      }
    }
    if(st.size()==1) //计算完成，结果唯一
         return resultCorrect(st.pop());
    else return "wrong";
}

QString myCal::getResult(const QString& s)
{
      QQueue<QString> Q;
      Q=getMid(s);              //分离操作数和运算符
      QQueue<QString> pos=getPost(Q);//得到后缀队列
      QString res =  calExp(pos);    //计算后缀表达式
      return res;          //返回结果
}


