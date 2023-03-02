#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define MAX_LEN 18

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
    double result;
    QString cleareNums(char *data);
    void deleteLast(QString *data);
    void cleareLable(QString *data);
    QString checkCalc(QString data);
    void calc(QString data, char c);
    void setEnabledToBtn();

private slots:
    void numBtn();
    void cleareBtn();
    void dotBtn();
    void arifmeticBtn();
    void delBtn();
};
#endif // MAINWINDOW_H
