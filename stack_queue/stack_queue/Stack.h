#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��̬
//struct Stack
//{
//	int _a[N];
//	int _size;
//};

typedef  int STDataType;
typedef struct Stack
{
	STDataType *_a;
	int _top;  //ջ���±�
	int _capacity;
}Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);
//��ȡ���ݸ���
int StackSize(Stack* pst);

//����1�ǿգ�����0�Ƿǿ�
int StackEmpty(Stack* pst);
//��ȡջ��������
STDataType StackTop(Stack* pst);