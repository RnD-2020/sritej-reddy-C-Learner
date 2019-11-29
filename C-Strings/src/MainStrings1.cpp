/*

Use MainStrings1 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of Strings-1 Lesson:

->Basics of Strings / Char Arrays .
->Learn about 2D Strings
->Convert Numbers/Floats into Strings
->Manipulating Strings

*/
#include <stdio.h>
#include "FunctionHeadersStrings1.h"

int main(){

	//Test KthIndexFromEnd 

	//TestNumbertoStr

	//removeSpaces

	//StrWordsinRev

	//commonWords

	char *str1 = "the are all is well";
	char *str2 = "is who the";
	char expected[2][31] = { { "the" },{ "is" } };
	char **res = commonWords(str1, str2);
	if (res == NULL)
		printf("yes");
	printf("\n\n%s %s\n\n", res[0], res[1]);
	return 0;
}