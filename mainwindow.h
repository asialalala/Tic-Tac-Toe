#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "Place.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();// SLOT-handler pressing add button
    void slotGetNumber();           // SLOT for getting number of the dynamic buttons


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
