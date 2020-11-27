#ifndef GAMEOVERDIALOG_HH
#define GAMEOVERDIALOG_HH

#include <QDialog>
#include <string>

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
    void setLabelTexts(QString player, int runningMinutes, int runningSeconds);

private:
    Ui::gameOverDialog *ui;
};
}
#endif // GAMEOVERDIALOG_HH
