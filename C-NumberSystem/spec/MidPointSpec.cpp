#include "stdafx.h"
#include "./../src/MidPoint.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;



namespace spec
{
	[TestClass]
	public ref class MidPointSpec
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
		void MidPoint_Test1()
		{

			int a = 0, b = 0;
			int temp=midPoint(a, b);
			Assert::AreEqual(0, temp, L"MidPoint testcase 1 failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void MidPoint_Test2()
		{

			int a = 5, b = 7;
			int temp = midPoint(a, b);
			Assert::AreEqual(6, temp, L"MidPoint testcase 2 failed", 1, 2);

		};

		[TestMethod(), Timeout(3000)]
		void MidPoint_Test3()
		{
			//INT_MIN is equal to -2147483648
			int a = -2147483647LL, b = -2147483647LL;
			long long temp = midPoint(a, b);
			Assert::AreEqual(-2147483647LL, temp, L"MidPoint testcase 3 failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void MidPoint_Test4()
		{
			//INT_MAX is equal to 2147483647
			int a = 2147483647, b = 2147483647;
			int temp = midPoint(a, b);
			Assert::AreEqual(2147483647, temp, L"MidPoint testcase 3 failed", 1, 2);
		};


	};
}
