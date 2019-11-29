/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is studentsay of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: studentsay of structures of type student, length of studentsay.

OUTPUT: Sort the studentsay in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SD
*/

#include <stdio.h>
#include<malloc.h>
struct student {
	char name[10];
	int score;
};

void fillMainArrWithSubArr(struct student *arr, struct student *left_arr, int *k,int *i,int size_of_left_arr)
{
	while (*i < size_of_left_arr)
	{
		arr[*k] = left_arr[*i];
		*k = *k + 1;
		*i = *i + 1;
	}
}

void merge(struct student *students, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	struct student *L=(struct student*)malloc(sizeof(struct student)*n1), *R= (struct student*)malloc(sizeof(struct student)*n2);

	for (i = 0; i < n1; i++)
		L[i] = students[l + i];
	for (j = 0; j < n2; j++)
		R[j] = students[m + 1 + j];

	i = 0;
	j = 0;
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i].score >= R[j].score)
		{
			students[k] = L[i];
			i++;
		}
		else
		{
			students[k] = R[j];
			j++;
		}
		k++;
	}
	if (i < n1)
	{
		fillMainArrWithSubArr(students, L, &k, &i, n1);
	}
	if (j < n2)
	{
		fillMainArrWithSubArr(students, R, &k, &j, n2);
	}
}

void mergeSort(struct student *students, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(students, l, m);
		mergeSort(students, m + 1, r);
		merge(students, l, m, r);
	}
}

void * scoresDescendingSort(struct student *students, int len) {
	if (!students)
		return NULL;
	mergeSort(students, 0, len - 1);
}