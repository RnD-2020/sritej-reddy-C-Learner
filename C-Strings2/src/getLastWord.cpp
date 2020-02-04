/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

int lengthh(char *str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int traverseTillLastOfLastWord(char *str,int len) {
	len--;
	while (str[len] != ' ' && len>=0)
		len--;
	return len;
}

void traverseTillStartingOfLastWord(char *str,int len,int *word_len,int *starting_point_of_word) {
	int i = traverseTillLastOfLastWord(str, len);
	int t = i;
	while (str[i] != ' ' && i >= 0) {
		i--;
	}
	*starting_point_of_word = i + 1;
	*word_len = t - i;
}

void storeInWord(char *word, int word_len, char *str, int str_len) {
	str_len--;
	word_len--;
	while (str[str_len] != ' ' && str[str_len] != '\0') {
		word[word_len--] = str[str_len--];
	}
}

char * get_last_word(char * str){
	if (!str) return NULL;
	int len=lengthh(str);

	return NULL;
}
