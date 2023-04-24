#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>

#include "tableWork.h"
#include "metric.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void outputData(int rowLen, int collumLen, char ***data);
    bool checkInput(const char *region);
    metricInit getDataFromTable(const char *region, int col);

private slots:
    void fileOpen();
    void dataLoad();
    void calcMetrics();
};
#endif // MAINWINDOW_H
