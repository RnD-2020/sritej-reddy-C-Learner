/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int areEqual(char date1[], char date2[]) {
	for (int i = 0; i < 10; i++) {
		if (date1[i] != date2[i])
			return 0;
	}
	return 1;
}

void copy(char *res, char *arr) {
	int i = 0;
	while(arr[i]!='\0'){
		res[i] = arr[i];
		i++;
	}
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (!A || !B || ALen < 0 || BLen < 0) return NULL;
	struct transaction *res = (struct transaction *)malloc(sizeof(struct transaction)*ALen);
	int k = 0;
	for (int i = 0; i < ALen; i++) {
		for (int j = 0; j < BLen; j++) {
			if (areEqual(A[i].date, B[j].date)) {
				res[k].amount = A[i].amount;
				copy(res[k].date, A[i].date);
				copy(res[k].description, A[i].description);
				k++;
			}
		}
	}
	if (k == 0) return NULL;
	return res;
}
