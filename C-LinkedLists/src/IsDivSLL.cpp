/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4'

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 .
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};

int getRemainder(int num, int key)
{
	return num%key;
}

/*i am adding current number(c) to rev_num and storing last digit of rev_num in 
temp then getting the remainder of rev_num and straigth_num 
then adding temp+current number(c)+remainder and then getting remainder of it 
it prevents overflow of number*/
int result(char c, int straight_num, int rev_num,int key)
{
	int t = rev_num % 10;
	rev_num /= 10;
	int last_num= c - '0';
	rev_num = rev_num + (1000000000 * c);
	int remainder = getRemainder(straight_num + rev_num, key);
	remainder *= 10;
	remainder += (last_num + t);
	return getRemainder(remainder, key);
}


int getResult(struct charNode* head,int key)
{
	struct charNode *temp = head;
	if (temp->letter == '+' || temp->letter == '-')
		temp = temp->next; //ignore a node if value is + or -
	int straight_num = 0, rev_num = 0;//straight_num stores num in straight way and rev_num from end
	int tenspower = 1, count_of_digits = 0,remainder=0;
	while (temp != NULL)
	{
		count_of_digits++;
		if (count_of_digits == 10)//this goes tru if only no.of digits go more than 9 i.e =10
		{							//as an normal int can store only till 9 digits perfectly (can store 10 digits but but no all ten digit numbers can be stored)
			return result(temp->letter, straight_num, rev_num,key);
		}
		straight_num *= 10;
		straight_num += (temp->letter) - '0';
		rev_num += (((temp->letter) - '0')*tenspower);
		tenspower *= 10;
		temp = temp->next;
	}
	return getRemainder(straight_num + rev_num, key);
}

int isDivisibleSLL(struct charNode * head, int key){
	if (!head || key==0)
		return -1;
	if (getResult(head,key) == 0)
		return 1;
	return 0;
}