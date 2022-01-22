/*
배열 구현하기

배열에 넣기
배열에 빼기
오버플로우 처리
*/

#include "data_structure.h"

/*
ArrayList를 생성하고 maxElementCount만큼 ArrayListNode를 할당하여 리턴
*/
ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* arr;

	arr = (ArrayList *)malloc(sizeof(ArrayList) * 1);
	if (!arr)
		return (NULL);
	arr->currentElementCount = 0;
	arr->maxElementCount = maxElementCount;
	arr->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!arr->pElement)
		return (NULL);
	return (arr);
}

/*
ArrayList 안에 pElement 메모리 해제
ArrayList 메모리 해제
*/
void deleteArrayList(ArrayList* pList)
{
	free(pList->pElement);
	free(pList);
}

/*
Array가 maxElementCount만큼 다 찼는지 확인
*/
int isArrayListFull(ArrayList* pList)
{
	if (pList->currentElementCount >= pList->maxElementCount)
		return TRUE;
	else
		return FALSE;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (position < pList->maxElementCount && !isArrayListFull(pList))
	{
		for (int i = pList->currentElementCount; i > position; i--)
		{
			pList->pElement[i].data = pList->pElement[i - 1].data;
		}
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
		return TRUE;
	}
	else
		return FALSE;
}

int removeALElement(ArrayList* pList, int position)
{
	if (position < pList->maxElementCount)
	{
		for (int i = position; i < pList->currentElementCount - 1; i++)
		{
			pList->pElement[i].data = pList->pElement[i + 1].data;
		}
		pList->pElement[pList->currentElementCount - 1].data = 0;
		pList->currentElementCount--;
		return TRUE;
	}
	return FALSE;
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (position < pList->maxElementCount)
		return &(pList->pElement[position]);
	return NULL;
}

/*
pList 원소 출력
*/
void displayArrayList(ArrayList* pList)
{
	for (int i = 0; i < pList->maxElementCount; i++)
	{
		printf("%d ", pList->pElement[i].data);
	}
	printf("\n");
}

/*
pList 원소 초기화
*/
void clearArrayList(ArrayList* pList)
{
	for (int i = 0; i < pList->maxElementCount; i++)
		pList->pElement[i].data = 0;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	return pList->currentElementCount;
}
