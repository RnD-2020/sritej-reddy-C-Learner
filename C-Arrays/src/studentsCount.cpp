
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

Problem Code :SC
*/

#include <stdio.h>
 
int leftMostIndex(int *arr, int pos,int len)
{
	int j,count=0;
	for (j=pos-1; j > -1; j--)
	{
		if (arr[pos] != arr[j])
			break;
		else count++;
	}
	return count;
}
int rightMostIndex(int *arr, int pos, int len)
{
	int j, count = 0;
	for (j = pos + 1; j <len; j++)
	{
		if (arr[pos] != arr[j])
			break;
		else count++;
	}
	return count;
}
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return r;
}
void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if(!Arr || len<1)
		return NULL; 
	int pos = binarySearch(Arr, 0, len-1, score);
	if (Arr[pos] == score)
	{
		*lessCount = pos - leftMostIndex(Arr, pos, len);
		*moreCount = len - (pos + 1) - rightMostIndex(Arr, pos, len);
	}
	else 
	{
		*lessCount = pos +1;
		*moreCount = len - (pos + 1);
	}
}