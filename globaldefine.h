#ifndef GLOBALDEFINE_H
#define GLOBALDEFINE_H

#include <QStringList>

enum CEOLevelEdu
{
    no = 0,
    bachelor = 1,
    master = 2,
    mba = 3,
    phd = 4,
    not_available = 5
};

static QStringList ExatNameListOfEliteUni = {
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


static QStringList keyWordListOfEliteUni = {
                                     "Oxford", // University of Oxford
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


#endif // GLOBALDEFINE_H
