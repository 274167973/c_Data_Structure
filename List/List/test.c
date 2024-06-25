#include"List.h"

//void test01()
//{
//	SListNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 1);
//	SListPrint(&plist);
//}

int main()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPushFront(&plist, 0);
	SListPushFront(&plist, -1);
	SListPushFront(&plist, -2);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	return 0;
}