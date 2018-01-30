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

QStringList ExatNameListOfEliteUni = {
                                  "Oxford University",                 // University of Oxford
                                  "All Souls College, Oxford University",  // University of Oxford
                                  "University of Oxford",                  // University of Oxford
                                  "University College, Oxford University", // University of Oxford

                                  "University of Cambridge", // University of Cambridge
                                  "Murray Edwards College, Cambridge University (New Hall, Cambridge University prior to 06/2008)", // University of Cambridge
                                  "Judge Business School (Judge Institute of Management Studies prior to 09/2005)", // University of Cambridge
                                  "King's College Cambridge, University of Cambridge", // University of Cambridge
                                  "Christ's College, Cambridge University", // University of Cambridge
                                  "Gonville and Caius College, Cambridge University", // University of Cambridge
                                  "Downing College, Cambridge University", // University of Cambridge

                                  // California Institute of Technology; University of California, Los Angeles;
                                  "University of California, Berkeley", // University of California, Berkeley
                                  "University of California, Los Angeles", // University of California, Los Angeles
                                  "Anderson Graduate School of Management, University of California", // University of California, Los Angeles

                                  "Stanford", // Stanford University
                                  "Stanford University", // Stanford University
                                  "Stanford University, Graduate School of Business", // Stanford University
                                  "Stanford University School of Medicine", // Stanford University

                                  "Massachusetts Institute of Technology (MIT)", // Massachusetts Institute of Technology
                                  "University of Massachusetts, Medical School", // Massachusetts Institute of Technology
                                  "Massachusetts Institute of Technology", // Massachusetts Institute of Technology
                                  "Massachusetts Institute of Technology (MIT) Sloan School of Management", // Massachusetts Institute of Technology
                                  "MIT Sloan School of Management",

                                  "Harvard", // Harvard University
                                  "Harvard Business School", // Harvard University
                                  "Harvard University", // Harvard University
                                  "Harvard Graduate School of Arts and Sciences", // Harvard University
                                  "Harvard College", // Harvard University
                                  "Harvard Medical School", // Harvard University
                                  "Harvard Law School", // Harvard University

                                  "Princeton University", // Princeton University

                                  "Imperial College London", // Imperial College London
                                  "Imperial College London (The Imperial College of Science Technology and Medicine)", // Imperial College London

                                  "University of Chicago", // University of Chicago
                                  "Booth School of Business, University of Chicago", // University of Chicago

                                  "Eidgenossische Technische Hochschule Zurich (ETH) (Swiss Federal Institute of Technology Zurich)", // ETH Zurich – Swiss Federal Institute of Technology Zurich

                                  "University of Pennsylvania", // University of Pennsylvania
                                  "Wharton School, University of Pennsylvania", // University of Pennsylvania
                                  "Moore School of Electrical Engineering, University of Pennsylvania", // University of Pennsylvania

                                  "Yale School of Management", // Yale University
                                  "Yale University", // Yale University

                                  "Johns Hopkins University", // Johns Hopkins University
                                  "Johns Hopkins University School for Advanced International Studies", // Johns Hopkins University
                                  "Johns Hopkins University School for Advanced International Studies (SAIS)", // Johns Hopkins University

                                  "Columbia University", // Columbia University
                                  "Columbia Business School", // Columbia University
                                  "Columbia College, Columbia University", // Columbia University

                                  "University College London (UCL)", // UCL
                                  "University College London",

                                  "Duke University", // Duke University

                                  "Cornell University", // Cornell University
                                  "Cornell University School of Industrial and Labor Relations",

                                  "Northwestern University", // Northwestern University
                                  "Kellogg School of Management, Northwestern University" // Northwestern University
                                    };


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
                                     "Duke", // Duke University
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
        filePath = "/Users/yijia_gong/workspace/QtProjects/test/InvestManagerData.csv";
//        filePath = "D:/workspace/qt project/LisaMA-master/LisaMA/InvestManagerData.csv";
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

        // ceo edu level
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


        // phd mba JD
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

        // elite uni
        for (QString& ExatNameOfEliteUni : ExatNameListOfEliteUni)
        {
            if (ExatNameOfEliteUni == manager.phd01_university || ExatNameOfEliteUni == manager.phd01_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.phd02_university || ExatNameOfEliteUni == manager.phd02_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.jd01_university || ExatNameOfEliteUni == manager.jd01_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.mba01_university || ExatNameOfEliteUni == manager.mba01_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.mba02_university || ExatNameOfEliteUni == manager.mba02_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.master01_university || ExatNameOfEliteUni == manager.master01_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.master02_university || ExatNameOfEliteUni == manager.master02_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.bachelor01_university || ExatNameOfEliteUni == manager.bachelor01_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.bachelor02_university || ExatNameOfEliteUni == manager.bachelor02_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
            else if (ExatNameOfEliteUni == manager.other01_university || ExatNameOfEliteUni == manager.other01_university_standardized)
            {
                manager.isEliteUni = 1;
                break;
            }
        }

        if (1 != manager.isEliteUni)
        {
            for (QString &keyWordOfEliteUni: keyWordListOfEliteUni)
            {
                if (manager.phd01_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)      || manager.phd01_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, phd01_university      = %60s     phd01_university_standardized      = %20s", i+2, manager.match_id, manager.phd01_university.toStdString().c_str(), manager.phd01_university_standardized.toStdString().c_str());
                }

                if (manager.phd02_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)      || manager.phd02_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, phd02_university      = %60s     phd02_university_standardized      = %20s", i+2, manager.match_id, manager.phd02_university.toStdString().c_str(), manager.phd02_university_standardized.toStdString().c_str());
                }

                if (manager.jd01_university.contains(keyWordOfEliteUni,  Qt::CaseInsensitive)      || manager.jd01_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, jd01_university       = %60s      jd01_university_standardized       = %20s", i+2, manager.match_id, manager.jd01_university.toStdString().c_str(), manager.jd01_university_standardized.toStdString().c_str());
                }

                if (manager.mba01_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)      || manager.mba01_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, mba01_university      = %60s     mba01_university_standardized      = %20s", i+2, manager.match_id, manager.mba01_university.toStdString().c_str(), manager.mba01_university_standardized.toStdString().c_str());
                }

                if (manager.mba02_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)      || manager.mba02_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, mba02_university      = %60s     mba02_university_standardized      = %20s", i+2, manager.match_id, manager.mba02_university.toStdString().c_str(), manager.mba02_university_standardized.toStdString().c_str());
                }

                if (manager.master01_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)   || manager.master01_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, master01_university   = %60s     master01_university_standardized   = %20s", i+2, manager.match_id, manager.master01_university.toStdString().c_str(), manager.master01_university_standardized.toStdString().c_str());
                }

                if (manager.master02_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)   || manager.master02_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, master02_university   = %60s     master02_university_standardized   = %20s", i+2, manager.match_id, manager.master02_university.toStdString().c_str(), manager.master02_university_standardized.toStdString().c_str());
                }

                if (manager.bachelor01_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive) || manager.bachelor01_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, bachelor01_university = %60s     bachelor01_university_standardized = %20s", i+2, manager.match_id, manager.bachelor01_university.toStdString().c_str(), manager.bachelor01_university_standardized.toStdString().c_str());
                }

                if (manager.bachelor02_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive) || manager.bachelor02_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, bachelor02_university = %60s     bachelor02_university_standardized = %20s", i+2, manager.match_id, manager.bachelor02_university.toStdString().c_str(), manager.bachelor02_university_standardized.toStdString().c_str());
                }

                if (manager.other01_university.contains(keyWordOfEliteUni, Qt::CaseInsensitive)    || manager.other01_university_standardized.contains(keyWordOfEliteUni, Qt::CaseInsensitive))
                {
                    manager.isEliteUni = 2;
                    qDebug("i = %3d, match_id = %5d, other01_university    = %60s     other01_university_standardized    = %20s", i+2, manager.match_id, manager.other01_university.toStdString().c_str(), manager.other01_university_standardized.toStdString().c_str());
                }
            }
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
    qDebug("xxxxxxxxx");
    for (int i = 0; i < managerList.size(); ++i)
    {
        qDebug("i = %3d, match_id = %5d, elite = %d", i+2, managerList.at(i).match_id, managerList.at(i).isEliteUni);
//        qDebug("match_id = %5d, phd = %d, mba = %d, jd = %d", managerList.at(i).match_id, managerList.at(i).hasPHD, managerList.at(i).hasMBA, managerList.at(i).hasJD);


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
