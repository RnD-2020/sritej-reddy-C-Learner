#include "stdafx.h"
#include "./../src/AverageofN.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;



namespace spec
{
	[TestClass]
	public ref class AverageofNSpec
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
		void AverageOfN_NULLCase()
		{

			int ans=averageOfN(NULL,-1);
			Assert::AreEqual(-1, ans, L"Null case failed to execute- testcase 0 failed", 1, 2);	

		};

		[TestMethod(), Timeout(3000)]
		void AverageOfN_InvalidSize()
		{

			int arr[] = { -1, -1, -1, -1, -2 };
			int N = 5;
			int ans = averageOfN(arr, 0);
			Assert::AreEqual(-1, ans, L"testcase 2 failed", 1, 2);

		};

		[TestMethod(), Timeout(3000)]
		void AverageOfN_Test1()
		{

			int arr[] = { 0, 0, 0, 0, 0 };
			int N = 5;
			int ans = averageOfN(arr, N);
			Assert::AreEqual(0, ans, L"testcase 1 failed", 1, 2);

		};

		[TestMethod(), Timeout(3000)]
		void AverageOfN_Test2()
		{

			int arr[] = { -1, -1, -1, -1, -2 };
			int N = 5;
			int ans = averageOfN(arr, N);
			Assert::AreEqual(-1, ans, L"testcase 2 failed", 1, 2);

		};

		[TestMethod(), Timeout(3000)]
		void AverageOfN_Test3()
		{
			int high_value = INT_MAX;
			int arr[] = { high_value, high_value, high_value, high_value, high_value, 
				high_value, high_value, high_value, high_value, high_value, };
			int N = 10;
			int ans = averageOfN(arr, N);
			Assert::AreEqual(high_value, ans, L"testcase 2 failed", 1, 2);

		};
	};
}
