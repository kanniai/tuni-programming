#include "gameoverdialog.hh"
#include "ui_gameoverdialog.h"

namespace StudentSide {

gameOverDialog::gameOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOverDialog)
{
    ui->setupUi(this);
}

gameOverDialog::~gameOverDialog()
{
    delete ui;
}

void gameOverDialog::setLabelTexts(QString player, int runningMinutes,
                                   int runningSeconds)
{
    ui->winnerLabel->setText(player + " won the game!");

    if (runningMinutes == 0) {
        ui->timeSpentLabel->setText("Time spent: " +
                                      QString::number(runningSeconds) +
                                    " seconds.");
    } else {
        ui->timeSpentLabel->setText(" Time spent: " +
                                      QString::number(runningMinutes) +
                                      " minutes and " +
                                    QString::number(runningSeconds) +
                                    " seconds.");
    }
}

void gameOverDialog::setTop10(QString total_scores)
{
    ui->top10TextBrowser->setText(total_scores);
}

void StudentSide::gameOverDialog::on_restartPushButton_clicked()
{
    qApp->exit( StudentSide::gameOverDialog::EXIT_CODE_REBOOT );
}
}

void StudentSide::gameOverDialog::on_closeButton_clicked()
{
    close();
}
