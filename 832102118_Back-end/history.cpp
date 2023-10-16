#include "history.h"
#include "ui_history.h"
#include "Mysql.h"
History::History(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::History)
    {
        ui->setupUi(this);
        for(int i = 1; i <= table_size; i++)
        {
            find_line(i);
            ui->textBrowser->append(line_data);
            ui->textBrowser->append("");
        }
    }

History::~History()
{
    delete ui;
}

void History::on_equal_clicked()
{
    this->parentWidget()->show();
    delete this;
}
