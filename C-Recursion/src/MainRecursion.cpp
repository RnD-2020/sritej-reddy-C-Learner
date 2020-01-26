/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>
#include "FunctionHeaders.h"



int main(){

	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code
	const int n = 5, m = 5;
	int blocks[n][m] = {
		{ 1, 2, 0, 1, 0 },
		{ 0, 0, 0, 9, 0 },
		{ 0, 0, 0, 8, 0 },
		{ 0, 1, 4, 6, 5 },
		{ 0, 0, 2, 3, 4 }, };
	/*const int jc_exp = 6;
	int maxpath_exp[jc_exp + 1] = { 2, 3, 4, 5, 6, 8, 9 };
	int nopath = 0;
	*/
	int jc = 0;
	int * arr=pillars_max_jumps(&blocks[0][0], n, m, &jc);
	/*printf("%d ", jc);
	for (int i = 0; i < jc+10; i++)
		printf("%d ", arr[i]);
	*/return 0;
}