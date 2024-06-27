#include"Stack.h"

//��ʼ��
void StackInit(Stack* pst)
{
	pst->_a = (STDataType*)malloc(sizeof(STDataType)*4);
	pst->top = 0;
	pst->capacity = 4;
}
//����
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->top = pst->capacity = 0;
}
//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top >= pst->capacity)
	{
		pst->capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->capacity);
		if (tmp == NULL)
		{
			printf("�ڴ治��\n");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->top++] = x;

}
//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
//ջ��Ԫ��
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->_a[pst->top - 1];
}
//��ȡջ�е�Ԫ�ظ���
int StackSize(Stack* pst);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}