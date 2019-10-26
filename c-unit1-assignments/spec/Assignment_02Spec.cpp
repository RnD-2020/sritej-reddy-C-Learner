#include "stdafx.h"


#include "./../src/Assignment_02.cpp"
#include "TestHelperMethods.h"
#include <string.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Assignment_02Spec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

        
        //
        // factorial of N
        //
        // Ref: https://www.wolframalpha.com/input/?i=100!
        // 0! - 1
        // 1! - 1
        // 5! - 120
        // 10! - 3628800
        // 20! - 2432902008176640000
        // 30! - 265252859812191058636308480000000
        // 50! - 30414093201713378043612608166064768844377641568960512000000000000
        // 80! - 71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000
        // 100! - 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
        
        // this is specific for factorialOfN test cases
        static void stringFromDigits(int digits[], int n, char str[159]) {
            for (int i = 0; i < n; i++) {
                str[i] = digits[i] + '0';
            }
            str[n] = '\0';
        }
        
        [TestMethod, Timeout(3000)]
        void Test_factorialOfN0() {
            
            int numbers[] = {0, 1, 5, 10};
            int numberOfFactorialDigits[] = {1, 1, 3, 7};
            char *factorials[] = {"1", "1", "120", "3628800"};
            
            int factorialDigits[158];
            char factorialString[159];
            
            int numberOfDigits = factorialOfN(numbers[0], factorialDigits);
            Assert::AreEqual(numberOfFactorialDigits[0], numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[0] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[0], factorialString), L"factorail(" + numbers[0] + ") failed", 1, 2);

            
            numberOfDigits = factorialOfN(numbers[1], factorialDigits);
            Assert::AreEqual(numberOfFactorialDigits[1], numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[1] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[1], factorialString), L"factorail(" + numbers[1] + ") failed", 1, 2);
            
            numberOfDigits = factorialOfN(numbers[2], factorialDigits);
            Assert::AreEqual(numberOfFactorialDigits[2], numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[2] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[2], factorialString), L"factorail(" + numbers[2] + ") failed", 1, 2);
            
            numberOfDigits = factorialOfN(numbers[3], factorialDigits);
            Assert::AreEqual(numberOfFactorialDigits[3], numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[3] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[3], factorialString), L"factorail(" + numbers[3] + ") failed", 1, 2);
            
        }
        
        [TestMethod, Timeout(10000)] // 10 sec
        void Test_factorialOfN1() {
            
            int numbers[] = {20, 30, 50};
            char *factorials[] = {
                "2432902008176640000",
                "265252859812191058636308480000000",
                "30414093201713378043612608166064768844377641568960512000000000000"
            };
            
            int factorialDigits[158];
            char factorialString[159];
            
            int numberOfDigits = factorialOfN(numbers[0], factorialDigits);
            Assert::AreEqual((int)strlen(factorials[0]), numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[0] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[0], factorialString), L"factorail(" + numbers[0] + ") failed", 1, 2);
            
            numberOfDigits = factorialOfN(numbers[1], factorialDigits);
            Assert::AreEqual((int)strlen(factorials[1]), numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[1] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[1], factorialString), L"factorail(" + numbers[1] + ") failed", 1, 2);
            
            numberOfDigits = factorialOfN(numbers[2], factorialDigits);
            Assert::AreEqual((int)strlen(factorials[2]), numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[2] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[2], factorialString), L"factorail(" + numbers[2] + ") failed", 1, 2);
        }
        
        [TestMethod, Timeout(40000)] // 40 sec
        void Test_factorialOfN2() {
            
            int numbers[] = {80, 100};
            char *factorials[] = { "71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000",
            "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000"
            };
            
            int factorialDigits[158];
            char factorialString[159];
            
            int numberOfDigits = factorialOfN(numbers[0], factorialDigits);
            Assert::AreEqual((int)strlen(factorials[0]), numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[0] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[0], factorialString), L"factorail(" + numbers[0] + ") failed", 1, 2);
            
            numberOfDigits = factorialOfN(numbers[1], factorialDigits);
            Assert::AreEqual((int)strlen(factorials[1]), numberOfDigits, L"Wrong number of digits for factorialOf(" + numbers[1] + ")", 1, 2);
            stringFromDigits(factorialDigits, numberOfDigits, factorialString);
            Assert::AreEqual(true, areEqualStrings(factorials[1], factorialString), L"factorail(" + numbers[1] + ") failed", 1, 2);
        }
        
        
        //
        // Tests for recamanSequence function
        //
        [TestMethod, Timeout(6000)] // 6 sec
        void Test_recamanSequence() {
            
			int sequence[] = { 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9, 24, 8, 25, 43,
				62, 42, 63, 41, 18, 42, 17, 43, 16, 44, 15, 45, 14, 46, 79, 113, 78, 114, 77, 39,
				78, 38, 79, 37, 80, 36, 81, 35, 82, 34, 83, 33, 84, 32, 85, 31, 86, 30, 87, 29,
				88, 28, 89, 27, 90, 26, 91, 157, 224, 156, 225, 155 }; // 71 terms
            
            int input[] = {0, 1, 3, 6, 20, 40, 70};
            int output[71];
            bool result;
            
            for (int testCase = 0; testCase < 7; testCase++) {
                recamanSequence(input[testCase], output);
                result = areEqualArrays(sequence, output, input[testCase] + 1);
                Assert::AreEqual(true, result, L"recamanSequence(" + input[testCase] + ") failed", 1, 2);
            }
        }
        
        
	};
}
