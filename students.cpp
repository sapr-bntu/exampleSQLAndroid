#include "students.h"
#include "ui_students.h"

students::students(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::students)
{
    ui->setupUi(this);
}

students::~students()
{
    delete ui;
}

void students::on_actionInit_triggered()
{

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("students.s3db");
    db.open();

    QSqlQuery query;
    query.exec("CREATE TABLE [groups] ("
             "[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
             "[name] VARCHAR(20)  NULL"
             ")"  );
    query.exec("CREATE TABLE [prepod] ("
             "[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
             "[fio] VARCHAR(255)  NULL"
             ")");
    query.exec("CREATE TABLE [rasp] ("
             "[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
             "[name] VARCHAR(200)  NULL,"
             "  [type] VARCHAR(20)  NULL,"
             " [day] INTEGER DEFAULT '1' NULL,"
             " [time] TIME  NULL"
             "  )");
    query.exec("CREATE TABLE [students] ("
                   "[id] INTEGER  PRIMARY KEY AUTOINCREMENT NOT NULL,"
                   "[fio] VARCHAR(255)  NULL,"
                   "[nickname] VARCHAR(20)  NULL,"
                   "[groupnumber] vARCHAR(20) DEFAULT '0' NULL"
                   ")");
    //    model->select();
//    return true;
}

void students::on_action_triggered()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("students.s3db");
    db.open();
    QSqlQuery query;
    query.exec("INSERT INTO  students ("
               "fio,nickname,'groupnumber') VALUES("
               "'ivanov i i',"
               "'student',"
               "'107528'"
               ")");
        model = new QSqlTableModel(this);
        model->setTable("students");
        model->select();
        ui->tableView_2->setModel(model);
    //    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_clik()));
}
