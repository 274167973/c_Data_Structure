#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	int size;    //��Ч���ݵĳ���
	int capacity; //����
}SL;

//��ʼ��
void SeqListInit(SL* ps);

//����
void SeqListDestory(SL* ps);

//��ӡ
void SeqListPrint(SL* ps);

//���˳����Ƿ���Ҫ����
void SeqListCheckCapacity(SL* ps);

//β��βɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);

//ͷ��ͷɾ
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

//����
int SeqListFind(SL* ps, SLDataType x);

//����ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);


