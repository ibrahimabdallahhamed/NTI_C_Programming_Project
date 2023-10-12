#ifndef SCHOOLMANAGEMENT_H
#define SCHOOLMANAGEMENT_H
#include "STDTYPES.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct birth
{
    u32 year;
    u32 month;
    u32 day;
}Birth ;

typedef struct data
{
    s8 StudentName[30];
    s8 StudentAddress[30];
    u32 StudentID;
    f32 StudentScore;
    u64 StudentPhone;
    Birth StudentBirth;

} Data_T;


typedef struct Student_T
{
    Data_T Data;
    struct Student_T *Link;

} Student_T;

void MAIN_MENU(void);
void NEW_STUDENT(Student_T **list);
void DELETE_STUDENT(Student_T **list);
void STUDENT_LIST(Student_T **list);
void STUDENT_EDIT(Student_T **list);
void RANK_STUDENT(Student_T **list);
void STUDENT_SCORE(Student_T **list);

#endif