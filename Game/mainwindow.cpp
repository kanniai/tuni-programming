#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

const int PADDING = 10;

namespace StudentSide {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

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
        //for (auto data_pair: passengers_) {
            //if (data_pair.first == actor) {
            //    data_pair.second ->setCoord(nX, nY);
          //  }
        //}
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
