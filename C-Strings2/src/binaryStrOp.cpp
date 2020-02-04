/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>

int length(char *str) {
	int i = 0;
	while (str[i++] != '\0');
	return i-1;
}

void xorOperation(char *str1, char *str2, char *res, int len1, int len2, int res_len) {
	while (len1 >= 0 && len2 >= 0) {
		if (str1[len1--] == str2[len2--])
			res[res_len--] = '0';
		else res[res_len--] = '1';
	}
	while (len1 >= 0) {
		if (str1[len1--] == '1')
			res[res_len--] = '1';
		else res[res_len--] = '0';
	}
	while (len2 >= 0) {
		if (str2[len2--] == '1')
			res[res_len--] = '1';
		else res[res_len--] = '0';
	}
}

void norOperation(char *str1, char *str2, char *res, int len1, int len2, int res_len) {
	while (len1 >= 0 && len2 >= 0) {
		if (str1[len1--] =='0' && str2[len2--]=='0')
			res[res_len--] = '1';
		else res[res_len--] = '0';
	}
	while (len1 >= 0) {
		if (str1[len1--] == '0')
			res[res_len--] = '1';
		else res[res_len--] = '0';
	}
	while (len2 >= 0) {
		if (str2[len2--] == '0')
			res[res_len--] = '1';
		else res[res_len--] = '0';
	}
}

void orOperation(char *str1, char *str2, char *res, int len1, int len2, int res_len) {
	while (len1 >= 0 && len2 >= 0) {
		res[res_len--] = str1[len1--] | str2[len2--];
	}
	while (len1 >= 0) {
		res[res_len--] = str1[len1--] | '0';
	}
	while (len2 >= 0) {
		res[res_len--] = str2[len2--] | '0';
	}
}

void andOperation(char *str1, char *str2,char *res,int len1,int len2,int res_len) {
	while (len1 >= 0 && len2 >= 0) {
		res[res_len--] = str1[len1--] & str2[len2--];
	}
	while (len1 >= 0) {
		res[res_len--] = str1[len1--] & '0';
	}
	while (len2 >= 0) {
		res[res_len--] = str2[len2--] & '0';
	}
}

char *performOperation(char *str1, char *str2, char *operation){
	if (!str1 || !str2) return NULL;
	int len1 = length(str1);
	int len2 = length(str2);
	int res_len = len1 > len2 ? len1 : len2;
	char *res = (char*)malloc(sizeof(char)*(res_len));
	res[res_len] = '\0';
	
	switch (*operation) {
	case 'A':andOperation(str1, str2, res, len1 - 1, len2 - 1, res_len - 1);
		break;
	case 'O':orOperation(str1, str2, res, len1 - 1, len2 - 1, res_len - 1);
		break;
	case 'X':xorOperation(str1, str2, res, len1 - 1, len2 - 1, res_len - 1);
		break;
	case 'N':norOperation(str1, str2, res, len1 - 1, len2 - 1, res_len - 1);
		break;
	}
	return res;
}








