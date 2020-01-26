/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int count = 0;
void colIncrementer(int, int, int**, int*, int, int, int);

void rowDecrementer(int rows, int columns, int **input_array, int *arr, int index, int temp_row, int temp_col) {
	if (temp_row >= 0 + count) {
		arr[index++] = *(*(input_array + temp_row) + temp_col);
		rowDecrementer(rows, columns, input_array, arr, index, temp_row - 1, temp_col);
	}
	else colIncrementer(rows, columns, input_array, arr, index, temp_row+1, temp_col+1);
}

void colDecrementer(int rows, int columns, int **input_array, int *arr, int index, int temp_row, int temp_col) {
	if (temp_col >= 0 + count) {
		arr[index++] = *(*(input_array + temp_row) + temp_col);
		colDecrementer(rows, columns, input_array, arr, index, temp_row, temp_col - 1);
	}
	else {
		count++;
		rowDecrementer(rows, columns, input_array, arr, index, temp_row-1, temp_col+1);
	}
}

void rowIncrementer(int rows, int columns, int **input_array, int *arr, int index, int temp_row, int temp_col) {
	if (temp_row < (rows - count)) {
		arr[index++] = *(*(input_array + temp_row) + temp_col);
		rowIncrementer(rows, columns, input_array, arr, index, temp_row+1, temp_col);
	}
	else colDecrementer(rows, columns, input_array, arr, index, temp_row-1, temp_col-1);
}

void colIncrementer(int rows, int columns, int **input_array, int *arr, int index,int temp_row,int temp_col) {
	if (rows % 2 == 0 && count == rows / 2) return;
	else if (temp_col < (columns - count)) {
		arr[index++] = *(*(input_array + temp_row) + temp_col);
		colIncrementer(rows, columns, input_array, arr, index, temp_row, temp_col+1);
	}
	else if (rows % 2 != 0 && count == rows / 2) return;
	else rowIncrementer(rows, columns, input_array, arr, index, temp_row+1, temp_col-1);
}

int *spiral(int rows, int columns, int **input_array)
{
	if (!input_array || rows < 0 || columns < 0) return NULL;
	int *arr = (int *)calloc(rows*columns, sizeof(int));
	colIncrementer(rows, columns, input_array, arr, 0,0,0); //0 is a index for arr and one more is just used for checking boundry conditions
	return arr;
}