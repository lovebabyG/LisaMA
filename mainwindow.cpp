#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QDir>

bool debug = false;
bool csvConvertedinMac = true;

QStringList keyWordListOfEliteUni = {"Oxford", // University of Oxford
                                     "Cambridge", // University of Cambridge
                                     "California", // California Institute of Technology; University of California, Los Angeles; University of California, Berkeley
                                     "Stanford", // Stanford University
                                     "Massachusetts", // Massachusetts Institute of Technology
                                     "Harvard", // Harvard University
                                     "Princeton", // Princeton University
                                     "Imperial", // Imperial College London
                                     "Chicago", // University of Chicago
                                     "Zurich", // ETH Zurich – Swiss Federal Institute of Technology Zurich
                                     "Pennsylvania", // University of Pennsylvania
                                     "Yale", // Yale University
                                     "Johns Hopkins", // Johns Hopkins University
                                     "Columbia", // Columbia University
                                     "UCL", // UCL
                                     "Duke University", // Duke University
                                     "Cornell", // Cornell University
                                     "Northwestern" // Northwestern University
                                    };


const int match_id_index = 0;
const int bachelor01_university_index = 1;
const int bachelor01_university_standardiz_index = 2;
const int bachelor01_degree_index = 3;
const int bachelor01_degree_standardized_index = 4;

const int bachelor02_university_index = 5;
const int bachelor02_university_standardiz_index = 6;
const int bachelor02_degree_index = 7;
const int bachelor02_degree_standardized_index = 8;

const int master01_university_index = 9;
const int master01_university_standardized_index = 10;
const int master01_degree_index = 11;
const int master01_degree_standardized_index = 12;

const int master02_university_index = 13;
const int master02_university_standardized_index = 14;
const int master02_degree_index = 15;
const int master02_degree_standardized_index = 16;

const int mba01_university_index = 17;
const int mba01_university_standardized_index = 18;
const int mba01_degree_index = 19;
const int mba01_degree_standardized_index = 20;

const int mba02_university_index = 21;
const int mba02_university_standardized_index = 22;
const int mba02_degree_index = 23;
const int mba02_degree_standardized_index = 24;

const int phd01_university_index = 25;
const int phd01_university_standardized_index = 26;
const int phd01_degree_index = 27;
const int phd01_degree_standardized_index = 28;

const int phd02_university_index = 29;
const int phd02_university_standardized_index = 30;
const int phd02_degree_index = 31;
const int phd02_degree_standardized_index = 32;

const int jd01_university_index = 33;
const int jd01_university_standardized_index = 34;
const int jd01_degree_index = 35;
const int jd01_degree_standardized_index = 36;

const int other01_university_index = 37;
const int other01_university_standardized_index = 38;
const int other01_degree_index = 39;
const int other01_degree_standardized_index = 40;

const int last_end_index = 41;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),\
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QString filePath = "\Users\yijia_gong\workspace\QtProjects\test\test1.txt";
    qDebug() << "filePath = "<< filePath;

    QFile inputFile(filePath);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        QList<int> numberOfCompanies;

        while (!in.atEnd())
        {
            QString line = in.readLine();
            numberOfCompanies.push_back( (line.count(QChar(','), Qt::CaseInsensitive) + 1) );
        }
        inputFile.close();

        for (int i = 0; i < numberOfCompanies.size(); ++i)
        {
\\            qDebug("i = %d, numberOfCompanies = %d", i+1, numberOfCompanies.at(i));
            qDebug("%d", numberOfCompanies.at(i));
        }
    }
    */

    parseData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parseData()
{
    QString filePath;
    if (csvConvertedinMac)
    {
//        filePath = "/Users/yijia_gong/workspace/QtProjects/test/InvestManagerData.csv";
        filePath = "D:/workspace/qt project/LisaMA-master/LisaMA/InvestManagerData.csv";
    }
    else
    {
        filePath = "D:/workspace/qt project/LisaMA-master/InvestManagerData.csv";
    }


    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        qDebug() << "current path = " << QDir::currentPath();
        return;
    }

    QList<Manager> managerList;

    if (csvConvertedinMac)
    {
       parseDataInMac(file, managerList);
    }
    else
    {
        parseDataInWin(file, managerList);
    }

    file.close();

    handelManagerList(managerList);

    outputResult(managerList);
}

void MainWindow::parseDataInMac(QFile& file, QList<Manager>& managerList)
{
    QString dataReplaced;
    while (!file.atEnd())
    {
           QByteArray line = file.readLine();
           QString data = line.data();
           QString newData1 = data.replace("\r\n", "\n");
           dataReplaced = newData1.replace("\r", "\n");
   }

   QStringList lines = dataReplaced.split(QChar('\n'));

   for (int j = 0; j < lines.size(); ++j)
   {
       QString line = lines.at(j);
       QStringList splitLineData = line.split(QChar(';'), QString::KeepEmptyParts, Qt::CaseInsensitive);

       Manager manager;
       parseLineToManager(splitLineData, manager);
       managerList.push_back(manager);
   }
}

void MainWindow::parseDataInWin(QFile& file, QList<Manager>& managerList)
{
    QTextStream in(&file);

    int j = 0;

    while (!in.atEnd())
    {
        qDebug() << j;
        j++;

        QString line = in.readLine();
        QStringList splitLineData = line.split(QChar(';'), QString::KeepEmptyParts, Qt::CaseInsensitive);

        Manager manager;
        parseLineToManager(splitLineData, manager);
        managerList.push_back(manager);

    }
}

void MainWindow::parseLineToManager(const QStringList& line, Manager& manager)
{
    for (int i = 0; i < line.size(); ++i)
    {
        if (i >= last_end_index)
        {
            continue;
        }
        QString data = line.at(i);
        switch (i)
        {
            case match_id_index:
            bool ok;
            manager.match_id = data.toInt(&ok);
            break;

            case bachelor01_university_index:
            manager.bachelor01_university = data;
            break;
            case bachelor01_university_standardiz_index:
            manager.bachelor01_university_standardized = data;
            break;
            case bachelor01_degree_index:
            manager.bachelor01_degree = data;
            break;
            case bachelor01_degree_standardized_index:
            manager.bachelor01_degree_standardized = data;
            break;

            case bachelor02_university_index:
            manager.bachelor02_university = data;
            break;
            case bachelor02_university_standardiz_index:
            manager.bachelor02_university_standardized = data;
            break;
            case bachelor02_degree_index:
            manager.bachelor02_degree = data;
            break;
            case bachelor02_degree_standardized_index:
            manager.bachelor02_degree_standardized = data;
            break;

            case master01_university_index:
            manager.master01_university = data;
            break;
            case master01_university_standardized_index:
            manager.master01_university_standardized = data;
            break;
            case master01_degree_index:
            manager.master01_degree = data;
            break;
            case master01_degree_standardized_index:
            manager.master01_degree_standardized = data;
            break;

            case master02_university_index:
            manager.master02_university = data;
            break;
            case master02_university_standardized_index:
            manager.master02_university_standardized = data;
            break;
            case master02_degree_index:
            manager.master02_degree = data;
            break;
            case master02_degree_standardized_index:
            manager.master02_degree_standardized = data;
            break;

            case mba01_university_index:
            manager.mba01_university = data;
            break;
            case mba01_university_standardized_index:
            manager.mba01_university_standardized = data;
            break;
            case mba01_degree_index:
            manager.mba01_degree = data;
            break;
            case mba01_degree_standardized_index:
            manager.mba01_degree_standardized = data;
            break;

            case mba02_university_index:
            manager.mba02_university = data;
            break;
            case mba02_university_standardized_index:
            manager.mba02_university_standardized = data;
            break;
            case mba02_degree_index:
            manager.mba02_degree = data;
            break;
            case mba02_degree_standardized_index:
            manager.mba02_degree_standardized = data;
            break;

            case phd01_university_index:
            manager.phd01_university = data;
            break;
            case phd01_university_standardized_index:
            manager.phd01_university_standardized = data;
            break;
            case phd01_degree_index:
            manager.phd01_degree = data;
            break;
            case phd01_degree_standardized_index:
            manager.phd01_degree_standardized = data;
            break;

            case phd02_university_index:
            manager.phd02_university = data;
            break;
            case phd02_university_standardized_index:
            manager.phd02_university_standardized = data;
            break;
            case phd02_degree_index:
            manager.phd02_degree = data;
            break;
            case phd02_degree_standardized_index:
            manager.phd02_degree_standardized = data;
            break;

            case jd01_university_index:
            manager.jd01_university = data;
            break;
            case jd01_university_standardized_index:
            manager.jd01_university_standardized = data;
            break;
            case jd01_degree_index:
            manager.jd01_degree = data;
            break;
            case jd01_degree_standardized_index:
            manager.jd01_degree_standardized = data;
            break;

            case other01_university_index:
            manager.other01_university = data;
            break;
            case other01_university_standardized_index:
            manager.other01_university_standardized = data;
            break;
            case other01_degree_index:
            manager.other01_degree = data;
            break;
            case other01_degree_standardized_index:
            manager.other01_degree_standardized = data;
            break;

        }
    }
}

void MainWindow::handelManagerList(QList<Manager>& managerList)
{
    for (int i = 0; i < managerList.size(); ++i)
    {
        Manager& manager = managerList[i];
        manager.ceoLevelEdu = Manager::not_available;
        manager.hasPHD = false;
        manager.hasMBA = false;
        manager.hasJD = false;

        if (!manager.phd01_university.isEmpty() || !manager.phd01_university_standardized.isEmpty() || !manager.phd01_degree.isEmpty() || !manager.phd01_degree_standardized.isEmpty() ||
            !manager.phd02_university.isEmpty() || !manager.phd02_university_standardized.isEmpty() || !manager.phd02_degree.isEmpty() || !manager.phd02_degree_standardized.isEmpty() ||
            !manager.jd01_university.isEmpty()  || !manager.jd01_university_standardized.isEmpty()  || !manager.jd01_degree.isEmpty()  || !manager.jd01_degree_standardized.isEmpty())
        {
            manager.ceoLevelEdu = Manager::phd;
        }
        else if (!manager.mba01_university.isEmpty() || !manager.mba01_university_standardized.isEmpty() || !manager.mba01_degree.isEmpty() || !manager.mba01_degree_standardized.isEmpty() ||
                 !manager.mba02_university.isEmpty() || !manager.mba02_university_standardized.isEmpty() || !manager.mba02_degree.isEmpty() || !manager.mba02_degree_standardized.isEmpty())
        {
            manager.ceoLevelEdu = Manager::mba;
        }
        else if (!manager.master01_university.isEmpty() || !manager.master01_university_standardized.isEmpty() || !manager.master01_degree.isEmpty() || !manager.master01_degree_standardized.isEmpty() ||
                 !manager.master02_university.isEmpty() || !manager.master02_university_standardized.isEmpty() || !manager.master02_degree.isEmpty() || !manager.master02_degree_standardized.isEmpty())
        {
            manager.ceoLevelEdu = Manager::master;
        }
        else if (!manager.bachelor01_university.isEmpty() || !manager.bachelor01_university_standardized.isEmpty() || !manager.bachelor01_degree.isEmpty() || !manager.bachelor01_degree_standardized.isEmpty() ||
                 !manager.bachelor02_university.isEmpty() || !manager.bachelor02_university_standardized.isEmpty() || !manager.bachelor02_degree.isEmpty() || !manager.bachelor02_degree_standardized.isEmpty())
        {
            manager.ceoLevelEdu = Manager::bachelor;
        }


        if (!manager.phd01_university.isEmpty() || !manager.phd01_university_standardized.isEmpty() || !manager.phd01_degree.isEmpty() || !manager.phd01_degree_standardized.isEmpty() ||
            !manager.phd02_university.isEmpty() || !manager.phd02_university_standardized.isEmpty() || !manager.phd02_degree.isEmpty() || !manager.phd02_degree_standardized.isEmpty())
        {
            manager.hasPHD = true;
        }

        if (!manager.mba01_university.isEmpty() || !manager.mba01_university_standardized.isEmpty() || !manager.mba01_degree.isEmpty() || !manager.mba01_degree_standardized.isEmpty() ||
            !manager.mba02_university.isEmpty() || !manager.mba02_university_standardized.isEmpty() || !manager.mba02_degree.isEmpty() || !manager.mba02_degree_standardized.isEmpty())
        {
            manager.hasMBA = true;
        }

        if (!manager.jd01_university.isEmpty()  || !manager.jd01_university_standardized.isEmpty()  || !manager.jd01_degree.isEmpty()  || !manager.jd01_degree_standardized.isEmpty())
        {
            manager.hasJD = true;
        }



        if (debug)
        {
        qDebug("i = %d, match_id = %d,\
                bachelor01_university = %s,\
                bachelor01_university_standardiz = %s,\
                bachelor01_degree = %s,\
                bachelor01_degree_standardized = %s,\
                bachelor02_university = %s,\
                bachelor02_university_standardiz = %s,\
                bachelor02_degree = %s,\
                bachelor02_degree_standardized = %s,\
                master01_university = %s,\
                master01_university_standardized = %s,\
                master01_degree = %s,\
                master01_degree_standardized = %s,\
                master02_university = %s,\
                master02_university_standardized = %s,\
                master02_degree = %s,\
                master02_degree_standardized = %s,\
                mba01_university = %s,\
                mba01_university_standardized = %s,\
                mba01_degree = %s,\
                mba01_degree_standardized = %s,\
                mba02_university = %s,\
                mba02_university_standardized = %s,\
                mba02_degree = %s,\
                mba02_degree_standardized = %s,\
                phd01_university = %s,\
                phd01_university_standardized = %s,\
                phd01_degree = %s,\
                phd01_degree_standardized = %s,\
                phd02_university = %s,\
                phd02_university_standardized = %s,\
                phd02_degree = %s,\
                phd02_degree_standardized = %s,\
                jd01_university = %s,\
                jd01_university_standardized = %s,\
                jd01_degree = %s,\
                jd01_degree_standardized = %s,\
                other01_university = %s,\
                other01_university_standardized = %s,\
                other01_degree = %s,\
                other01_degree_standardized = %s",\
                i, manager.match_id,\
                   manager.bachelor01_university.toStdString().c_str(),\
                   manager.bachelor01_university_standardized.toStdString().c_str(),\
                   manager.bachelor01_degree.toStdString().c_str(),\
                   manager.bachelor01_degree_standardized.toStdString().c_str(),\
                   manager.bachelor02_university.toStdString().c_str(),\
                   manager.bachelor02_university_standardized.toStdString().c_str(),\
                   manager.bachelor02_degree.toStdString().c_str(),\
                   manager.bachelor02_degree_standardized.toStdString().c_str(),\
                   manager.master01_university.toStdString().c_str(),\
                   manager.master01_university_standardized.toStdString().c_str(),\
                   manager.master01_degree.toStdString().c_str(),\
                   manager.master01_degree_standardized.toStdString().c_str(),\
                   manager.master02_university.toStdString().c_str(),\
                   manager.master02_university_standardized.toStdString().c_str(),\
                   manager.master02_degree.toStdString().c_str(),\
                   manager.master02_degree_standardized.toStdString().c_str(),\
                   manager.mba01_university.toStdString().c_str(),\
                   manager.mba01_university_standardized.toStdString().c_str(),\
                   manager.mba01_degree.toStdString().c_str(),\
                   manager.mba01_degree_standardized.toStdString().c_str(),\
                   manager.mba02_university.toStdString().c_str(),\
                   manager.mba02_university_standardized.toStdString().c_str(),\
                   manager.mba02_degree.toStdString().c_str(),\
                   manager.mba02_degree_standardized.toStdString().c_str(),\
                   manager.phd01_university.toStdString().c_str(),\
                   manager.phd01_university_standardized.toStdString().c_str(),\
                   manager.phd01_degree.toStdString().c_str(),\
                   manager.phd01_degree_standardized.toStdString().c_str(),\
                   manager.phd02_university.toStdString().c_str(),\
                   manager.phd02_university_standardized.toStdString().c_str(),\
                   manager.phd02_degree.toStdString().c_str(),\
                   manager.phd02_degree_standardized.toStdString().c_str(),\
                   manager.jd01_university.toStdString().c_str(),\
                   manager.jd01_university_standardized.toStdString().c_str(),\
                   manager.jd01_degree.toStdString().c_str(),\
                   manager.jd01_degree_standardized.toStdString().c_str(),\
                   manager.other01_university.toStdString().c_str(),\
                   manager.other01_university_standardized.toStdString().c_str(),\
                   manager.other01_degree.toStdString().c_str(),\
                   manager.other01_degree_standardized.toStdString().c_str());
        }
    }


}

void MainWindow::outputResult(QList<Manager>& managerList)
{
    for (int i = 0; i < managerList.size(); ++i)
    {

        qDebug("match_id = %5d, phd = %d, mba = %d, jd = %d", managerList.at(i).match_id, managerList.at(i).hasPHD, managerList.at(i).hasMBA, managerList.at(i).hasJD);


//        if (managerList.at(i).ceoLevelEdu != Manager::not_available)
//        {
////            qDebug("match_id = %5d, ceoLevel = %d", managerList.at(i).match_id, managerList.at(i).ceoLevelEdu);
//            qDebug("%d", managerList.at(i).ceoLevelEdu);
//        }
//        else
//        {
////            qDebug("match_id = %5d, ceoLevel =  ", managerList.at(i).match_id);
//            qDebug("");
//        }
    }
}
