#include"Stack.h"

//初始化
void StackInit(Stack* pst)
{
	pst->_a = (STDataType*)malloc(sizeof(STDataType)*4);
	pst->top = 0;
	pst->capacity = 4;
}
//销毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->top = pst->capacity = 0;
}
//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top >= pst->capacity)
	{
		pst->capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->capacity);
		if (tmp == NULL)
		{
			printf("内存不够\n");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->top++] = x;

}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
//栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->_a[pst->top - 1];
}
//获取栈中的元素个数
int StackSize(Stack* pst);
//判断栈是否为空
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}