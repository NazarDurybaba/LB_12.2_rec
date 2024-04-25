#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreateNode)
		{
			Node* newNode = createNode(5);
			Assert::IsNotNull(newNode);
			Assert::AreEqual(newNode->data, 5);
			Assert::IsNull(newNode->next);
			delete newNode; 
		}

		TEST_METHOD(TestInsertNode)
		{
			Node* head = nullptr;
			head = insertNode(head, 1);
			Assert::IsNotNull(head);
			Assert::AreEqual(head->data, 1);
			Assert::IsNull(head->next);

			head = insertNode(head, 2);
			Assert::IsNotNull(head->next);
			Assert::AreEqual(head->next->data, 2);
			Assert::IsNull(head->next->next);
		}

		TEST_METHOD(TestSumPositiveValues)
		{
			Node* head = nullptr;
			head = insertNode(head, 1);
			head = insertNode(head, -2);
			head = insertNode(head, 3);
			head = insertNode(head, 4);
			head = insertNode(head, -5);

			int sum = sumPositiveValues(head);
			Assert::AreEqual(sum, 8); // 1 + 3 + 4 = 8
		}
	};
}
