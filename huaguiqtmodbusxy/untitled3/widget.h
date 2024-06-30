#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QModbusRtuSerialMaster>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void updateSerialInfo();
    void on_pushButton_kp_clicked();
    void on_pushButton_ki_clicked();
    void on_pushButton_kd_clicked();
   // void onReadReady();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;

    //写一个modbus子类
    QModbusRtuSerialMaster *rtuMaster;
};


#endif // WIDGET_H
