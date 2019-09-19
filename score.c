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

	printf("ѧ����ĿΪ:%d\n", count);

	stu = (SS*)malloc(count * sizeof(SS));

	printf("*ѧ��:        ����         ƽʱ�ɼ�         ʵ��ɼ�        ��ĩ�ɼ�    ");

	while ((!feof(fp)))
	{
		fscanf(fp, "%s%s%f%f%f", &stu[index].number, &stu[index].name, &stu[index].dailyScore, &stu[index].testScore, &stu[index].finalScore);

		printf("\n%s    %-5s         %4.2f��         %4.2f��         %4.2f��\n" , stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].testScore, stu[index].finalScore);

		index++;
	}
	printf("\n�밴�»س�����\n");
	getchar();

	fclose(fp);

	return stu;
}


void calcuScore(SS stu[], int N)
{
	printf("*ѧ��:        ����          �ܳɼ� ");
	for (int i = 0; i < N; i++)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + +0.2 * stu[i].testScore + 0.6 *stu[i].finalScore;
		printf("\n%s    %-5s         %4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}
	printf("\n�밴�»س�����\n");
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
	printf("*ѧ��:        ����          �ܳɼ�       ����   ");
	for (int i = 0; i < N; i++)
	{
		stu[i].rank = i + 1;
		printf("\n%s    %-5s         %4.2f��       %d \n", stu[i].number, stu[i].name, stu[i].generalScore, stu[i].rank);
	}
	printf("\n�밴�»س�����\n");
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
		printf("������Ҫ��ѯ��ѧ��ѧ��:");
		scanf("%s", id);
		index = Student_SearchByIndex(stu, N, id);
		if (index == -1)
		{
			printf("ѧ��������!\n\n");
		}
		else
		{
			printf("* ѧ�ţ�%s ������%-5s ƽʱ�ɼ���%4.2f�� ʵ��ɼ���%4.2f�� ��ĩ�ɼ���%4.2f�� �ܳɼ�:%4.2f�� ����:%d\n\n",
				stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].testScore, stu[index].finalScore, stu[index].generalScore, stu[index].rank);
		}
		getchar();
		printf("�Ƿ����?(y/n)");
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
	printf("1.ȫ��ͬѧ�ɼ��ľ�ֵΪ:%4.4f\t,����Ϊ:%4.4f\n", mean, variance);
	printf("\n");
	if (mean >= 80)
		printf("2.ȫ��ѧ���ɼ��ľ�ֵ%4.4f��[80,100]�����ڣ�˵������ˮƽ����.\n", mean);
	else if (mean >= 60)
		printf("2.ȫ��ѧ���ɼ��ľ�ֵ%4.4f��[60,80)�����ڣ�˵������ˮƽ����.\n", mean);
	else
		printf("2.ȫ��ѧ���ɼ��ľ�ֵ%4.4f��[0,60)������, ˵������ˮƽ�ϲ�.\n", mean);
	printf("\n");
	if (variance <= 10)
		printf("3.ȫ��ѧ���ĳɼ�����Ϊ:%4.4f, ˵������ɼ����ȶ�.\n", variance);
	else if (variance <= 20)
		printf("3.ȫ��ѧ���ĳɼ�����Ϊ:%4.4f, ˵������ɼ����в���.\n", variance);
	else
		printf("3.ȫ��ѧ���ɼ��ķ���Ϊ:%4.4f, ˵������ɼ���̫�ȶ�.\n", variance);
	getchar();
}