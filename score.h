#pragma once
#ifndef __SCORE_H__
#define __SCORE_H__

#include <stdio.h>


typedef struct student
{
	char number[11];
	char name[11];
	float dailyScore;
	float testScore;
	float finalScore;
	float generalScore;
	int rank;

}SS;



SS* readDataFromFile(int *N);

void calcuScore(SS stu[], int N);

void searchGradeInfo(SS stu[], int N);


void sortScore(SS stu[], int N);

void analysisScore(SS stu[], int N);


#endif
