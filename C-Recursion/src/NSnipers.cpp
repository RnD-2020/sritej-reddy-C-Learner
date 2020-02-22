/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"

/*
In this code snipper and row terms are of same value at all times.
I just used different terms to get a clarity at some points about code.
*/

void initializeBattlefield(int *battlefield, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(battlefield + (i*n) + j) = -1;
		}
	}
}

void setARow(int row, int snipper,int *battlefield,int n) {
	for (int j = 0; j < n; j++) {
		if (*(battlefield+(n*row)+j) == -1)
			*(battlefield + (n*row) + j) = snipper;
	}
}

void setACol(int col, int snipper, int *battlefield, int n) {
	for (int i = 0; i < n; i++) {
		if (*(battlefield + (i*n) + col) == -1)
			*(battlefield + (i*n) + col) = snipper;
	}
}

void setDownwardsDiagonal(int row, int col, int snipper, int *battlefield, int n) {
	int i, j;
	i = row;
	j = col;
	while (i >= 0 && j >= 0) {
		if (*(battlefield + (i*n) + j) == -1)
			*(battlefield + (i*n) + j) = snipper;
		i--;
		j--;
	}
	i = row + 1;
	j = col + 1;
	while (i <= n - 1 && j <= n - 1) {
		if (*(battlefield + (i*n) + j) == -1)
			*(battlefield + (i*n) + j) = snipper;
		i++;
		j++;
	}
}

void setUpwardsDiagonal(int row, int col, int snipper, int *battlefield, int n) {
	int i, j;
	i = row;
	j = col;
	while (i >= 0 && j <= n - 1) {
		if (*(battlefield + (i*n) + j) == -1)
			*(battlefield + (i*n) + j) = snipper;
		i--;
		j++;
	}
	i = row + 1;
	j = col - 1;
	while (i <= n - 1 && j >= 0) {
		if (*(battlefield + (i*n) + j) == -1)
			*(battlefield + (i*n) + j) = snipper;
		i++;
		j--;
	}
}

void removeARow(int row, int snipper, int *battlefield, int n) {
	for (int j = 0; j < n; j++) {
		if (*(battlefield + (n*row) + j) == snipper)
			*(battlefield + (n*row) + j) = -1;
	}
}

void removeACol(int col, int snipper, int *battlefield, int n) {
	for (int i = 0; i < n; i++) {
		if (*(battlefield + (i*n) + col) == snipper)
			*(battlefield + (i*n) + col) = -1;
	}
}

void removeDownwardsDiagonal(int row, int col, int snipper, int *battlefield, int n) {
	int i, j;
	i = row;
	j = col;
	while (i >= 0 && j >= 0) {
		if (*(battlefield + (i*n) + j) == snipper)
			*(battlefield + (i*n) + j) = -1;
		i--;
		j--;
	}
	i = row + 1;
	j = col + 1;
	while (i <= n - 1 && j <= n - 1) {
		if (*(battlefield + (i*n) + j) == snipper)
			*(battlefield + (i*n) + j) = -1;
		i++;
		j++;
	}
}

void removeUpwardsDiagonal(int row, int col, int snipper, int *battlefield, int n) {
	int i, j;
	i = row;
	j = col;
	while (i >= 0 && j <= n - 1) {
		if (*(battlefield + (i*n) + j) == snipper)
			*(battlefield + (i*n) + j) = -1;
		i--;
		j++;
	}
	i = row + 1;
	j = col - 1;
	while (i <= n - 1 && j >= 0) {
		if (*(battlefield + (i*n) + j) == snipper)
			*(battlefield + (i*n) + j) = -1;
		i++;
		j--;
	}
}

void set(int row, int col, int snipper, int *battlefield, int n) {
	setARow(row, snipper, battlefield, n);
	setACol(col, snipper, battlefield, n);
	setDownwardsDiagonal(row, col, snipper, battlefield, n);
	setUpwardsDiagonal(row, col, snipper, battlefield, n);
}

void remove(int row, int col, int snipper, int *battlefield, int n) {
	removeARow(row, snipper, battlefield, n);
	removeACol(col, snipper, battlefield, n);
	removeDownwardsDiagonal(row, col, snipper, battlefield, n);
	removeUpwardsDiagonal(row, col, snipper, battlefield, n);
}

int ifcanBePlaced(int row,int col, int *battlefield, int n) {
	if (*(battlefield + (row*n) + col) == -1)
		return 1;
	return 0;
}

int placeNthSnipper(int snipper, int *battlefield, int n) {
	printf("%d ", snipper);
	if (snipper == n) //this gets true when last snipper is placed and calls for further recursion only
		return 1;
	for (int j = 0; j < n; j++) {
		if (ifcanBePlaced(snipper, j, battlefield, n)) {
			set(snipper, j, snipper, battlefield, n);
			if (placeNthSnipper(snipper + 1, battlefield, n))
				return 1;
			remove(snipper, j, snipper, battlefield, n);
		}
	}
	return 0;
}

int solve_nsnipers(int *battlefield, int n){
	if (!battlefield)
		return NULL;
	initializeBattlefield(battlefield, n);
	return placeNthSnipper(0, battlefield, n); //0 is the kth snipper. here we consider 0 - (n-1) snippers and we start process
										//using first i.e 0th snipper and all other snippers will be called recursively from that function only
}