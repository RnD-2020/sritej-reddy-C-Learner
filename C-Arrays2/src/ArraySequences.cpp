/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int inAP(int a,int b,int c) {
	if (b - a == c - b)
		return 1;
	return 0;
}

int inGP(int a, int b, int c) {
	if (a == 0 || b == 0 || c == 0) return 0;
	if ((float)b / a == (float)c / b)
		return 1;
	return 0;
}

int goAhead_AP(int *arr, int len, int start) {
	int difference = arr[start+1] - arr[start];
	int i = start+2; //+2 because we have already checked for 3 numbers in inAp / inGp function.
						//now we need to check next indexes till where the conditon of AP / GP becomes true
	while (i < len) {
		if (arr[i+1] - arr[i] == difference)
			i++;
		else break;
	}
	return i;
}

int goAhead_GP(int *arr, int len, int start) {
	float difference = (float)arr[start + 1] / arr[start];
	int i = start + 2; //+2 because we have already checked for 3 numbers in inAp / inGp function.
					   //now we need to check next indexes till where the conditon of AP / GP becomes true
	while (i < len) {
		if (arr[i] == 0) break;
		if ((float)arr[i +1] / arr[i] == difference)
			i++;
		else break;
	}
	return i;
}

int notPreviousAP(int i, int ap_count, int *arr) {
	if (i == 0 || ap_count == 0) //this is true for first AP sequence
		return 1;
	if (arr[i + 1] - arr[i] == arr[i] - arr[i - 1]) return 0; 
	return 1;
}

int * find_sequences(int *arr, int len){
	if (!arr)
		return NULL;
	int *final_arr = (int *)calloc(6, sizeof(int));
	int ap_count = 0,gp_count=0,k=0; 
	for (int i = 0; i < len; i++) {
		if (gp_count != 1) { //if it is one then it means we have already got gp's start and end index
			if (inGP(arr[i], arr[i + 1], arr[i + 2])) {
				gp_count++;
				final_arr[4] = i;
				final_arr[5]=goAhead_GP(arr, len, i);
			}
		}
		if (ap_count != 2) {
			if (inAP(arr[i], arr[i + 1], arr[i + 2]) && notPreviousAP(i,ap_count,arr)) {
				ap_count++;
				final_arr[k++] = i;
				final_arr[k++] = goAhead_AP(arr, len, i);
			}
		}
		if (ap_count == 2 && gp_count == 1)
			break;
	}
	return final_arr;
}