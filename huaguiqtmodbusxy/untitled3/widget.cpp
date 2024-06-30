#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始化串口信息
    updateSerialInfo();
    // 创建串口对象
    rtuMaster = new QModbusRtuSerialMaster;
    // 创建定时器并连接 timeout 信号到槽函数
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updateSerialInfo);
    timer->start(1000); // 每隔一秒更新一次串口信息

    // 将水平滑动条的数值改变信号与微调框的数值改变槽连接起来
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox_4, &QSpinBox::setValue);
    // 将微调框的数值改变信号与水平滑动条的值改变槽连接起来
    connect(ui->spinBox_4, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider, &QSlider::setValue);
    // 将水平滑动条的数值改变信号与微调框的数值改变槽连接起来
    connect(ui->horizontalSlider_2, &QSlider::valueChanged, ui->spinBox_5, &QSpinBox::setValue);
    // 将微调框的数值改变信号与水平滑动条的值改变槽连接起来
    connect(ui->spinBox_5, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_2, &QSlider::setValue);

}

Widget::~Widget()
{
    delete ui;
}

/*
 * 端口的刷新
*/
void Widget::updateSerialInfo()
{
    // 保存当前选择的端口
    QString currentPort = ui->comboBox->currentText();
    // 清空原有的串口信息
    ui->comboBox->clear();
    // 获取最新的串口信息并显示
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    for(int i = 0; i < list.size(); i++)
    {
        ui->comboBox->addItem(list.at(i).portName());
    }

    // 恢复之前选择的端口
    int index = ui->comboBox->findText(currentPort);
    if (index != -1)
    {
        ui->comboBox->setCurrentIndex(index);
    }
}


/*
 *端口数据设置
 */
void Widget::on_pushButton_clicked()
{
    //选择端口
    rtuMaster->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBox->currentText());
    //设置波特率
    if(ui->comboBox_2->currentText()=="1200")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,1200);
    }
    else if(ui->comboBox_2->currentText()=="2400")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,2400);
    }
    else if(ui->comboBox_2->currentText()=="4800")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,4800);
    }
    else if(ui->comboBox_2->currentText()=="9600")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,9600);
    }
    else if(ui->comboBox_2->currentText()=="19200")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,19200);
    }
    else if(ui->comboBox_2->currentText()=="38400")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,38400);
    }
    else if(ui->comboBox_2->currentText()=="57600")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,57600);
    }
    else if(ui->comboBox_2->currentText()=="115200")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,115200);
    }
    //设置校验位
    if(ui->comboBox_5->currentText()=="none")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);
    }
    else if(ui->comboBox_5->currentText()=="even")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::EvenParity);
    }
    else if(ui->comboBox_5->currentText()=="odd")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::OddParity);
    }
    //设置停止位
    if(ui->comboBox_4->currentText()=="1")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);
    }
    else if(ui->comboBox_4->currentText()=="2")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::TwoStop);
    }
    //设置数据位
    if(ui->comboBox_3->currentText()=="5")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data5);
    }
    else if(ui->comboBox_3->currentText()=="6")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data6);
    }
    else if(ui->comboBox_3->currentText()=="7")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data7);
    }
    else if(ui->comboBox_3->currentText()=="8")
    {
        rtuMaster->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);
    }
    //打开串口
    if (rtuMaster->state() == QModbusDevice::ConnectedState)
    {
        // 如果 Modbus RTU 设备已经连接，则断开连接
        rtuMaster->disconnectDevice();
        ui->pushButton->setText("打开串口");  // 更新按钮显示文本
        qDebug() << "Modbus RTU device disconnected";
    }
    else
    {
        // 如果 Modbus RTU 设备未连接，则根据当前设置连接设备
        rtuMaster->setConnectionParameter(QModbusDevice::NetworkPortParameter, ui->comboBox->currentText());
        if (rtuMaster->connectDevice())
        {
            ui->pushButton->setText("关闭串口");  // 更新按钮显示文本
            qDebug() << "Modbus RTU device connected";
        }
        else
        {
            qDebug() << "Failed to connect to Modbus RTU device";
        }
    }
}


/*
 * kp输入的数据
 */
void Widget::on_pushButton_kp_clicked()
{
    if (rtuMaster->state() == QModbusDevice::ConnectedState)
    {
        // 获取发送的数据
        int sendkp = ui->spinBox->value();
        //这个到时写在发送成功下面
        ui->textEdit_kp->clear();
        ui->textEdit_kp->append(QString::number(sendkp));
        qDebug() <<sendkp;
        // 将整数值转换为Modbus RTU数据类型（保持寄存器）
        quint16 modbusData;
        if (sendkp >= 0) {
            modbusData = static_cast<quint16>(sendkp);
        } else {
            modbusData = static_cast<quint16>(65536 + sendkp);  // 负数需要转换为补码形式
        }
        // 创建写请求
        QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, 0, 1);  // 使用保持寄存器，从地址0开始，写入1个寄存器，对于不同变量的写入不同寄存器地址
        writeRequest.setValue(0, modbusData);
        // 发送 Modbus RTU 写请求
        rtuMaster->sendWriteRequest(writeRequest, 1);  // 这里的1是从机地址也就是单片机的地址

        qDebug() << "Write request sent";
    }
    else
    {
        qDebug() << "Modbus RTU device is not connected";
    }
}


/*
* ki输入的数据
*/
 void Widget::on_pushButton_ki_clicked()
{
    if (rtuMaster->state() == QModbusDevice::ConnectedState)
    {
        // 获取发送的数据
        int sendki = ui->spinBox_2->value();
        //实时显示出kp值
        ui->textEdit_ki->clear();
        ui->textEdit_ki->append(QString::number(sendki));
        qDebug() <<sendki;
        // 将整数值转换为Modbus RTU数据类型（保持寄存器）
        quint16 modbusData;
        if (sendki >= 0) {
            modbusData = static_cast<quint16>(sendki);
        } else {
            modbusData = static_cast<quint16>(65536 + sendki);  // 负数需要转换为补码形式
        }
        // 创建写请求
        QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, 1, 1);  // 使用保持寄存器，从地址0开始，写入1个寄存器，对于不同变量的写入不同寄存器地址
        writeRequest.setValue(0, modbusData);           // 写入该寄存器地址为1的位置，所以从0开始
        // 发送 Modbus RTU 写请求
        rtuMaster->sendWriteRequest(writeRequest, 1);  // 这里的1是从机地址也就是单片机的地址，数据帧writeRequest发送出去

        qDebug() << "Write request sent";
    }
    else
    {
        qDebug() << "Modbus RTU device is not connected";
    }
}

// /*
//  * kd输入的数据
//  */
 void Widget::on_pushButton_kd_clicked()
{
    if (rtuMaster->state() == QModbusDevice::ConnectedState)
    {
        // 获取发送的数据
        int sendkd = ui->spinBox_3->value();
        //实时显示出kp值
        ui->textEdit_kd->clear();
        ui->textEdit_kd->append(QString::number(sendkd));
        qDebug() <<sendkd;
        // 将整数值转换为Modbus RTU数据类型（保持寄存器）
        quint16 modbusData;
        if (sendkd >= 0) {
            modbusData = static_cast<quint16>(sendkd);
        } else {
            modbusData = static_cast<quint16>(65536 + sendkd);  // 负数需要转换为补码形式
        }
        // 创建写请求
        QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters,2, 1);  // 使用保持寄存器，从地址0开始，写入1个寄存器，对于不同变量的写入不同寄存器地址
        writeRequest.setValue(0, modbusData);
        // 发送 Modbus RTU 写请求
        rtuMaster->sendWriteRequest(writeRequest, 1);  // 这里的1是从机地址也就是单片机的地址，数据帧writeRequest发送出去

        qDebug() << "Write request sent";
    }
    else
    {
        qDebug() << "Modbus RTU device is not connected";
    }
}


// /*
//  * 距离输入的数据
//  */


void Widget::on_pushButton_2_clicked()
{
    if (rtuMaster->state() == QModbusDevice::ConnectedState)
    {
        // 获取发送的数据
        int d = ui->spinBox_4->value();
        int d1 = ui->spinBox_5->value();
        //实时显示出kp值
        ui->textEdit_D->clear();
        ui->textEdit_D->append(QString::number(d));
        ui->textEdit_D_2->clear();
        ui->textEdit_D_2->append(QString::number(d1));
        qDebug() <<d;
        // 将整数值转换为Modbus RTU数据类型（保持寄存器）
        quint16 modbusData;
        if (d >= 0) {
            modbusData = static_cast<quint16>(d);
        } else {
            modbusData = static_cast<quint16>(65536 + d);  // 负数需要转换为补码形式
        }
        quint16 modbusData1;
        if (d >= 0) {
            modbusData1 = static_cast<quint16>(d1);
        } else {
            modbusData1 = static_cast<quint16>(65536 + d1);  // 负数需要转换为补码形式
        }
        // 创建写请求
        QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters,3, 1);  // 使用保持寄存器，从地址0开始，写入1个寄存器，对于不同变量的写入不同寄存器地址
        writeRequest.setValue(0, modbusData);
        // 发送 Modbus RTU 写请求，不等待回应
        rtuMaster->sendWriteRequest(writeRequest, 1);  // 这里的1是从机地址也就是单片机的地址，数据帧writeRequest发送出去
        qDebug() << "Write request sent";
        // 创建写请求
        QModbusDataUnit writeRequest1(QModbusDataUnit::HoldingRegisters,4, 1);  // 使用保持寄存器，从地址0开始，写入1个寄存器，对于不同变量的写入不同寄存器地址
        writeRequest1.setValue(0, modbusData1);
        // 发送 Modbus RTU 写请求，不等待回应
        rtuMaster->sendWriteRequest(writeRequest1, 1);  // 这里的1是从机地址也就是单片机的地址，数据帧writeRequest发送出去
        qDebug() << "Write request sent";
    }
    else
    {
        qDebug() << "Modbus RTU device is not connected";
    }
}

