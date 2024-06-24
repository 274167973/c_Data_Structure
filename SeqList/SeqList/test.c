#include"SeqList.h"

//À≥–Ú±Ì≤‚ ‘
void SeqListTest01()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListDestory(&s);

}

int main()
{
	SeqListTest01();

	return 0;
}