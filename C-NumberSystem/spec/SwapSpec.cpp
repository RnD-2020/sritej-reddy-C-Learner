#include "stdafx.h"
#include "./../src/Swap.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;



namespace spec
{
	[TestClass]
	public ref class SwapSpec
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
		void Swap_Test1()
		{

			int a = 1236, b = -3612;
			swap(&a, &b);
			Assert::AreEqual(-3612, a, L"Swap testcase 1 failed", 1, 2);
			Assert::AreEqual(1236, b, L"Swap testcase 1 failed", 1, 2);
			
		};

		[TestMethod(), Timeout(3000)]
		void Swap_Test2()
		{

			int a = 5, b = 7;
			swap(&a, &b);
			Assert::AreEqual(7, a, L"Swap testcase 2 failed", 1, 2);
			Assert::AreEqual(5, b, L"Swap testcase 2 failed", 1, 2);

		};

		
	};
}
