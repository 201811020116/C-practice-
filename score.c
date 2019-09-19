#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SCORE.h"


SS* readDataFromFile(int *N, SS *stu)
{
	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("学生数目为:%d\n", count);

	stu = (SS*)malloc(count * sizeof(SS));

	printf("*学号:        姓名         平时成绩         实验成绩        期末成绩    ");

	while ((!feof(fp)))
	{
		fscanf(fp, "%s%s%f%f%f", &stu[index].number, &stu[index].name, &stu[index].dailyScore, &stu[index].testScore, &stu[index].finalScore);

		printf("\n%s    %-5s         %4.2f分         %4.2f分         %4.2f分\n" , stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].testScore, stu[index].finalScore);

		index++;
	}
	printf("\n请按下回车继续\n");
	getchar();

	fclose(fp);

	return stu;
}


void calcuScore(SS stu[], int N)
{
	printf("*学号:        姓名          总成绩 ");
	for (int i = 0; i < N; i++)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + +0.2 * stu[i].testScore + 0.6 *stu[i].finalScore;
		printf("\n%s    %-5s         %4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}
	printf("\n请按下回车继续\n");
	getchar();
}


int cmpBigtoSmall(const void *a, const void *b)
{
	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);

	if ((*aa).generalScore < (*bb).generalScore)
		return 1;

	else if ((*aa).generalScore > (*bb).generalScore)
		return -1;

	else
		return 0;
}


void sortScore(SS stu[], int N)
{
	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);
	printf("*学号:        姓名          总成绩       排名   ");
	for (int i = 0; i < N; i++)
	{
		stu[i].rank = i + 1;
		printf("\n%s    %-5s         %4.2f分       %d \n", stu[i].number, stu[i].name, stu[i].generalScore, stu[i].rank);
	}
	printf("\n请按下回车继续\n");
	getchar();
}


int Student_SearchByIndex(SS stu[], int N, char id[])
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(stu[i].number, id) == 0)
		{
			return i;
		}
	}
	return -1;
}

void searchGradeInfo(SS stu[], int N)
{
	while (1)
	{
		char id[11];
		int index;
		printf("请输入要查询的学生学号:");
		scanf("%s", id);
		index = Student_SearchByIndex(stu, N, id);
		if (index == -1)
		{
			printf("学生不存在!\n\n");
		}
		else
		{
			printf("* 学号：%s 姓名：%-5s 平时成绩：%4.2f分 实验成绩：%4.2f分 期末成绩：%4.2f分 总成绩:%4.2f分 排名:%d\n\n",
				stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].testScore, stu[index].finalScore, stu[index].generalScore, stu[index].rank);
		}
		getchar();
		printf("是否继续?(y/n)");
		if (getchar() == 'n')
		{
			break;
		}

	}
}

void analysisScore(SS stu[], int N)
{
	float mean = 0;
	float variance = 0;
	for (int i = 0; i < N; i++)
	{
		mean += stu[i].generalScore;
	}
	mean = 1.0 * mean / N;
	for (int i = 0; i < N; i++)
	{
		variance += (stu[i].generalScore - mean) * (stu[i].generalScore - mean);
	}
	variance = 1.0 * variance / N;
	printf("\n");
	printf("1.全班同学成绩的均值为:%4.4f\t,方差为:%4.4f\n", mean, variance);
	printf("\n");
	if (mean >= 80)
		printf("2.全班学生成绩的均值%4.4f在[80,100]区间内，说明整体水平优秀.\n", mean);
	else if (mean >= 60)
		printf("2.全班学生成绩的均值%4.4f在[60,80)区间内，说明整体水平良好.\n", mean);
	else
		printf("2.全班学生成绩的均值%4.4f在[0,60)区间内, 说明整体水平较差.\n", mean);
	printf("\n");
	if (variance <= 10)
		printf("3.全班学生的成绩方差为:%4.4f, 说明整体成绩较稳定.\n", variance);
	else if (variance <= 20)
		printf("3.全班学生的成绩方差为:%4.4f, 说明整体成绩略有波动.\n", variance);
	else
		printf("3.全班学生成绩的方差为:%4.4f, 说明整体成绩不太稳定.\n", variance);
	getchar();
}