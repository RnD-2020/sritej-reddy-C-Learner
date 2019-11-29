/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

int getFrontIndex(char *input, int front_index)
{
	if (front_index == -1)
		return ++front_index;
	else
	{
		while (input[front_index] != ' ')
			front_index++;
		return front_index + 1;
	}
}

int getBackIndex(char *input, int front_index, int back_index)
{
	while (input[back_index] != ' ')
	{
		back_index--;
	}
	if (back_index < front_index)
		return -1;
	return back_index + 1;//+1 is because back_index points to a ' ' without +1
}

void leftRotate(char* input, int len, int front_index)
{
	for (int i = front_index; i < len - 1; i++)
	{
		input[i] = input[i + 1];
	}
}

void rightRotate(char *input, int len, int front_index, int back_index)
{
	for (int i = back_index; i > front_index - 1; i--)
	{
		input[i] = input[i - 1];
	}
}

int swap(char * input, int front_index, int back_index,int *bi)
{
	char t;
	while (input[front_index] != ' ' && input[back_index] != ' ' &&input[back_index]!='\0')
	{
		//swap front_index ele and back_index ele
		t = input[front_index];
		input[front_index] = input[back_index];
		input[back_index] = t;
		front_index++;
		back_index++;
	}
	while (input[front_index] != ' ')
	{
		t = input[front_index];
		leftRotate(input, strlen(input),front_index);
		input[back_index-1] = t;
		front_index;
		*bi = *bi - 1;
	}
	while (input[back_index] != ' ' && input[back_index] != '\0')
	{
		t = input[back_index];
		rightRotate(input, strlen(input),front_index,back_index);
		input[front_index] = t;
		back_index++;
		front_index++;
		*bi = *bi + 1;
	}
	return *bi;
}

void str_words_in_rev(char *input, int len)
{
	int back_index=len-1;//back_index for getting work from last
	int front_index=-1;//front_index for pointing from starting
	while (1)
	{
		front_index = getFrontIndex(input, front_index);
		back_index = getBackIndex(input, front_index, back_index);
		if (back_index == -1)
			break;
		back_index=swap(input, front_index, back_index,&back_index); 
		/*afetr this step back_index points to the first letter of the word which was bought to end recently after a swap() call
		now if we do -2 it points to last letter of next word that needs to be sent to begining */
		back_index -= 2;
	}
}
