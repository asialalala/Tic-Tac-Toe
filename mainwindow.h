#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QString>
#include "Place.h"
#include "Game.h"
#include <QMessageBox>


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
    void comunicate(Winner result);


private slots:
    void on_addButton_clicked();// SLOT-handler pressing add button
    void slotPut0(); // SLOT for wiriting o on the clicked button
    void on_pushButtonReset_clicked(); // reset game
    void on_checkBox_stateChanged(int check); // decision if user plais o or x

private:
    Ui::MainWindow *ui;
    Game game;

};
#endif // MAINWINDOW_H
