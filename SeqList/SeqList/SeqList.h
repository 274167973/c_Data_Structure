#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	int size;    //有效数据的长度
	int capacity; //容量
}SL;

//初始化
void SeqListInit(SL* ps);

//销毁
void SeqListDestory(SL* ps);

//打印
void SeqListPrint(SL* ps);

//检查顺序表是否需要扩容
void SeqListCheckCapacity(SL* ps);

//尾插尾删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);

//头插头删
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

//查找
int SeqListFind(SL* ps, SLDataType x);

//插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);


