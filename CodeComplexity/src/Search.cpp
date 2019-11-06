/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search: it iterates from stating till finding the given key

Binary Search : it searches through dividing array size to half in every iteration
but for this we need an sorted array

Conclusion : binary search takes half of time in best case when compared to linear search but in some cases 
linear search takes best time than binary search
*/

int linearSearch(int *arr, int len, int key) {
	for (int i = 0; i < len; i++)
		if (*(arr + i) == key)
			return i;
	/*test case:1 here it takes 4ms beacuse it iterates for 987 times which takes some time
	test case:2 here it takes 3ms beacuse it iterates for 9879 times whick takes more time
	test case:3 here it takes 30ms because it iterates for 98799 times whick takes so much of time*/
	return -1;
}


int recursiveFunction(int *arr,int front ,int end, int key)
{
	int t = (front + end) / 2;
	if (key == *(arr + t))
		return t;
	else if (key < *(arr + t))
		return recursiveFunction(arr, front, t - 1,key);
	else return recursiveFunction(arr, t + 1, end, key);
}
int binarySearch(int *arr, int len, int key) {
	return recursiveFunction(arr,0, len, key);
	/*test case :1 here it takes time as it should divide 1000->500->250->125->67->32 sizes of array 
	test case :2 here it takes time as it should divide 10000->2500->1250->670->320->160 etc sizes fo array
	test case : 3 here it takes somuch of time as it runs for 100000->25000->12500 etc sizes of array*/
	//Use this function as wrapper function,if you are implementing bs recursively.
}