#include "stdafx.h"
#include "./../src/ButterflyNumber.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;



namespace spec
{
	[TestClass]
	public ref class ButterflyNumber
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
		void ButterflyNumber_Invalid1()
		{
			long long N = -405504;
			long long ans = -1;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase basecase failed", 1, 2);
		};

		void ButterflyNumber_Invalid2()
		{
			long long N = -1;
			long long ans = -1;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase basecase failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void ButterflyNumber_Test1()
		{

			long long N = 12356;
			long long ans = 1235665321;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase 1 failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void ButterflyNumber_Test2()
		{
			long long N = 0;
			long long ans = 0;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase 2 failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void ButterflyNumber_Test3()
		{
			long long N = 10000;
			long long ans = 1000000001;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase 3 failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void ButterflyNumber_Test4()
		{
			long long N = 10;
			long long ans = 1001;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase 3 failed", 1, 2);
		};

		[TestMethod(), Timeout(3000)]
		void ButterflyNumber_Test5()
		{
			long long N = 10000000000000;
			long long ans = -1;
			Assert::AreEqual(ans, butterFlyNumber(N), L"ButterflyNumber testcase 3 failed", 1, 2);
		};
	};
}
