#include"SeqList.h"

//初始化
void SeqListInit(SL* ps)
{
	ps->array = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->array == NULL)
	{
		printf("内存不足,顺序表申请失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//销毁
void SeqListDestory(SL* ps)
{
	free(ps->array);
	ps->array = NULL;
	ps->size = ps->capacity = 0;
}

//打印
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}

//检查顺序表是否需要扩容
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	//判断是否需要扩容,当顺序表满了时需要扩容
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		//realloc函数:扩容,将原来的数据移动到新的空间,并销毁原空间
		ps->array = (SLDataType*)realloc(ps->array,sizeof(SLDataType) * ps->capacity);
		if (ps->array == NULL)
		{
			printf("内存不足,开辟失败\n");
			exit(-1);
		}
	}
}

//尾插尾删
void SeqListPushBack(SL* ps, SLDataType x)
{
	//assert(ps);
	/*SeqListCheckCapacity(ps);
	ps->array[ps->size++] = x;*/
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopBack(SL* ps)
{
	/*assert(ps);
	ps->size--;*/
	SeqListErase(ps, ps->size - 1);
}

//头插头删
void SeqListPushFront(SL* ps, SLDataType x)
{
	//assert(ps);
	/*SeqListCheckCapacity(ps);
	for (int i = ps->size-1; i >= 0; --i)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[0] = x;
	ps->size++;*/
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SL* ps)
{
	/*assert(ps);
	for (int i = 0; i < ps->size-1; ++i)
	{
		ps->array[i] = ps->array[i+1];
	}
	ps->size--;*/
	SeqListErase(ps, 0);

}

//查找
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->array[i] == x)
		{
			return i;
		}
		++i;
	}
	return -1;
}

//插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = ps->size-1; i >=pos; --i)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size-1; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}
