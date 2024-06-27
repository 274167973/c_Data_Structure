#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//返回1是空，返回0是非空
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

