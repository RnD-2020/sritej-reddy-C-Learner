#include "stdafx.h"
#include "./../src/BigFibonacci.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;



namespace spec
{
	[TestClass]
	public ref class BigFibonacci
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

#pragma region Additional test attributes

#pragma endregion 




		[TestMethod(), Timeout(3000)]
		void BigFibonacci_Basic_Test()
		{

			int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int output[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
			for (int i = 0; i < 9; i++){
				Assert::AreEqual(output[i],bigFibonacci(input[i]), L"BigFibonacci testcase Basic failed", 1, 2);
			}
		};

		[TestMethod(), Timeout(3000)]
		void BigFibonacci_Medium_Test()
		{
			int input[] = { 40, 80, 100, 99 };
			int output[] = { 102334155, 184550589, 687995182, 94208912 };
			for (int i = 0; i < 4; i++){
				Assert::AreEqual(output[i], bigFibonacci(input[i]), L"BigFibonacci testcase Medium failed", 1, 2);
			}
		};

		[TestMethod(), Timeout(3000)]
		void BigFibonacci_Invalid_Test()
		{
			int N = 0;
			Assert::AreEqual(-1, bigFibonacci(N), L"BigFibonacci testcase Invalid failed", 1, 2);

			N = -1;
			Assert::AreEqual(-1, bigFibonacci(N), L"BigFibonacci testcase Invalid failed", 1, 2);

			N = -2;
			Assert::AreEqual(-1, bigFibonacci(N), L"BigFibonacci testcase Invalid failed", 1, 2);

			N = -100;
			Assert::AreEqual(-1, bigFibonacci(N), L"BigFibonacci testcase Invalid failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void BigFibonacci_Large_Test()
		{

			int input[] = { 999, 1000, 1001 };
			int output[] = { 589888339, 517691607, 107579939 };
			for (int i = 0; i < 3; i++){
				Assert::AreEqual(output[i], bigFibonacci(input[i]), L"BigFibonacci testcase Large failed, overflow condition! case", 1, 2);
			}
		};



	};
}
