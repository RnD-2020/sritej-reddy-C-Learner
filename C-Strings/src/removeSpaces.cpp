/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<string.h>

char removeSpaces(char *str) {
	if (!str || !strlen(str))
	{
		return '\0';
	}
	int pos = 0,i=0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			str[pos++] = str[i++];
		else i++;
	}
	str[pos] = '\0';
	return '\0';
}