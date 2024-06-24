#include"SeqList.h"

//��ʼ��
void SeqListInit(SL* ps)
{
	ps->array = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->array == NULL)
	{
		printf("�ڴ治��,˳�������ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//����
void SeqListDestory(SL* ps)
{
	free(ps->array);
	ps->array = NULL;
	ps->size = ps->capacity = 0;
}

//��ӡ
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}

//���˳����Ƿ���Ҫ����
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	//�ж��Ƿ���Ҫ����,��˳�������ʱ��Ҫ����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		//realloc����:����,��ԭ���������ƶ����µĿռ�,������ԭ�ռ�
		ps->array = (SLDataType*)realloc(ps->array,sizeof(SLDataType) * ps->capacity);
		if (ps->array == NULL)
		{
			printf("�ڴ治��,����ʧ��\n");
			exit(-1);
		}
	}
}

//β��βɾ
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

//ͷ��ͷɾ
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

//����
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

//����ɾ��
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
