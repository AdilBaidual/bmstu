#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "string.h"
#include <QMessageBox>
#include "calcFunctions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_cleare, SIGNAL(clicked()), this, SLOT(cleareBtn()));
    connect(ui->btn_dot, SIGNAL(clicked()), this, SLOT(dotBtn()));
    connect(ui->btn_plus, SIGNAL(clicked()), this, SLOT(arifmeticBtn()));
    connect(ui->btn_minus, SIGNAL(clicked()), this, SLOT(arifmeticBtn()));
    connect(ui->btn_multiply, SIGNAL(clicked()), this, SLOT(arifmeticBtn()));
    connect(ui->btn_divide, SIGNAL(clicked()), this, SLOT(arifmeticBtn()));
    connect(ui->btn_equals, SIGNAL(clicked()), this, SLOT(arifmeticBtn()));
    connect(ui->btn_del, SIGNAL(clicked()), this, SLOT(delBtn()));

    connect(ui->btn_0, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_1, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_2, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_3, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_4, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_5, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_6, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_7, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_8, SIGNAL(clicked()), this, SLOT(numBtn()));
    connect(ui->btn_9, SIGNAL(clicked()), this, SLOT(numBtn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::checkCalc(QString data) {
    std::string stdStr = (data).toStdString();
    const char* str = stdStr.c_str();
    if (my_strstr(str, "inf") == 1) {
        data = QString('0');
        QMessageBox::critical(this, "error", "вводите значения нормально!");
    } else if (my_strstr(str, "nan") == 1) {
        data = QString('0');
        qDebug() << "Original String: " << data;
        QMessageBox::critical(this, "error", "вводите значения нормально!");
    }
    return data;
}

void MainWindow::calc(QString data, char c) {
    switch (c) {
    case '+':
        result += data.toDouble();
        qDebug() << "+: " << result;
        break;
    case '-':
        result += data.toDouble();
        break;
    case '*':
        result *= data.mid(1, data.length()).toDouble();
        break;
    case '/':
        result /= data.mid(1, data.length()).toDouble();
        break;
    }
    qDebug() << "Original String: " << result;
    qDebug() << "Original String: " << data.toDouble();
}

void MainWindow::setEnabledToBtn() {
    ui->btn_dot->setEnabled(true);
    ui->btn_del->setEnabled(true);
}

void MainWindow::delBtn() {
    QPushButton *btn = (QPushButton *)sender();
    QString data = this->ui->label->text();
    std::string stdStr = (data).toStdString();
    const char* str = stdStr.c_str();
    setEnabledToBtn();
    if (checkE(str) == 0) {
        data = data.mid(0,data.length()-1);
        if (data.length() == 0) {
            result = 0;
        }
        this->ui->label->setText(data);
    } else {
        btn->setEnabled(false);
    }
}

void MainWindow::arifmeticBtn() {
    setEnabledToBtn();
    QPushButton *btn = (QPushButton *)sender();
    QString data = this->ui->label->text();
    std::string stdStr = (data).toStdString();
    const char* str = stdStr.c_str();
    int len = strlen(str);
    if (isNumber(str[0]) == 1 || str[0] == '.') {
        result = data.toDouble();
        qDebug() << "1: " << result;
    }
    if (isSign(str[0])) {
        calc(data, str[0]);
    }
    data = btn->text();
    if (data == '=') {
        data = QString::number(result);
    }
    data = checkCalc(data);
    this->ui->label->setText(data);
}

void MainWindow::dotBtn() {
    QPushButton *btn = (QPushButton *)sender();
    QString data = this->ui->label->text();
    std::string stdStr = (data).toStdString();
    const char* str = stdStr.c_str();
    int index = rfind(str);
    int len = strlen(str);
    char tmp[len-index+1];
    strcpy(tmp, str+index+1);
    data = checkCalc(data);
    if (strcount(tmp, '.') == 0 && data.length() < MAX_LEN && checkE(str) == 0) {
        data += btn->text();
        btn->setEnabled(false);
    } else if (checkE(str) == 1) {
        btn->setEnabled(false);
    }
    this->ui->label->setText(data);
}

void MainWindow::cleareBtn() {
    result = 0;
    setEnabledToBtn();
    this->ui->label->setText(QString());
}

void MainWindow::numBtn() {
    QPushButton *btn = (QPushButton *)sender();
    QString data = this->ui->label->text();
    std::string stdStr = (data).toStdString();
    const char* str = stdStr.c_str();
    if (data.length() < MAX_LEN && checkE(str) == 0) {
        data += btn->text();
        if (strcount(str, '.') == 0 && isSign(str[0]) == 0) {
            data = QString::number(data.toLongLong());
        } else if (strcount(str, '.') == 0 && isSign(str[0]) == 1) {
            data = data.at(0) + QString::number(data.mid(1, data.length()).toLongLong());
        }
    }
    this->ui->label->setText(data);
}
