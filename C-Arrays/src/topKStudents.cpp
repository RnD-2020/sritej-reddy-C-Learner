/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/

#include <iostream>
#include <malloc.h>
struct student {
	char *name;
	int score;
};


//I am storing ele's into res(result holding array) in decreasing order 
//storing them in descending order because if an ele from students array needs to be inserted into res is smaller than 
//the least value in res then we won't be wasting time in checking every ele in res
//same in the case of ele from students largest of all ele's in res we return 0 (0 is means ele needs to be inserted at first position) 


//this returns the position of where to insert a ele into res
int searchArrayForPositionToInsert(int score, struct student **res, int res_index)
{
	for (int i = 1; i < res_index - 1; i++)
	{
		if (res[i]->score < score)
			return i;
	}
}

//this function rotates right the **res from given position
void rotateRightFromPos(struct student **res, int pos, int res_index)
{
	for (int i = pos; i < res_index; i++)
	{
		res[i + 1] = res[i];
	}
}
//this func returns the correct position of where to insert a ele (and also returns -1 if ele which is to be inserted is smaller than other ele in res
int getCorrectPosition(struct student **res, int res_index, int ele_from_students,int k)
{
	if (res[0]->score <= ele_from_students)
		return 0;
	if (res_index<k && res[res_index - 1]->score > ele_from_students)
		return res_index;
	if (res[res_index - 1]->score > ele_from_students) //this only beacomes true when a ele from students is smaller than all the other ele's in res and res is full(K ele's already present)
		return -1;
	return searchArrayForPositionToInsert(ele_from_students, res, res_index);
}

//this function inserts K ele's into res in decreasing order
void insertKElements(int k, struct student **res, struct student *students)
{
	res[0] = &students[0];
	int res_index = 1, students_index = 1;
	for (res_index; res_index < k; res_index++,students_index++)
	{
		int pos=getCorrectPosition(res, res_index, students[students_index].score,k);
		if (pos != -1)
		{
			rotateRightFromPos(res, pos, res_index);
			res[pos] = &students[students_index];
		}
	}
}

//this func inserts next len-K ele's after inserting K ele's into res by insertKElements()
void checkAndInsertOtherEle(struct student **res, int k, struct student *students, int len)
{
	for (int i = k; i < len; i++)
	{
		int pos = getCorrectPosition(res, k, students[i].score,k);
		if (pos != -1)
		{
			rotateRightFromPos(res, pos, k);
			res[pos] = &students[i];
		}
	}
}

struct student ** topKStudents(struct student *students, int len, int K) {
	if (K < 1)
		return NULL;
	if (K > len)
		K = len;
	struct student **res = (struct student **)malloc(sizeof(struct student)*K);
	
	insertKElements(K, res, students);
	checkAndInsertOtherEle(res, K, students, len);
	
	return res;
}