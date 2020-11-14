#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>


const int PADDING = 40;
const int NEXTROW = 30;
const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 700;

namespace StudentSide {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette black = palette();
    black.setColor(QPalette::Background, Qt::black);

    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(WINDOW_WIDTH + ui->startButton->width() + PADDING, WINDOW_HEIGHT+ PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);
    ui->timeLabel->move(width_ + PADDING, 3*NEXTROW);
    ui->runningTime->move(width_ + 3*PADDING, 3*NEXTROW);
    ui->timeFrame->move(width_ + 2.75*PADDING, 3*NEXTROW);

    ui->busesLabel->move(width_ + PADDING, 5*NEXTROW);
    ui->busCount->move(width_ + 5*PADDING, 5*NEXTROW);
    ui->busCount->setAutoFillBackground(true);
    ui->busCount->setPalette(black);


    ui->statisticsLabel->move(width_ + 1.2*PADDING, 6.2*NEXTROW);
    ui->statisticsLabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px");
    ui->destroyedTextLabel->move(width_ + PADDING, 7.5*NEXTROW);
    ui->destroyedLabel->move(width_ + 6*PADDING, 7.5*NEXTROW);
    ui->killedTextLabel->move(width_ + PADDING, 8.5*NEXTROW);
    ui->killedLabel->move(width_ + 6*PADDING, 8.5*NEXTROW);
    ui->statisticsFrame->move(width_ + 0.8*PADDING, 6*NEXTROW);


    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void MainWindow::setTick(int t)
{
    tick_ = t;
}

void MainWindow::addActor(int locX, int locY, int type, std::shared_ptr<Interface::IActor> actor)
{
    ActorItem* nActor = new ActorItem(locX, locY, type);
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;

    if (type == 1) {
        buses_.insert( {actor, nActor} );
    } else if (type == 2) {
        passengers_.insert( {actor, nActor} );
    }

}

void MainWindow::updateCoords(int nX, int nY)
{
    last_->setCoord(nX, nY);
}

void MainWindow::updateActorCoords(int nX, int nY, std::shared_ptr<Interface::IActor> actor,
                                   int type)
{
    if (type == 1) {
        std::map<std::shared_ptr<Interface::IActor>,ActorItem*>::iterator it;
        it = buses_.find(actor);
        if (it != buses_.end())
          it->second->setCoord(nX, nY);
    } else if (type == 2) {
        std::map<std::shared_ptr<Interface::IActor>,ActorItem*>::iterator it;
        it = passengers_.find(actor);
        if (it != passengers_.end())
          it->second->setCoord(nX, nY);
    }
}

void StudentSide::MainWindow::MainWindow::showTime()
{
    QString minutes = QString::number(minutes_);
    QString hours = QString::number(hours_);

    if (minutes_ < 10) {
        minutes = "0" + minutes;
    }
    if (hours_ < 10) {
        hours = "0" + hours;
    }

    ui->runningTime->setText(hours + " : " + minutes);
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::setTime(int hours, int minutes)
{
    hours_ = hours;
    minutes_ = minutes;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) {
        emit buttonPressed('w');
    } else if (event->key() == Qt::Key_D) {
        emit buttonPressed('d');
    } else if (event->key() == Qt::Key_S) {
        emit buttonPressed('s');
    } else if (event->key() == Qt::Key_A) {
        emit buttonPressed('a');
    }
}

}

void StudentSide::MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
}

