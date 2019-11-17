#include "pch.h"
#include "CppUnitTest.h"
#include "../Skobki/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSkobki1
{
	TEST_CLASS(TestSkobki1)
	{
	public:
		
		TEST_METHOD(Test_1)
		{
			Assert::IsTrue(skobki("([](){([])})") == "Success");
		}
		TEST_METHOD(Test_2)
		{
			Assert::IsTrue(skobki("()[]}") == "5");
		}
		TEST_METHOD(Test_3)
		{
			Assert::IsTrue(skobki("{{[()]]") == "7");
		}
		TEST_METHOD(Test_4)
		{
			Assert::IsTrue(skobki("([](){([])})") == "Success");
		}
		TEST_METHOD(Test_5)
		{
			Assert::IsTrue(skobki("()[]}") == "5");
		}
		TEST_METHOD(Test_6)
		{
			Assert::IsTrue(skobki("{{{[][][]") == "3");
		}
		TEST_METHOD(Test_7)
		{
			Assert::IsTrue(skobki("{*{{}") == "3");
		}
		TEST_METHOD(Test_8)
		{
			Assert::IsTrue(skobki("[[*") == "2");
		}
		TEST_METHOD(Test_9)
		{
			Assert::IsTrue(skobki("{*}") == "Success");
		}
		TEST_METHOD(Test_10)
		{
			Assert::IsTrue(skobki("{{") == "2");
		}
		TEST_METHOD(Test_11)
		{
			Assert::IsTrue(skobki("{}") == "Success");
		}
		TEST_METHOD(Test_12)
		{
			Assert::IsTrue(skobki("") == "Success");
		}
		TEST_METHOD(Test_13)
		{
			Assert::IsTrue(skobki("}") == "1");
		}
		TEST_METHOD(Test_14)
		{
			Assert::IsTrue(skobki("*{}") == "Success");
		}
		TEST_METHOD(Test_15)
		{
			Assert::IsTrue(skobki("{{{**[][][]") == "3");
		}
		TEST_METHOD(Test_16)
		{
			Assert::IsTrue(skobki("[]") == "Success");
		}
		TEST_METHOD(Test_17)
		{
			Assert::IsTrue(skobki("{}[]") == "Success");
		}
		TEST_METHOD(Test_18)
		{
			Assert::IsTrue(skobki("[()]") == "Success");
		}
		TEST_METHOD(Test_19)
		{
			Assert::IsTrue(skobki("(())") == "Success");
		}
		TEST_METHOD(Test_20)
		{
			Assert::IsTrue(skobki("{[]}()") == "Success");
		}
		TEST_METHOD(Test_21)
		{
			Assert::IsTrue(skobki("{") == "1");
		}
		TEST_METHOD(Test_22)
		{
			Assert::IsTrue(skobki("{[}") == "3");
		}
		TEST_METHOD(Test_23)
		{
			Assert::IsTrue(skobki("foo(bar)") == "Success");
		}
		TEST_METHOD(Test_24)
		{
			Assert::IsTrue(skobki("foo(bar[i)") == "10");
		}
		TEST_METHOD(Test_25)
		{
			Assert::IsTrue(skobki("({[") == "3");
		}
		TEST_METHOD(Test_26)
		{
			Assert::IsTrue(skobki("({{}") == "2");
		}
		TEST_METHOD(Test_27)
		{
			Assert::IsTrue(skobki("(()") == "1");
		}
		TEST_METHOD(Test_28)
		{
			Assert::IsTrue(skobki("]]]") == "1");
		}
		TEST_METHOD(Test_29)
		{
			Assert::IsTrue(skobki("{[}]") == "3");
		}
		

	};
}
