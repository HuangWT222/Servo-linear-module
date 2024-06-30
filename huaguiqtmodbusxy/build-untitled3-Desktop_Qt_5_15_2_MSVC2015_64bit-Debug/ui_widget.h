/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSpinBox *spinBox;
    QPushButton *pushButton_kp;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_ki;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_kd;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QSlider *horizontalSlider;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_kd_2;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_kd_3;
    QTimeEdit *timeEdit_2;
    QTextEdit *textEdit_kp;
    QLabel *label_7;
    QLabel *label_12;
    QLabel *label_13;
    QTextEdit *textEdit_ki;
    QTextEdit *textEdit_kd;
    QTextEdit *textEdit_D;
    QLabel *label_14;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(864, 637);
        Widget->setMinimumSize(QSize(864, 637));
        Widget->setMaximumSize(QSize(864, 637));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 10, 141, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 500, 171, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        pushButton->setFont(font1);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 90, 231, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout_3->addWidget(label_4);

        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_3->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        horizontalLayout_4->addWidget(label_5);

        comboBox_4 = new QComboBox(layoutWidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        horizontalLayout_4->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        horizontalLayout_5->addWidget(label_6);

        comboBox_5 = new QComboBox(layoutWidget);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        horizontalLayout_5->addWidget(comboBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(590, 90, 251, 221));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        horizontalLayout_7->addWidget(label_8);

        spinBox = new QSpinBox(layoutWidget1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QFont font3;
        font3.setPointSize(12);
        spinBox->setFont(font3);
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(1);

        horizontalLayout_7->addWidget(spinBox);

        pushButton_kp = new QPushButton(layoutWidget1);
        pushButton_kp->setObjectName(QString::fromUtf8("pushButton_kp"));
        pushButton_kp->setFont(font3);

        horizontalLayout_7->addWidget(pushButton_kp);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        horizontalLayout_8->addWidget(label_9);

        spinBox_2 = new QSpinBox(layoutWidget1);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setFont(font3);
        spinBox_2->setMinimum(-1000);
        spinBox_2->setMaximum(1000);
        spinBox_2->setSingleStep(1);

        horizontalLayout_8->addWidget(spinBox_2);

        pushButton_ki = new QPushButton(layoutWidget1);
        pushButton_ki->setObjectName(QString::fromUtf8("pushButton_ki"));
        pushButton_ki->setFont(font3);

        horizontalLayout_8->addWidget(pushButton_ki);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        horizontalLayout_9->addWidget(label_10);

        spinBox_3 = new QSpinBox(layoutWidget1);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setFont(font3);
        spinBox_3->setMinimum(-1000);
        spinBox_3->setMaximum(1000);
        spinBox_3->setSingleStep(1);

        horizontalLayout_9->addWidget(spinBox_3);

        pushButton_kd = new QPushButton(layoutWidget1);
        pushButton_kd->setObjectName(QString::fromUtf8("pushButton_kd"));
        pushButton_kd->setFont(font3);

        horizontalLayout_9->addWidget(pushButton_kd);


        verticalLayout_2->addLayout(horizontalLayout_9);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(320, 480, 471, 134));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        horizontalLayout_6->addWidget(label_11);

        horizontalSlider = new QSlider(layoutWidget2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QFont font4;
        font4.setBold(false);
        horizontalSlider->setFont(font4);
        horizontalSlider->setMinimum(-130);
        horizontalSlider->setMaximum(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);

        horizontalLayout_6->addWidget(horizontalSlider);

        spinBox_4 = new QSpinBox(layoutWidget2);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setFont(font3);
        spinBox_4->setMinimum(-130);
        spinBox_4->setMaximum(0);
        spinBox_4->setSingleStep(1);

        horizontalLayout_6->addWidget(spinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font3);

        horizontalLayout_10->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font3);

        horizontalLayout_10->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_10);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(260, 90, 321, 281));
        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(590, 340, 251, 111));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButton_kd_2 = new QPushButton(layoutWidget3);
        pushButton_kd_2->setObjectName(QString::fromUtf8("pushButton_kd_2"));
        pushButton_kd_2->setFont(font3);

        horizontalLayout_12->addWidget(pushButton_kd_2);

        timeEdit = new QTimeEdit(layoutWidget3);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setFont(font3);

        horizontalLayout_12->addWidget(timeEdit);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_kd_3 = new QPushButton(layoutWidget3);
        pushButton_kd_3->setObjectName(QString::fromUtf8("pushButton_kd_3"));
        pushButton_kd_3->setFont(font3);

        horizontalLayout_11->addWidget(pushButton_kd_3);

        timeEdit_2 = new QTimeEdit(layoutWidget3);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setFont(font3);

        horizontalLayout_11->addWidget(timeEdit_2);


        verticalLayout_4->addLayout(horizontalLayout_11);

        textEdit_kp = new QTextEdit(Widget);
        textEdit_kp->setObjectName(QString::fromUtf8("textEdit_kp"));
        textEdit_kp->setEnabled(true);
        textEdit_kp->setGeometry(QRect(400, 160, 95, 40));
        textEdit_kp->setFont(font);
        textEdit_kp->setFrameShape(QFrame::NoFrame);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 160, 41, 31));
        label_7->setFont(font2);
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(350, 200, 41, 31));
        label_12->setFont(font);
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(350, 240, 41, 31));
        label_13->setFont(font);
        textEdit_ki = new QTextEdit(Widget);
        textEdit_ki->setObjectName(QString::fromUtf8("textEdit_ki"));
        textEdit_ki->setEnabled(true);
        textEdit_ki->setGeometry(QRect(400, 200, 95, 40));
        textEdit_ki->setFont(font);
        textEdit_ki->setFrameShape(QFrame::NoFrame);
        textEdit_kd = new QTextEdit(Widget);
        textEdit_kd->setObjectName(QString::fromUtf8("textEdit_kd"));
        textEdit_kd->setEnabled(true);
        textEdit_kd->setGeometry(QRect(400, 240, 95, 40));
        textEdit_kd->setFont(font);
        textEdit_kd->setFrameShape(QFrame::NoFrame);
        textEdit_D = new QTextEdit(Widget);
        textEdit_D->setObjectName(QString::fromUtf8("textEdit_D"));
        textEdit_D->setEnabled(true);
        textEdit_D->setGeometry(QRect(390, 310, 95, 40));
        textEdit_D->setFont(font);
        textEdit_D->setFrameShape(QFrame::NoFrame);
        label_14 = new QLabel(Widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(790, 500, 69, 19));
        QFont font5;
        font5.setPointSize(14);
        label_14->setFont(font5);
        textEdit->raise();
        label->raise();
        pushButton->raise();
        layoutWidget1->raise();
        layoutWidget1->raise();
        layoutWidget1->raise();
        layoutWidget1->raise();
        textEdit_kp->raise();
        label_7->raise();
        label_12->raise();
        label_13->raise();
        textEdit_ki->raise();
        textEdit_kd->raise();
        textEdit_D->raise();
        label_14->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "   \347\253\257 \345\217\243 \357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\263\242 \347\211\271 \347\216\207 \357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "9600", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Widget", "4800", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Widget", "2400", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Widget", "1200", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("Widget", "19200", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("Widget", "38400", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("Widget", "57600", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("Widget", "115200", nullptr));

        label_4->setText(QCoreApplication::translate("Widget", "\346\225\260 \346\215\256 \344\275\215 \357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Widget", "8", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Widget", "7", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Widget", "6", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("Widget", "5", nullptr));

        label_5->setText(QCoreApplication::translate("Widget", "\345\201\234 \346\255\242 \344\275\215 \357\274\232", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Widget", "2", nullptr));

        label_6->setText(QCoreApplication::translate("Widget", "   \346\240\241 \351\252\214 \357\274\232", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("Widget", "none", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("Widget", "even", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("Widget", "odd", nullptr));

        label_8->setText(QCoreApplication::translate("Widget", "Kp\357\274\232", nullptr));
        pushButton_kp->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "Ki\357\274\232", nullptr));
        pushButton_ki->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "Kd\357\274\232", nullptr));
        pushButton_kd->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\344\275\215 \347\275\256 \357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\220\257\345\212\250", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; color:#a600e8;\">\346\254\242\350\277\216\344\275\277\347\224\250\346\234\254\344\270\262\345\217\243\345\212\251\346\211\213</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">\345\275\223\345\211\215\346\225\260"
                        "\345\200\274\344\270\272\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">	      </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:700;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">	     </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:700;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bo"
                        "ttom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">	      </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">\347\233\256\346\240\207\344\275\215\347\275\256\344\270\272\357\274\232</span></p></body></html>", nullptr));
        pushButton_kd_2->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\220\257\345\212\250", nullptr));
        pushButton_kd_3->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\205\263\351\227\255", nullptr));
        textEdit_kp->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:14pt; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">0</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Kp:", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "K i:", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "Kd:", nullptr));
        textEdit_ki->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:14pt; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">0</span></p></body></html>", nullptr));
        textEdit_kd->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:14pt; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">0</span></p></body></html>", nullptr));
        textEdit_D->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:14pt; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">0</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
