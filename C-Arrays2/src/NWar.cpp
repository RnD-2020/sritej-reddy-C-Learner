/*
Problem Code :NWAR

There is a war going among numbers ,on who should be considered as a Leader and finally they have reached a conclusion .
For those numbers when breaked into digits and Individual squares are added ,and if the sum is not 1 ,the process is repeated for the sum and so on.
When doing this if any any time ,Sum reaches 1 , that number can be called as Leader Number , other wise not .

Ex: 1000 => (1^2 + 0^2 + 0^2 + 0^2) ==> 1 .1000 is a leader number
Ex: 44 => (16+16) => 32 => (9+4) ==> 13 => (1+9) ==> 10 ==> (1+0) ==> 1. 44 is a leader number .
Ex: 67 => (36+49) ==> 85 => By Doing Dividing and Squaring and Summing we get this series
89 => 145 => 42 => 20 => 4 => 16 => 37 => 58 => 89 , As 89 is already generated No matter how many times we do this process We can never reach 1 .So its not a leader Element .

Given an Array of Numbers ,You need to return the array of Leader Elements .You should also copy the Number of Leader Elements Found in *leadersArraLen variable .
Order should be maintained in the Result Array .

Ex Input : [

Constraints :
0<= A[i]< 1000000
0<len<10000

Note : Returns Array Length will not be greater than 10001 . And If the leader number occured 2 or more times in the original array include those many times in answer
Note : Return NULL for Invalid Inputs
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int leader(int num) {
	int sum = 0;
	if (num / 10 == 0) {
		if (num == 1) return 1;
		return 0;
	}
	while (num) {
		sum += ((num % 10) * (num % 10));
		num /= 10;
	}
	return leader(sum);
}

int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen){
	if (!arr || len<0) return NULL;
	int *leaderArray = (int *)malloc(len * sizeof(int));
	int k = 0;
	for (int i = 0; i < len; i++) {
		if (leader(arr[i])) {
			leaderArray[k++] = arr[i];
		}
	}
	*leadersArrayLen = k;
	return leaderArray;
}
