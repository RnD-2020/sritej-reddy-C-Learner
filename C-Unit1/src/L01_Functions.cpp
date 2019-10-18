//
//  L01_Functions.cpp
//  Unit1_lesson1_understanding_functions
//

/*

 Note:
 Function is the basic building block of any programming language.
 
 This idea of giving freedom for the programmer to add more functionality
 to the language is perhaps the greatest idea in high-level languages.
 
 "The basic langauge can be extended at will."
 Watch this video: https://www.youtube.com/watch?v=UhC20aAl8IM&t=1m5s
 till 5min 30sec.

 In this lesson we will understand how things work in the context of function
 - functions without arguments
 - functions with (local) argument variables
 - return keyword in void functions
 - changing the value in the array passed by the caller
 - changing loop index variable inside for loop
 - calling another function inside the function.
 
 You read the code in this file and understand the behaviour.
 And fill the blanks in corresponding file: L01_FunctionsSpec.cpp under spec project.
 
 *****important******
 And DO NOT modify any functions in the lesson files in src project
 except the comments in three_things_i_learnt() function.
*/

int numberOfPeople() {
    return 662;
}

double centimetersPerInch() {
	return 2.4;
}

int tenTimes(int n) {
    return 10*n;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

void tenTimesVector3(int vector[3]) {
    vector[0] = tenTimes         (vector[0]);
    vector[1] = tenTimes  (     vector[1]   );
    vector[2] = tenTimes(vector[2]);
}

int numberOfPrimeFactors(int n) {
    int primeFactors = 0;
    int prime = 2;
    while (n > 1) {
        if (n % prime == 0) {
            primeFactors += 1;
        }
        
        while (n % prime == 0) {
            n = n/prime;
        }
        prime++;
    }
    return primeFactors;
}

void primeFactorsVector(int vector[], int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = numberOfPrimeFactors(vector[i]);
    }
}

void numberToString(int n, char arr[12]) {
    
    if (n == 0) {
        arr[0] = '0';
        arr[1] = '\0';
        return;
    }
    
    int index = 0;
    if (n < 0 ) {
        arr[0] = '-';
        index = 1;
        n = -n;
    }
    
    int reverse = 0;
    for (; n > 0; n = n/10) {
        reverse = reverse*10 + n%10;
    }
    
    for (n = reverse; n > 0; index++) {
        arr[index] = '0' + n%10;
        n = n/10;
    }
    arr[index] = '\0';
}

//
// Mysterious function
// find out these functions behaviour
//
void nTimesMysteryVectorN(int n, int vector[], int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = n * vector[i];
        if (vector[i] == size) {
            return;
        }
    }
}

int sigmaNWithMystery(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        i = i + 3 ;
        sum += i;
    }
    return sum;
}

void tenTimesMysteryVectorN(int vector[], int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = tenTimes(vector[i]);
        i = i + 2;
    }
}

static void three_things_i_learnt() {
    /*
	I have learnt
     1. How to write test cases for each function.
     2. How arrays are compared in test cases with that of answer
     3. Swap() can be compared if address are sent else not. For arrays its different,
	 when we send array name we are actually sending the first address of array.
     */
}
