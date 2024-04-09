#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamethread.h"
#include "head.h"
#include "qgraphicsscene.h"
#include "snake.h"
#include "target.h"
#include <thread>
#include <atomic>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene scene;

    GameThread *gThread;

public slots:
    void onTargetReached();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();

};
#endif // MAINWINDOW_H
