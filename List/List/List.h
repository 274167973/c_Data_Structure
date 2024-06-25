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

//Œ≤≤ÂŒ≤…æ
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);

//Õ∑≤ÂÕ∑…æ
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

//∫Û≤Â,…æ≥˝
void SListInsertAfter(SListNode* pos, SListDataType x);
void SListErase(SListNode* pos);

//≤È’“¥Ú”°
SListNode* SListFind(SListNode* pphead, SListDataType x);
void SListPrint(SListNode* pphead);