#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#define cout qDebug() << "[" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    cout << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("xuxudb");
    db.setUserName("root");
    db.setPassword("");
    bool isOk = db.open();
    if(isOk)
    {
        cout << "sql already connect";
    }
    else
    {
       cout << "connect failure";
    }
    m_model = new QSqlTableModel(this);
    m_model->setTable("stu");
    m_model->select();

    ui->tableView->setModel(m_model);
}

Widget::~Widget()
{
    delete ui;
}
