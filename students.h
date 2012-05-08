#ifndef STUDENTS_H
#define STUDENTS_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
    class students;
}

class students : public QMainWindow
{
    Q_OBJECT

public:
    explicit students(QWidget *parent = 0);
    ~students();

private slots:
    void on_actionInit_triggered();

    void on_action_triggered();

private:
    Ui::students *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // STUDENTS_H
