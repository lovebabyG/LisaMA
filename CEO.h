#ifndef CEO_H
#define CEO_H

#include <QString>
#include "globaldefine.h"

class CEO
{
public:
    CEO();

    static const int match_id_index = 0;

    static const int bachelor01_university_index = 1;
    static const int bachelor01_university_standardiz_index = 2;
    static const int bachelor01_degree_index = 3;
    static const int bachelor01_degree_standardized_index = 4;
    static const int bachelor01_major_index = 5;
    static const int bachelor01_major_standardized_index = 6;

    static const int bachelor02_university_index = 7;
    static const int bachelor02_university_standardiz_index = 8;
    static const int bachelor02_degree_index = 9;
    static const int bachelor02_degree_standardized_index = 10;
    static const int bachelor02_major_index = 11;
    static const int bachelor02_major_standardized_index = 12;

    static const int master01_university_index = 13;
    static const int master01_university_standardized_index = 14;
    static const int master01_degree_index = 15;
    static const int master01_degree_standardized_index = 16;
    static const int master01_major_index = 17;
    static const int master01_major_standardized_index = 18;

    static const int master02_university_index = 19;
    static const int master02_university_standardized_index = 20;
    static const int master02_degree_index = 21;
    static const int master02_degree_standardized_index = 22;
    static const int master02_major_index = 23;
    static const int master02_major_standardized_index = 24;

    static const int mba01_university_index = 25;
    static const int mba01_university_standardized_index = 26;
    static const int mba01_degree_index = 27;
    static const int mba01_degree_standardized_index = 28;

    static const int mba02_university_index = 29;
    static const int mba02_university_standardized_index = 30;
    static const int mba02_degree_index = 31;
    static const int mba02_degree_standardized_index = 32;

    static const int phd01_university_index = 33;
    static const int phd01_university_standardized_index = 34;
    static const int phd01_degree_index = 35;
    static const int phd01_degree_standardized_index = 36;
    static const int phd01_major_index = 37;
    static const int phd01_major_standardized_index = 38;

    static const int phd02_university_index = 39;
    static const int phd02_university_standardized_index = 40;
    static const int phd02_degree_index = 41;
    static const int phd02_degree_standardized_index = 42;
    static const int phd02_major_index = 43;
    static const int phd02_major_standardized_index = 44;

    static const int jd01_university_index = 45;
    static const int jd01_university_standardized_index = 46;
    static const int jd01_degree_index = 47;
    static const int jd01_degree_standardized_index = 48;

//    static const int other01_university_index = 37;
//    static const int other01_university_standardized_index = 38;
//    static const int other01_degree_index = 39;
//    static const int other01_degree_standardized_index = 40;

    static const int last_end_CEO_index = 49;

    int match_id;
    QString bachelor01_university;
    QString bachelor01_university_standardized;
    QString bachelor01_degree;
    QString bachelor01_degree_standardized;
    QString bachelor01_major;
    QString bachelor01_major_standardized;

    QString bachelor02_university;
    QString bachelor02_university_standardized;
    QString bachelor02_degree;
    QString bachelor02_degree_standardized;
    QString bachelor02_major;
    QString bachelor02_major_standardized;

    QString master01_university;
    QString master01_university_standardized;
    QString master01_degree;
    QString master01_degree_standardized;
    QString master01_major;
    QString master01_major_standardized;

    QString master02_university;
    QString master02_university_standardized;
    QString master02_degree;
    QString master02_degree_standardized;
    QString master02_major;
    QString master02_major_standardized;

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
    QString phd01_major;
    QString phd01_major_standardized;

    QString phd02_university;
    QString phd02_university_standardized;
    QString phd02_degree;
    QString phd02_degree_standardized;
    QString phd02_major;
    QString phd02_major_standardized;

    QString jd01_university;
    QString jd01_university_standardized;
    QString jd01_degree;
    QString jd01_degree_standardized;

//    QString other01_university;
//    QString other01_university_standardized;
//    QString other01_degree;
//    QString other01_degree_standardized;

    CEOLevelEdu ceoLevelEdu;
    bool hasMBA;
    bool hasPHD;
    bool hasJD;
    int isEliteUni = 0;
};

#endif // CEO_H
