/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>

bool rightElementIsSmaller(int *blocks, int i, int j, int m, int n) {
	if (*(blocks + (i*n) + j + 1) < *(blocks + (i*n) + j))
		return true;
	return false;
}

bool leftElementIsSmaller(int *blocks, int i, int j, int m, int n) {
	if (*(blocks + (i*n) + j - 1) < *(blocks + (i*n) + j))
		return true;
	return false;
}

bool upElementIsSmaller(int *blocks, int i, int j, int m, int n) {
	if (*(blocks + ((i - 1)*n) + j) < *(blocks + (i*n) + j))
		return true;
	return false;
}

bool downElementIsSmaller(int *blocks, int i, int j, int m, int n) {
	if (*(blocks + ((i + 1)*n) + j) < *(blocks + (i*n) + j))
		return true;
	return false;
}

bool checkForDownEle(int *blocks, int i, int j, int m, int n) {
	if (i + 1 < m)
		if (downElementIsSmaller(blocks, i, j, m, n))
			return true;
		else return false;
		return true;
}

bool checkForUpAndDownEle(int *blocks, int i, int j, int m, int n) {
	if (i - 1 > -1) {
		if (upElementIsSmaller(blocks, i, j, m, n)) {
			return checkForDownEle(blocks, i, j, m, n);
		}
		return false;
	}
	return checkForDownEle(blocks, i, j, m, n);
}

bool checkForLeftUpAndDownEle(int *blocks, int i, int j, int m, int n) {
	if (j - 1 > -1) {
		if (leftElementIsSmaller(blocks, i, j, m, n)) {
			if (i - 1 > -1) {
				if (upElementIsSmaller(blocks, i, j, m, n)) {
					return checkForDownEle(blocks, i, j, m, n);
				}
				return false;
			}
			else {
				return checkForDownEle(blocks, i, j, m, n);
			}
		}
		return false;
	}
	return checkForUpAndDownEle(blocks, i, j, m, n);
}

bool isLeaderPillar(int *blocks, int i, int j, int m, int n) {
	if (j + 1 < n) {
		if (rightElementIsSmaller(blocks, i, j, m, n)) {
			if (j - 1 > -1) {
				if (leftElementIsSmaller(blocks, i, j, m, n)) {
					if (i - 1 > -1) {
						if (upElementIsSmaller(blocks, i, j, m, n)) {
							return checkForDownEle(blocks, i, j, m, n);
						}
						return false;
					}
					else {
						return checkForDownEle(blocks, i, j, m, n);
					}
				}
				return false;
			}
			else {
				return checkForUpAndDownEle(blocks, i, j, m, n);
			}
		}
		return false;
	}
	else {
		return checkForLeftUpAndDownEle(blocks, i, j, m, n);
	}
}
bool isLooserPillar(int *blocks, int i,int j,int m,int n) {
	if (*(blocks + (i*n) + j) == 0)
		return false;
	if (j + 1 < m && *(blocks + (i*n) + j + 1) != 0 && *(blocks + (i*n) + j + 1) < *(blocks + (i*n) + j))
		return false;
	if (j - 1 > -1 && *(blocks + (i*n) + j - 1) != 0 && *(blocks + (i*n) + j - 1) < *(blocks + (i*n) + j))
		return false;
	if (i - 1 > -1 && *(blocks + ((i - 1)*n) + j) != 0 && *(blocks + ((i - 1)*n) + j) < *(blocks + (i*n) + j))
		return false;
	if (i + 1 < n && *(blocks + ((i + 1)*n) + j) != 0 && *(blocks + ((i + 1)*n) + j) < *(blocks + (i*n) + j))
		return false;
	return true;
}

bool canBeJumped(int *blocks,int i, int j, int prev_i, int prev_j,int cols) {
	if (prev_j == -1) //-1 if it is first 1st pillar i.e the pillar which is starting one
		return true;
	if (*(blocks + i*cols + j) > *(blocks + prev_i*cols + prev_j))
		return true;
	return false;
}

int findARoute(int *blocks, int i, int j, int m, int n, int *arr, int index,int prev_i,int prev_j) {
	if (i < n && i>-1 && j < m && j>-1 && *(blocks + i*n + j) != 0) {
		if (!canBeJumped(blocks, i, j, prev_i, prev_j, n)) return -1;
		arr[index] = *(blocks + i*n + j);
		if (isLeaderPillar(blocks, i, j, m, n)) return 0;
		int len, temp_len;
		int *temp_arr = (int *)calloc(n*m, sizeof(int));
		len = findARoute(blocks, i, j+1, m, n, arr, index + 1, i, j);
		temp_arr = arr;
		if ((temp_len = findARoute(blocks, i, j-1, m, n, arr, index + 1, i, j)) < len) {
			arr = temp_arr;
		}
		else {
			len = temp_len;
			temp_arr = arr;
		}
		if ((temp_len = findARoute(blocks, i+1, j, m, n, arr, index + 1, i, j)) < len) {
			arr = temp_arr;
		}
		else {
			len = temp_len; 
			temp_arr = arr;
		}
		if ((temp_len = findARoute(blocks, i-1, j, m, n, arr, index + 1, i, j)) < len) {
			arr = temp_arr;
		}
		else {
			len = temp_len; 
			temp_arr = arr;
		}
		return len+1;
	}
	return -1;
}

int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count){
	int *a = (int *)calloc(n*m, sizeof(int));
	int *b = (int *)calloc(n*m, sizeof(int)); 
	*jumps_count = 0;
	int temp_jump_count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isLooserPillar(blocks, i,j,m,n))
			{
				if ((temp_jump_count=findARoute(blocks,i, j, m, n, b, 0,-1,-1)) > *jumps_count) { //0 is sent as array index for b array
					a = b;
					*jumps_count = temp_jump_count;
				}
			}
		}
	}
	return a;
}