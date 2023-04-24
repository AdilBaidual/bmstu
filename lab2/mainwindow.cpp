#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(fileOpen()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(dataLoad()));
    connect(ui->calcButton, SIGNAL(clicked()), this, SLOT(calcMetrics()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileOpen() {
    QString pathFileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "CSV File (*.csv)");
    ui->FilePathLabel->setText(pathFileName);
}

QStringList ConvertRowToQTFormat(char **row, size_t size)
{
    QStringList qsl = {};

    for(size_t i = 0; i < size; i++)
    {
        qsl.append(QString::fromUtf8(row[i]));
    }

    return qsl;
}

void MainWindow::dataLoad() {
    QString qpath = this->ui->FilePathLabel->text();
    QString qregion = this->ui->regionInput->text();
    QString qcolum = this->ui->columnInput->text();
    const char* region = ((qregion).toStdString()).c_str();
    const char* path = ((qpath).toStdString()).c_str();
    //qDebug() << "Result: " << qcolum.toInt();
    if (checkInput(region)) {
        tableStruct table = getData(path, region, qcolum.toInt());
        char ***data = table.data;
        if (!(table.error)) {
            if (data != NULL) {
                outputData(table.rowLen, table.collumLen, data);
            } else {
                ui->tableWindow->clear();
                ui->tableWindow->setRowCount(0);
                ui->tableWindow->setColumnCount(0);
            }
        } else {
            //месседж
        }
    } else {
        //месседж
    }
}

void MainWindow::outputData(int rowLen, int collumLen, char ***data) {
    ui->tableWindow->setColumnCount(collumLen);
    QStringList QColumns = ConvertRowToQTFormat(data[0], collumLen);
    ui->tableWindow->setHorizontalHeaderLabels(QColumns);
    ui->tableWindow->setRowCount(0);
    ui->tableWindow->setEditTriggers(QTableWidget::NoEditTriggers);
    for (int i = 0; i < rowLen - 1; i++) {
        QStringList currentRow = ConvertRowToQTFormat(data[i + 1], collumLen);
        ui->tableWindow->setRowCount(i + 1);
        for (int j = 0; j < currentRow.count(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setData(Qt::EditRole, currentRow.at(j).toDouble());
            item->setText(currentRow.at(j));
            ui->tableWindow->setItem(i, j, item);
        }
    }
}

bool MainWindow::checkInput(const char *region) {
    bool res = true;
    if (strlen(region) == 0) {
        res = false;
    }
    return res;
}

char* QstringToCharArray(QString qstr) {
    char *str = (char*)malloc(sizeof(char)*(qstr.size() + 1));
    size_t i;
    if (str != NULL) {
        for (i = 0; i < qstr.size(); i++) {
            str[i] = qstr.at(i).unicode();
        }
        str[i] = 0;
    }
    return str;
}

metricInit MainWindow::getDataFromTable(const char *region, int col) {
    double *data = (double *)malloc(sizeof(double));
    int count = 1;
    if (data != NULL) {
        for (size_t i = 0; i < (size_t)ui->tableWindow->rowCount(); i++) {
            bool flag = false;
            int num;
            for (size_t j = 0; j < (size_t)ui->tableWindow->columnCount(); j++) {
                QTableWidgetItem *item = ui->tableWindow->item(i,j);\
                char* str = QstringToCharArray(item->text());
                if (str == NULL) {
                    continue;
                }
                if (j == col) {
                    num = item->text().toDouble();
                }
                if (strcmp(str, region) == 0) {
                    flag = true;
                }
            }
            if (flag) {
                data[count-1] = num;
                count++;
                data = (double *)realloc(data, sizeof(double) * count);
            }
            if (data == NULL) {
                break;
            }
        }
    }
    metricInit init;
    init.data = data;
    init.rowLen = count - 1;
    return init;
}


void MainWindow::calcMetrics() {
    QString qregion = this->ui->regionInput->text();
    QString qcolum = this->ui->columnInput->text();
    const char* region = ((qregion).toStdString()).c_str();
    int col = qcolum.toInt();
    if (col != 0) {
        col--;
    }
    if (col <= (int)ui->tableWindow->columnCount()) {
        metricInit init = getDataFromTable(region, col);
        if (init.data != NULL) {
            for (int i = 0; i < init.rowLen; i++) {
                qDebug() << init.data[i];
            }
            qDebug() << "CALC";
            metrics result = calc(init);
            qDebug() << result.max;
            qDebug() << result.min;
            qDebug() << result.median;
            qDebug() << "DONE";
            QString res = QString("max ") + QString::number(result.max) + QString(" min ") + QString::number(result.min) + QString(" median ") + QString::number(result.median);
            ui->resultLabel->setText(res);
        } else {
            //выводить ошибку
        }
    } else {

    }
}


