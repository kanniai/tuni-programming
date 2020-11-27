#include "dialog.hh"
#include "ui_dialog.h"

namespace StudentSide {

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->errorNameLabel->hide();
    ui->heliButton->hide();
    ui->jetButton->hide();
    ui->spaceButton->hide();

    ui->name2Button->setDisabled(true);
    ui->player2LineEdit->setDisabled(true);
    ui->selectLabel->hide();

    ui->helicopterLabel->hide();
    ui->heliStatsLabel_1->hide();
    ui->heliStatsLabel_2->hide();

    ui->jetFighterLabel->hide();
    ui->jetStatsLabel_1->hide();
    ui->jetStatsLabel_2->hide();

    ui->spaceShipLabel->hide();
    ui->spaceStatsLabel_1->hide();
    ui->spaceStatsLabel_2->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

}

void StudentSide::Dialog::on_heliButton_clicked()
{
    startGame_ = true;
    emit helicopterSelected();
    close();
}

void StudentSide::Dialog::on_jetButton_clicked()
{
    startGame_ = true;
    emit fighterSelected();
    close();
}

void StudentSide::Dialog::on_spaceButton_clicked()
{
    startGame_ = true;
    emit spaceShipSelected();
    close();
}

void StudentSide::Dialog::on_name1Button_clicked()
{
    if (ui->player1LineEdit->text().isEmpty()) {
        ui->errorNameLabel->show();
    } else { name1_ = ui->player1LineEdit->text();
        ui->errorNameLabel->hide();
        ui->player1LineEdit->setDisabled(true);
        ui->name1Button->setDisabled(true);
        emit player1Name(name1_);

        ui->player2LineEdit->setEnabled(true);
        ui->name2Button->setEnabled(true);
    }
}

void StudentSide::Dialog::on_name2Button_clicked()
{
    if (ui->player2LineEdit->text().isEmpty()) {
        ui->errorNameLabel->show();
    } else {
        ui->errorNameLabel->hide();
        name2_ = ui->player2LineEdit->text();
        ui->player2LineEdit->setDisabled(true);
        ui->name2Button->setDisabled(true);
        emit player2Name(name2_);

        ui->heliButton->show();
        ui->jetButton->show();
        ui->spaceButton->show();

        ui->selectLabel->show();
        ui->selectLabel->setText(name1_ + ", select the vehicle!");

        ui->helicopterLabel->show();
        ui->heliStatsLabel_1->show();
        ui->heliStatsLabel_2->show();

        ui->jetFighterLabel->show();
        ui->jetStatsLabel_1->show();
        ui->jetStatsLabel_2->show();

        ui->spaceShipLabel->show();
        ui->spaceStatsLabel_1->show();
        ui->spaceStatsLabel_2->show();
    }
}

void StudentSide::Dialog::closeEvent(QCloseEvent *event)
{
    if (startGame_ == true) {
        return;
    }
    exit(0);
}
