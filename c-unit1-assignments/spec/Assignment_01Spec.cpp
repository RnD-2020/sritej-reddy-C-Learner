#include "stdafx.h"


#include "./../src/Assignment_01.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Assignment_01Spec
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
        // Tests for butterflyNumber function
        //
        
        [TestMethod, Timeout(3000)]
        void Test_butterflyNumber0() {
            
            int numbers[] = {123, 59, 202, 980214};
            char *butterflys[] = {"123321", "5995", "202202", "980214412089"};
            char butterfly[23];
            
            butterflyNumber(numbers[0], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[0], butterfly), L"butterfly of " + numbers[0] + L" failed", 1, 2);
            
            butterflyNumber(numbers[1], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[1], butterfly), L"butterfly of " + numbers[1] + L" failed", 1, 2);
            
            butterflyNumber(numbers[2], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[2], butterfly), L"butterfly of " + numbers[2] + L" failed", 1, 2);
            
            butterflyNumber(numbers[3], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[3], butterfly), L"butterfly of " + numbers[3] + L" failed", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void Test_butterflyNumber1() {
            
            int numbers[] = {20, -2, 0, -9090};
            char *butterflys[] = {"2002", "-22-", "00", "-90900909-"};
            char butterfly[23];
            
            butterflyNumber(numbers[0], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[0], butterfly), L"butterfly of " + numbers[0] + L" failed", 1, 2);
            
            butterflyNumber(numbers[1], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[1], butterfly), L"butterfly of " + numbers[1] + L" failed", 1, 2);
            
            butterflyNumber(numbers[2], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[2], butterfly), L"butterfly of " + numbers[2] + L" failed", 1, 2);
            
            butterflyNumber(numbers[3], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[3], butterfly), L"butterfly of " + numbers[3] + L" failed", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void Test_butterflyNumber2() {
            
            int numbers[] = {2147483647, -2147483600, 2147483600};
            char *butterflys[] = {"21474836477463847412", "-21474836000063847412-", "21474836000063847412"};
            char butterfly[23];
            
            butterflyNumber(numbers[0], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[0], butterfly), L"butterfly of " + numbers[0] + L" failed", 1, 2);
            
            butterflyNumber(numbers[1], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[1], butterfly), L"butterfly of " + numbers[1] + L" failed", 1, 2);
            
            butterflyNumber(numbers[2], butterfly);
            Assert::AreEqual(true, areEqualStrings(butterflys[2], butterfly), L"butterfly of " + numbers[2] + L" failed", 1, 2);
            
        }
        
        
        /*
         2 => 19, { 1, 3, 5, 7, 9, 15, 17, 21, 27, 31, 33, 45, 51, 63, 65, 73, 85, 93, 99}
         7 => 20, { 1, 2, 3, 4, 5, 6, 8, 16, 24, 32, 40, 48, 50, 57, 64, 71, 78, 85, 92, 100}
         10 => 18, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99}
         13 => 19, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 28, 42, 56, 70, 84, 98}
         32 => 34, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 66, 99}
         256 => 100, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
         */
        
        //
        // Tests for palindromeNumbers function
        //
        [TestMethod, Timeout(40000)]  // 40 sec
        void Test_palindromeNumbers() {
            
            int bases[6] = {2, 7, 10, 13, 32, 256};
            int numberOfPalindromes[6] = {19, 20, 18, 19, 34, 100};
            int expected[][100] = {
                { 1, 3, 5, 7, 9, 15, 17, 21, 27, 31, 33, 45, 51, 63, 65, 73, 85, 93, 99},
                { 1, 2, 3, 4, 5, 6, 8, 16, 24, 32, 40, 48, 50, 57, 64, 71, 78, 85, 92, 100},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 28, 42, 56, 70, 84, 98},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 66, 99},
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
            };
            int output[100];
            int count;
            bool result;
            
            count = palindromeNumbers(bases[0], output);
            Assert::AreEqual(numberOfPalindromes[0], count, L"Number of palindromes wrong for base:" + bases[0] + ".", 1, 2);
            result = areEqualArrays(expected[0], output, count);
            Assert::AreEqual(true, result, L"palindromeNumbers(" + bases[0] + ") failed", 1, 2);
            
            count = palindromeNumbers(bases[1], output);
            Assert::AreEqual(numberOfPalindromes[1], count, L"Number of palindromes wrong for base:" + bases[1] + ".", 1, 2);
            result = areEqualArrays(expected[1], output, count);
            Assert::AreEqual(true, result, L"palindromeNumbers(" + bases[1] + ") failed", 1, 2);
            
            count = palindromeNumbers(bases[2], output);
            Assert::AreEqual(numberOfPalindromes[2], count, L"Number of palindromes wrong for base:" + bases[2] + ".", 1, 2);
            result = areEqualArrays(expected[2], output, count);
            Assert::AreEqual(true, result, L"palindromeNumbers(" + bases[2] + ") failed", 1, 2);
            
            count = palindromeNumbers(bases[3], output);
            Assert::AreEqual(numberOfPalindromes[3], count, L"Number of palindromes wrong for base:" + bases[3] + ".", 1, 2);
            result = areEqualArrays(expected[3], output, count);
            Assert::AreEqual(true, result, L"palindromeNumbers(" + bases[3] + ") failed", 1, 2);
            
            count = palindromeNumbers(bases[4], output);
            Assert::AreEqual(numberOfPalindromes[4], count, L"Number of palindromes wrong for base:" + bases[4] + ".", 1, 2);
            result = areEqualArrays(expected[4], output, count);
            Assert::AreEqual(true, result, L"palindromeNumbers(" + bases[4] + ") failed", 1, 2);
            
            count = palindromeNumbers(bases[5], output);
            Assert::AreEqual(numberOfPalindromes[5], count, L"Number of palindromes wrong for base:" + bases[5] + ".", 1, 2);
            result = areEqualArrays(expected[5], output, count);
            Assert::AreEqual(true, result, L"palindromeNumbers(" + bases[5] + ") failed", 1, 2);
        }
        
        
        //
        // Tests for closest5EvenNumbers function
        //
        [TestMethod, Timeout(3000)]
        void Test_closest5EvenNumbers() {
            // 14  => { 8, 10, 12, 16, 18}; // 8 and 20 are at equal distance from 14, we pick 8.
            // 25  => { 20, 22, 24, 26, 28}; // 20 and 30 are at equal distance from 25, we pick 20.
            //
            int ns[6] = {14, 25, 1, 4, 7, 6};
            int evens[5];
            int expectedEvens[][5] = {
                { 8, 10, 12, 16, 18},
                { 20, 22, 24, 26, 28},
                { 2, 4, 6, 8, 10},
                { 2, 6, 8, 10, 12},
                { 2, 4, 6, 8, 10},
                { 2, 4, 8, 10, 12}
            };
            
            bool result;
            for (int testCase = 0; testCase < 6; testCase++) {
                closest5EvenNumbers(ns[testCase], evens);
                result = areEqualArrays(expectedEvens[testCase], evens, 5);
                Assert::AreEqual(true, result, L"closest5EvenNumbers(" + ns[testCase] + ") failed", 1, 2);
            }
        }
        
        //
        // Tests for closest5PalindromeNumbers function
        //
        [TestMethod, Timeout(3000)]
        void Test_closest5PalindromeNumbers0() {
 
            int base[] = {10, 10};
            int seeds[] = {6, 16};
            int palindromes[5];
            int expectedPalindromes[][5] = {
                { 3, 4, 5, 7, 8}, // n = 6, base-10
                { 7, 8, 9, 11, 22} // 16, base-10
            };
            
            closest5PalindromeNumbers(seeds[0], base[0], palindromes);
            bool result = areEqualArrays(expectedPalindromes[0], palindromes, 5);
            Assert::AreEqual(true, result, L"closest5PalindromeNumbers(" + seeds[0] + ", " + base[0] + ") failed", 1, 2);

            closest5PalindromeNumbers(seeds[1], base[1], palindromes);
            result = areEqualArrays(expectedPalindromes[1], palindromes, 5);
            Assert::AreEqual(true, result, L"closest5PalindromeNumbers(" + seeds[1] + ", " + base[1] + ") failed", 1, 2);
            
        }
        
        [TestMethod, Timeout(40000)] // 40 sec
        void Test_closest5PalindromeNumbers1() {
            
            int base[] = {16, 10, 16, 256, 14, 25};
            int seeds[] = {16, 1000, 1000, 1000, 1000, 1000};
            int palindromes[5];
            int expectedPalindromes[][5] = {
                { 0xc, 0xd, 0xe, 0xf, 0x11}, // 16, base-16
                { 969, 979, 989, 999, 1001}, // 1000, base-10
                { 0x3c3, 0x3d3, 0x3e3, 0x3f3, 0x404}, // 1000(0x3e8), base-16
                { 0x202, 0x303, 0x404, 0x505, 0x606}, // 1000(0x3e8), base-256
                { 970, 985, 999, 1013, 1027}, // 1000, base-14
                { 951, 976, 1001, 1026, 1051} // 1000, base-25
            };
            
            bool result;
            for (int testCase = 0; testCase < 6; testCase++) {
                closest5PalindromeNumbers(seeds[testCase], base[testCase], palindromes);
                result = areEqualArrays(expectedPalindromes[testCase], palindromes, 5);
                Assert::AreEqual(true, result, L"closest5PalindromeNumbers(" + seeds[testCase] + ", " + base[testCase] + ") failed", 1, 2);
            }
        }
        
        [TestMethod, Timeout(40000)] // 40 sec
        void Test_closest5PalindromeNumbers2() {
            
            int base[] = {16, 10, 2, 3, 4};
            int seed = 3;
            int palindromes[5];
            int expectedPalindromes[][5] = {
                { 1, 2, 4, 5, 6}, // 3, base-16
                { 1, 2, 4, 5, 6}, // 3, base-10
                { 1, 5, 7, 9, 15}, // 3, base-2
                { 1, 2, 4, 8, 10}, // 3, base-3
                { 1, 2, 5, 10, 15}, // 3, base-4
            };
            
            bool result;
            for (int testCase = 0; testCase < 5; testCase++) {
                closest5PalindromeNumbers(seed, base[testCase], palindromes);
                result = areEqualArrays(expectedPalindromes[testCase], palindromes, 5);
                Assert::AreEqual(true, result, L"closest5PalindromeNumbers(" + seed + ", " + base[testCase] + ") failed", 1, 2);
            }
        }
	};
}
