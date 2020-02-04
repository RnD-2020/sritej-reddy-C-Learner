/*

Use Strings2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Strings-2 Lesson:

->Using malloc to create new strings
->New ways of Handling Strings

Solve CommonRoute , Concat4Strings keeping complexity in Mind , BruteForce solutions take
long time to pass ,and will eventually fail when we run on our side with Timeouts .

Make Sure The Each Individual Test cases for Large inputs dosent take more than
2Seconds. (ie Real20_CommonRoute TestCase in CommonRouteSpec)
*/

#include "FunctionHeadersStrings2.h"
#include<stdio.h>
int main(){


	//Test Consonants_Vowels

	//Test getFrequencyofWord

	//Test getSubstring

	//Test getLastWord

	//Test others
	char sentences[][100] = { "abababa", "he he", "ab cd ab cd", "    ", "1234 aaaaaaa", "asd324", "yzqwer 23425", "a" };
	char words[][100] = { "ab", "he", "ab cd", " ", "aa", "asd324", "x", "a" };
	int counts[100] = { 3, 2, 2, 4, 6, 1, 0 };
	int sc = 7;
	int si = 0;
	for (si = 0; si < sc; si++) {
		int temp_c = count_word_in_str_way_1(sentences[si], words[si]);
		printf("%d ", temp_c);
	}
	return 0;
}