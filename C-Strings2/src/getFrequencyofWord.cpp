/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int checkForWholeWord(char *str, int i, char *word, int j) {
	for (j; word[j] != '\0' && str[i] != '\0'; i++, j++) {
		if (str[i] != word[j])
			return 0;
	}
	if (word[j] != '\0')
		return 0;
	return i;
}

int count_word_in_str_way_1(char *str, char *word){
	int i = 0, count = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] == word[0]) {
			j = checkForWholeWord(str, i, word, 0);
			if (j != 0) {
				count++;
			}
		}
		i++;
	}
	return count;
}

int checkForWholeWordRecursion(char *str, int i, char *word,int j) {
	if (word[j] == '\0')
		return i;
	if (str[i] == word[j])
		return checkForWholeWordRecursion(str, i + 1, word, j + 1);
	return 0;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	int i = 0, count = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] == word[0]) {
			j = checkForWholeWordRecursion(str, i, word, 0);
			if (j != 0) {
				i = j-1;
				count++;
			}
		}
		i++;
	}
	return count;
}