#include"List.h"

//����½��
SListNode* BuyListNode(SListDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//β��βɾ
void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
	}
}

//ͷ��ͷɾ
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead= NULL;
	}
	else
	{
		SListNode* head = *pphead;
		*pphead= head->next;
		free(head);
		head = NULL;
	}
}

//���,ɾ��
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	SListNode* newnode = BuyListNode(x);
	SListNode* next = pos->next;
	newnode->next = next;
	pos->next = newnode;
}
void SListErase(SListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
}

//���Ҵ�ӡ
SListNode* SListFind(SListNode* pphead, SListDataType x)
{
	SListNode* cur = pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListPrint(SListNode* pphead)
{
	SListNode* cur = pphead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}