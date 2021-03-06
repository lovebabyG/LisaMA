#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include "globaldefine.h"

class Manager
{
public:
    Manager();

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
    int isEliteUni = 0;
};

#endif // MANAGER_H
