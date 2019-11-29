/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>
#include<string.h>

#define SIZE 31

void copyIntoS(char *s,char *str, int start,int end) //copies a word from start to end position from str to s
{
	memcpy(s, str + start, end);
	s[end] = '\0';
}

void getWord(char *s,char* str, int* i) //gets positions of start and end
{
	int end = 0, start = *i;
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		end++;
		*i=*i+1;
	}
	copyIntoS(s,str ,start,end);
}

char ** commonWords(char *str1, char *str2) {
	if (!str1 || !str2)
		return NULL;
	int i = 0, j = 0, no_of_common =0;
	char **res=NULL;
	char *s1 = (char*)malloc(sizeof(char) * 31);
	char *s2 = (char*)malloc(sizeof(char) * 31);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i<len1; i++)
	{
		getWord(s1, str1, &i);
		for (int j = 0; j<len2; j++)
		{
			getWord(s2,str2, &j);
			if (!strcmp(s1, s2))
			{
				no_of_common++;
				res = (char **)realloc(res, no_of_common*sizeof(char*));
				res[no_of_common-1] = s1;
			}
		}
	}
	
	if (no_of_common!=0)
		return res;
	return NULL;
}