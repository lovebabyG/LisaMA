#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "globaldefine.h"
#include "Manager.h"
#include "CEO.h"


namespace Ui {
class MainWindow;
}

class QFile;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void parseData();

    void parseManagerDataInMac(QFile& file, QList<Manager>& managerList);

    void parseManagerDataInWin(QFile& file, QList<Manager>& managerList);

    void parseLineToManager(const QStringList& line, Manager& manager);

    void handelManagerList(QList<Manager>& managerList);

    void printManagerResult(QList<Manager>& managerList);

    void parseCEOData();

    void parseCEODataInMac(QFile& file, QList<CEO>& ceoList);

    void parseLineToCEO(const QStringList& line, CEO& ceo);

    void printCEOData(QList<CEO>& ceoList);

    void handelCEOList(QList<CEO>& ceoList);

    void printCEOResult(QList<CEO>& managerList);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
