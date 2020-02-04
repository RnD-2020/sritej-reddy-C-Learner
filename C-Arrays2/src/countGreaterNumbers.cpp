/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int length(char *date) {
	int i = 0;
	while (date[i] != '\0')
		i++;
	return i;
}

int	ifok(char ch) {
	if (ch >= '0'&& ch <= '9')
		return 1;
	return 0;
}

int getDate(char *date) {
	if (length(date) != 10) return -1;
	if (!ifok(date[0])) return -1;
	int datee = date[0] - 48;
	datee = datee * 10;
	if (!ifok(date[1])) return -1; 
	datee += date[1] - 48;
	return datee;
}

int getMonth(char *date) {
	if (length(date) != 10) return -1;
	if (!ifok(date[3])) return -1;
	int month = date[3] - 48;
	month = month * 10;
	if (!ifok(date[4])) return -1;
	month += date[4] - 48;
	return month;
}

int getYear(char *date) {
	if (length(date) != 10) return -1;
	if (!ifok(date[6])) return -1;
	int year = date[6] - 48;
	year = year * 10;
	if (!ifok(date[7])) return -1;
	year += date[7] - 48;
	year = year * 10; 
	if (!ifok(date[8])) return -1;
	year += date[8] - 48;
	year = year * 10; 
	if (!ifok(date[9])) return -1;
	year += date[9]- 48;
	return year;
}

int getPos(struct transaction *Arr, int len, int date, int month, int year) {
	int temp_year, temp_month, temp_date;
	for (int i = 0; i < len; i++) {
		temp_year=getYear(Arr[i].date);
		if (temp_year > year) return i;
		if (temp_year == year) {
			temp_month = getMonth(Arr[i].date);
			if (temp_month > month) return i;
			if (temp_month == month) {
				temp_date = getDate(Arr[i].date);
				if (temp_date > date) return i;
			}
		}
	}
	return len;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int datee = getDate(date);
	if (datee == -1) return NULL;
	int month = getMonth(date);
	if (month == -1) return NULL;
	int year = getYear(date);
	if (year == -1) return NULL;
	return len - getPos(Arr, len, datee, month, year);
}