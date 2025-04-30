#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    use(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::use(int won)
{

    money += won;
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=200);
    ui->pbReset->setEnabled(money>0);


}

void Widget::on_pb10_clicked()
{
    use(10);
}

void Widget::on_pb50_clicked()
{
    use(50);
}


void Widget::on_pb100_clicked()
{
    use(100);
}

void Widget::on_pb500_clicked()
{
    use(500);
}


void Widget::on_pbCoffee_clicked()
{
    use(-100);
}


void Widget::on_pbTea_clicked()
{
    use(-150);
}


void Widget::on_pbMilk_clicked()
{
    use(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int coinname[4] = {0};
    int coin[4] = {500, 100, 50, 10};

    int remain = money;
    for (int i = 0; i < 4; ++i) {
        coinname[i] = remain / coin[i];
        remain %= coin[i];
    }
    QString msg;
    msg += QString("거스름돈:\n");
    msg += QString("500원: %1개\n").arg(coinname[0]);
    msg += QString("100원: %1개\n").arg(coinname[1]);
    msg += QString("50원: %1개\n").arg(coinname[2]);
    msg += QString("10원: %1개").arg(coinname[3]);

    mb.information(this, "Change Info", msg);
    money = 0;
    use(0);
}
