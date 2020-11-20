#ifndef DIALOG_HH
#define DIALOG_HH

#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QKeyEvent>

#include <QString>
#include <map>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPointF>
#include <QDialog>

namespace Ui {
class Dialog;
}

namespace StudentSide {
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void helicopterSelected();
    void fighterSelected();
    void spaceShipSelected();


private slots:

    void on_closeButton_clicked();

    void on_heliButton_clicked();

    void on_jetButton_clicked();

    void on_spaceButton_clicked();

private:
    Ui::Dialog *ui;
};
}
#endif // DIALOG_HH
