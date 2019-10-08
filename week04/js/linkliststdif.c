#include <stdio.h>
#include <stdlib.h>
typedef struct student_information{
	int id;
	char name[30];
	char sex;
	int chinese_grade;
	int math+grade;
	struct student_information *p;
}stdif;
