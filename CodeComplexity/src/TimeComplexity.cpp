/**
Here you will be given 14 functions for which you have to return Big-Oh time complexity as a string.
You only need to fill return values for functions whose name starts with "function", it might use some helper functions.
You need to calculate the complexity of those helper functions too and return overall bigoh complexity from
wrapper function.

For example for function0. You need to return "O(n)";

If exacty time complexity is 6(n*n) . You just need to return n*n.
Rules for returning Strings :
'O' should be capital.
You can't write nlogn, write O(n*logn).
Use ^ character only if the power is not a constant. 
n^2 is to be written as n*n.
n^n can be written as it is.

For functions taking arrays as input ,consider n as size of array.

Try to solve the tasks without looking at answers, even if testcases fail.This makes sure you are learning really.
*/

#include<stdio.h>
#include<math.h>

char* function0(int n) {
	//Sample Not tested
	int i, j;
	for (i = 0; i < n; i++) {

	}
	/*O(n) because statements inside loop run for n times*/
	return "O(n)";
}

char* function1(int n) {
	int i, j;
	for (i = 0, j = n; i < j; i *= 2, j /= 2);
	/*O(logn base 2) because i is zero always ways (if i gets incremented then also same complexity ) and j is getting decremented by half every time
	and runs for logj times only(until j hits 0) */
	return "O(logn)";
}

char* function2(int n) {
	int i;
	for (i = 0; i<n; i++) {
		//some code
	}
	for (i = 0; i<6 * n; ++i) {
		//some other code
	}
	/*first loop runs for n times and second for 6*n times so total is n+(6*n) we take O(n)*/
	return "O(n)";
}

char* function3(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j += i) {
			//some code
		}
	}
	/*for each i in first loop the second loop runs for n/i times( n + n/2 + n/3 +..n/n) so total is n*logn */
	return "O(n*logn)";
}

//Consider n as number of digits in "number" 
int digit_count(int number) {
	int count = 0;
	while (number != 0) {
		number /= 10;
		count++;
	}
	return count;
}

char* function4(int number) {
	digit_count(number);
	/*runs for number of digits in number times so O(n)*/
	return "O(n)";
}

void swap(int *n1, int *n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void randomSort(int *arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

char* function5(int *arr, int size) {
	randomSort(arr, size);
	/*runs for n(n+1)/2 times */
	return "O(n*n)";
}

int factorial(int n) {
	int i, result = 1;
	for (i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

char* function6(int n) {
	factorial(n);
	/*because it loop in function runs for n-2 and it is O(n)*/
	return "O(n)";
}

//Consider n as number of digits in number
int reverse(int number) {
	int reversed_num = 0, remainder;
	while (number != 0) {
		remainder = number % 10;
		reversed_num = reversed_num * 10 + remainder;
		number /= 10;
	}
	return reversed_num;
}

char* function7(int number) {
	reverse(number);
	/*same as digit_count() function loop runs for number of digits in number times*/
	return "O(n)";
}

char* function8(int n) {
	int i, j;
	int k = 0;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j *= 2) {
			for (k = 2; k < 1000; k++){

			}
		}
	}
	/*first loop runs for n times and second for logn third for constant time(1000 times)*/
	return "O(n*logn)";
}

char* function9(int n) {
	int i, j;
	for (i = n; i >= 1; i /= 2){
		for (j = 1; j<n*n; j++){
			//some code
		}
	}
	/*first loop runs for logn times and second for n*n times*/
	return "O(n*n*logn)";
}

int power(int base, int exp) {
	int i, result = 1;
	for (i = 1; i <= exp; i++) {
		result *= base;
	}
	return result;
}

char* function10(int n) {
	int i, j;
	for (i = 1; i <= n; i += 2) {
		for (j = 1; j <= power(n, i); j += 2) {
			//some O(1) tasks
		}
	}
	/*first loop runs for n/2 times 
	second for 10^i times so n^n */
	return "O(n^n)";
}

void remove_dup(int *arr, int size){
	int i, j, k, *ptr = NULL;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size;) {
			if (arr[j] == arr[i]) {
				for (k = j; k < size; k++) {
					arr[k] = arr[k + 1];
				}
				size--;
			}
			else
				j++;
		}
	}
}

char* function11(int *array, int size) {
	remove_dup(array, size);
	/* first loop runs for n times and second for n times ..and also third loop inside a condition also runs for n times
	worst case is O(n*n*n). I think answer is O(n*n*n) but is it O(n*n)?
	best and average case can be n*n */
	return "O(n*n)";
}

int find_min_sum(int *array, int size) {
	int i, j, min_sum = 0, sum;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			sum = array[i] + array[j];
			if (abs(min_sum) > abs(sum)) {
				min_sum = sum;
			}
		}
	}
	return min_sum;
}

char* function12(int *array, int size) {
	find_min_sum(array, size);
	/*two loops are running and second runs for n(n+1)/2 times*/
	return "O(n*n)";
}

//calculates standard deviation
float calculate_sd(float *array, int size) {
	float sum = 0.0, mean, sd = 0.0;
	int i;
	for (i = 0; i<size; ++i) {
		sum += array[i];
	}
	mean = sum / size;
	for (i = 0; i<size; ++i)
		sd += power(array[i] - mean, 2);
	return sqrt(sd / 10);
}

char* function13(float* array, int size) {
	calculate_sd(array, size);
	/*two loops are running separately each for n times */
	return "O(n)";
}

int negative_sum(int *array, int size) {
	int i, sum = 0;
	for (i = 0; i<size; i++) {
		if (array[i] < 0)
			sum += array[i];
	}
	return sum;
}

char* function14(int *array, int size) {
	negative_sum(array, size);
	/*loop runs for n times */
	return "O(n)";
}