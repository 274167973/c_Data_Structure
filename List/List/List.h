#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

//β��βɾ
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);

//ͷ��ͷɾ
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

//���,ɾ��
void SListInsertAfter(SListNode* pos, SListDataType x);
void SListErase(SListNode* pos);

//���Ҵ�ӡ
SListNode* SListFind(SListNode* pphead, SListDataType x);
void SListPrint(SListNode* pphead);