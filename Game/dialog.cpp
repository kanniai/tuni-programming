#include "dialog.hh"
#include "ui_dialog.h"

const int NEXTROW = 20;

namespace StudentSide {

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->helicopterButton->setIcon()

}

Dialog::~Dialog()
{
    delete ui;
}


}

void StudentSide::Dialog::on_heliButton_clicked()
{
    emit helicopterSelected();
    close();
}

void StudentSide::Dialog::on_jetButton_clicked()
{
    emit fighterSelected();
    close();
}

void StudentSide::Dialog::on_spaceButton_clicked()
{
    emit spaceShipSelected();
    close();
}
