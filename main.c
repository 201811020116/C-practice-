#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include "SCORE.h"

#define  _CRT_SECURE_NO_WARNINGS


int main()
{
	printf("******************************\n");
	printf("       学生成绩管理分析系统        \n");
	printf("         Xialian  Li           \n");
	printf("******************************\n\n");

	int N = 0;
	SS *stu = NULL;

	stu = readDataFromFile(&N);

	calcuScore(stu, N);

	sortScore(stu, N);

	searchGradeInfo(stu, N);

	analysisScore(stu, N);


	free(stu);

	system("pause");
	return 0;
}