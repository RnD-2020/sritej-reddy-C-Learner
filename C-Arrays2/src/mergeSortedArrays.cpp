/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

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

int getYearr(char *date) {
	int year = date[6] - 48;
	year = year * 10;
	year += date[7] - 48;
	year = year * 10;
	year += date[8] - 48;
	year = year * 10;
	year += date[9] - 48;
	return year;
}

void copyy(char *res, char *arr) {
	int i = 0;
	while (arr[i] != '\0') {
		res[i] = arr[i];
		i++;
	}
	res[i] = '\0';
}

void copyStructure(struct transaction * res, struct transaction src) {
	res->amount = src.amount;
	copyy(res->date, src.date);
	copyy(res->description, src.description);
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (!A || !B || ALen < 0 || BLen < 0) return NULL;
	struct transaction *res = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int i = 0, j = 0, k = 0;
	while (i < ALen && j < BLen) {
		if (getYearr(A[i].date) > getYearr(B[j].date)) {
			copyStructure(&res[k], B[j]);
			j++;
			k++;
		}
		else if (getYearr(A[i].date) < getYearr(B[j].date)) {
			copyStructure(&res[k], A[i]);
			i++;
			k++;
		}
		else {
			copyStructure(&res[k], B[j]);
			j++;
			k++;
			i++;
		}
	}
	while (i < ALen) {
		copyStructure(&res[k], A[i]);
		k++;
		i++;
	}
	while (j<BLen) {
		copyStructure(&res[k], B[j]);
		k++;
		j++;
	}
	return res;
}