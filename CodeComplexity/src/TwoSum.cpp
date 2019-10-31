/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 : It is taking around 5 ms

Way 2 : It is taking around 72 ms

Way 3: It is taking around 574 ms

Conclusion : Actually time taken should decrease whereas in my case it is increasing for less complexity codes
*/
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________
*/

void storeResult(int *res, int n1, int n2)
{
	if (n1 > n2)
	{
		res[0] = n2;
		res[1] = n1;
	}
	else {

		res[0] = n1;
		res[1] = n2;
	}
}
int* sumoftwoBF(int *nums, int target, int len){
	if (!nums || len<1)
		return NULL;
	int *res = (int *)malloc(sizeof(int) * 2);
	
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				storeResult(res, nums[i], nums[j]);
				return res;
			}
		}
	}
	/*It iterates through every element of array and checks for the target, It is 
	a very time taking process for large sizes*/
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __________
*/

void searchTwoSum(int *nums, int target, int len, int *res)
{
	for (int i = 0, j = len - 1; i <= j;)
	{
		if (nums[i] + nums[j] == target)
		{
			storeResult(res, nums[i], nums[j]);
			break;
		}
		if (nums[i] + nums[j] < target)
		{
				i++;
			while(nums[i]==nums[i-1])
				i++;
		}
		if (nums[i] + nums[j] > target)
		{
			j--;
			while (nums[j] == nums[j + 1])
				j--;
		}
	}
}
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array
	if (!nums || len<1)
		return NULL;
	sort(nums, nums + len); // I tried for merge and quick sortes but time limit is exceeding
	//Do the task
	int *res = (int *)malloc(sizeof(int) * 2);
	searchTwoSum(nums, target, len, res);
	return res;
	/*In this way, as array is sorted finding for elements that gives sum as target becomes a little easier
	, we will be checking only with one loop
	, if sum by adding two ele is greater than target then we check with before ele of jth position(j is index from end i.e biggest numbers)
	else if sum is less than target than increase ith value */
}


/*

Array contains only		integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
	*/

int* sumoftwoExtraArray(int *nums, int target, int len) {
	//Initialise the array
	int *res=(int *)malloc(sizeof(int)*2);
	sort(nums, nums + len);
	int *temp = (int *)calloc(100,sizeof(int));
	//Do the task
	for (int i = 0; i < len; i++)
	{
		temp[nums[i]] = 1;
		if (temp[target-nums[i]] != 0)
		{
			res[0] = target - nums[i];
			res[1] = nums[i];
			return res;
		}
		while (nums[i] == nums[i + 1])  // This should not be considered for complexity, without this loop also we get result but this loop eliminates checking with repeated numbers
			i++;   //ex: {0,0,0,1,2} first when entering for loop we point at 0th pos and when it hits while loop i is incremented till element 1..
	}
	/* In this we set 1 at position "element" in extra array for ex: suppose ele=2 then we set 1 at array[2] so that we can access at O(1) time
	now when we get remaining value required later, we only check for target-nums[i] position in the array if it is 1 then we return the values
	supppose array[target-nums[i]]==1 then we set res[0]=target-nums[i]; res[1]=nums[i]
	As we decrease number of comparions and keep a track of obtained elements it decreases complexity*/
}