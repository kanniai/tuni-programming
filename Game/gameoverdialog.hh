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
    void setLabelTexts(QString player, int runningMinutes, int runningSeconds);
    void setTop10(QString total_scores);

    static int const EXIT_CODE_REBOOT = -123456789;

private:
    Ui::gameOverDialog *ui;

private slots:
    void on_restartPushButton_clicked();
};
}
#endif // GAMEOVERDIALOG_HH
