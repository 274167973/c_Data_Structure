#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int top;
	int capacity;
}Stack;

//��ʼ��
void StackInit(Stack* pst);
//����
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);
//ջ��Ԫ��
STDataType StackTop(Stack* pst);
//��ȡջ�е�Ԫ�ظ���
int StackSize(Stack* pst);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* pst);

