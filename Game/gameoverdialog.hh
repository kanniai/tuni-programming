#ifndef GAMEOVERDIALOG_HH
#define GAMEOVERDIALOG_HH

#include <QDialog>

namespace Ui {
class gameOverDialog;
}
namespace StudentSide {

class gameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gameOverDialog(QWidget *parent = nullptr);
    ~gameOverDialog();

private:
    Ui::gameOverDialog *ui;
};
}
#endif // GAMEOVERDIALOG_HH
