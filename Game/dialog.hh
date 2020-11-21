#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include <QKeyEvent>
#include <QString>
#include <map>


namespace Ui {

class Dialog;
}


namespace StudentSide {
/**
 * @brief The Dialog class is presented in making pregame-choices before
 * actually starting the game
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    // Player vehicle selection
    void helicopterSelected();
    void fighterSelected();
    void spaceShipSelected();

private slots:
    void on_heliButton_clicked();
    void on_jetButton_clicked();
    void on_spaceButton_clicked();

private:
    Ui::Dialog *ui;
};
}
#endif // DIALOG_HH
