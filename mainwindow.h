#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}


class Manager
{
public:

    enum CEOLevelEdu
    {
        no = 0,
        bachelor = 1,
        master = 2,
        mba = 3,
        phd = 4,
        not_available = 5
    };


    int match_id;
    QString bachelor01_university;
    QString bachelor01_university_standardized;
    QString bachelor01_degree;
    QString bachelor01_degree_standardized;

    QString bachelor02_university;
    QString bachelor02_university_standardized;
    QString bachelor02_degree;
    QString bachelor02_degree_standardized;

    QString master01_university;
    QString master01_university_standardized;
    QString master01_degree;
    QString master01_degree_standardized;

    QString master02_university;
    QString master02_university_standardized;
    QString master02_degree;
    QString master02_degree_standardized;

    QString mba01_university;
    QString mba01_university_standardized;
    QString mba01_degree;
    QString mba01_degree_standardized;

    QString mba02_university;
    QString mba02_university_standardized;
    QString mba02_degree;
    QString mba02_degree_standardized;

    QString phd01_university;
    QString phd01_university_standardized;
    QString phd01_degree;
    QString phd01_degree_standardized;

    QString phd02_university;
    QString phd02_university_standardized;
    QString phd02_degree;
    QString phd02_degree_standardized;

    QString jd01_university;
    QString jd01_university_standardized;
    QString jd01_degree;
    QString jd01_degree_standardized;

    QString other01_university;
    QString other01_university_standardized;
    QString other01_degree;
    QString other01_degree_standardized;

    CEOLevelEdu ceoLevelEdu;
    bool hasMBA;
    bool hasPHD;
    bool hasJD;
    bool isEliteUni;


};

class QFile;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void parseData();

    void parseDataInMac(const QStringList& lines, QList<Manager>& managerList);

    void parseDataInWin(QFile& file);

    void outputResult(QList<Manager>& managerList);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
