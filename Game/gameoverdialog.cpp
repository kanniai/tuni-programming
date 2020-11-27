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
}
