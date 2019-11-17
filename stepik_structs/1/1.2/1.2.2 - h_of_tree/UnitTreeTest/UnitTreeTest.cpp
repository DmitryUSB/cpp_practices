#include "pch.h"
#include "CppUnitTest.h"
#include "../Tree/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTreeTest
{
	TEST_CLASS(UnitTreeTest)
	{
	public:
		
		TEST_METHOD(Test_1)
		{
			vector<int> in{9, 7, 5, 5, 2, 9, 9, 9, 2, -1};
			Assert::AreEqual(calc_tree_H(in), 4);
		}
		TEST_METHOD(Test_2)
		{
			vector<int> in{ 4, -1, 4, 1, 1 };
			Assert::AreEqual(calc_tree_H(in), 3);
		}
		TEST_METHOD(Test_3)
		{
			vector<int> in{ -1, 0, 4, 0, 3 };
			Assert::AreEqual(calc_tree_H(in), 4);
		}
		/*TEST_METHOD(Test_4)
		{
			vector<int> in{ 9, 7, 5, 5, 2, 9, 9, 9, 2, -1 };
			Assert::AreEqual(calc_tree_H(in), 4);
		}*/
	};
}
