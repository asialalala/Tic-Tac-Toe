#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QString>
#include "Place.h"
#include "Game.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \file
 * \brief The MainWindow class
 *
 * The file includes definition of class MainWindow responsible
 * for despaying window with Tic-Tac-Toe
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();// SLOT-handler pressing add button
    void slotGetNumber();           // SLOT for getting number of the dynamic buttons
    void slotPut0(); // SLOT for wiriting O on the clicked button

private:
    Ui::MainWindow *ui;
    Game game;

};
#endif // MAINWINDOW_H
