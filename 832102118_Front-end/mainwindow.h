#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_pushButton_3_clicked();

    void on_symbol_clicked();

    void on_rightB_clicked();

    void on_LeftB_clicked();

    void on_add_clicked();

    void on_minus_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_equal_clicked();

    void on_clearOne_clicked();

    void on_clearBut_clicked();

    void on_mod_clicked();

    void on_ln_clicked();

    void on_log_clicked();

    void on_cube_clicked();

    void on_square_clicked();

    void on_abs_clicked();

    void on_re_clicked();

    void on_factorial_clicked();

    void on_exp_clicked();

    void on_ln_2_clicked();

    void on_ln_3_clicked();

    void on_ln_4_clicked();

    void on_ln_5_clicked();

    void on_ln_6_clicked();

    void on_trigBox_currentIndexChanged(int index);

    void on_SysConvertBox_currentIndexChanged(int index);

    long Mypow(int x, int y)
    {
        long res = 1;
        for(int i = 0; i < y; i ++)
        {
            res *= x;
        }
        return res;
    }
    int ten_to_two(int num)
    {
        int res = 0, tmp = num,j = 1;
        while(tmp)
        {
            res = res + j * (tmp %2);
            tmp = tmp / 2;
            j = j * 10;
        }
        return res;
    }

private:
    Ui::MainWindow *ui;
    bool clearall;
    bool eq;
};

#endif // MAINWINDOW_H
