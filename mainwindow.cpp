#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->fitInView(scene.sceneRect());

    ui->graphicsView->setHead();
    ui->graphicsView->setSnake();
}

MainWindow::~MainWindow()
{
    delete ui;

    if (gThread) {
        gThread->stop = true;
        gThread->wait();
        delete gThread;
    }
}

void MainWindow::onTargetReached(){

    ui->graphicsView->deleteTarget();
    ui->graphicsView->addTargets(1);
    ui->graphicsView->incrScore();
    ui->graphicsView->incTail();
    int score = ui->graphicsView->getScore();
    ui->lineEditScore->setText(QString::number(score));
    ui->lineEditScore->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_pushButtonStart_clicked()
{
   gThread = new GameThread(*ui->graphicsView);
   connect(gThread, &GameThread::targetReached, this, &MainWindow::onTargetReached);

   gThread->stop = false;
   gThread->start();
}


void MainWindow::on_pushButtonStop_clicked()
{
    if (gThread) {
        gThread->stop = true;
    }
    ui->graphicsView->deleteTarget();
}



