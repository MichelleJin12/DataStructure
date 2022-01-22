/*

linked list 구현하기

1. node 생성
2. node 맨 앞 연결
3. node 중간 연결
4. node 맨 뒤 연결
5. node 처음 삭제
6. node 중간 삭제
7. node 마지막 삭제

*/

#include "data_structure.h"

LinkedList* createLinkedList()
{
	LinkedList *lst;

	lst = (LinkedList *)malloc(sizeof(LinkedList) * 1);
	if (!lst)
		return (NULL);
	return lst;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *new_elem;
	ListNode *ptr;
	ListNode *tmp;

	if (position < 0)
		return (FALSE);

	new_elem = (ListNode *)malloc(sizeof(ListNode) * 1);
	if (!new_elem)
		return (FALSE);
	new_elem->data = element.data;

	ptr = pList->headerNode.pLink;

	if (position <= pList->currentElementCount)
	{
		// 맨 앞 삽입
		if (position == 0)
		{
			new_elem->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new_elem;
		}
		// 맨 뒤 삽입
		else if (position == pList->currentElementCount)
		{
			while (position--)
				ptr = ptr->pLink;
			ptr->pLink = new_elem;
		}
		// 중간 삽입
		else
		{
			while (position--)
			{
				tmp = ptr;
				ptr = ptr->pLink;
			}
			tmp->pLink = new_elem;
			new_elem->pLink = ptr;
		}
		pList->currentElementCount++;
		return TRUE;
	}
	return FALSE;
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *ptr;
	ListNode *tmp;

	if (position < 0)
		return (FALSE);

	ptr = pList->headerNode.pLink;

	if (position < pList->currentElementCount)
	{
		if (position == 0)
		{
			ptr = pList->headerNode.pLink;
			pList->headerNode.pLink = ptr->pLink;
			free(ptr);
		}
		else if (position == pList->currentElementCount - 1)
		{
			while (position--)
			{
				tmp = ptr;
				ptr = ptr->pLink;
			}
			tmp->pLink = NULL;
			free(ptr);
		}
		else
		{
			while (position--)
			{
				tmp = ptr;
				ptr = ptr->pLink;
			}
			tmp->pLink = ptr->pLink;
			free(ptr);
		}
		pList->currentElementCount--;
		return (TRUE);
	}
	return FALSE;
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *ptr;

	if (position < 0)
		return (NULL);

	ptr = pList->headerNode.pLink;
	if (position < pList->currentElementCount)
	{
		while (position--)
			ptr = ptr->pLink;
		return ptr;
	}
	return (NULL);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *ptr;

	ptr = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
		ptr->data = 0;
	ptr->pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	ListNode *ptr;
	int i;

	i = 0;
	ptr = pList->headerNode.pLink;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->pLink;
	}
	return (i);
}

void deleteLinkedList(LinkedList* pList)
{
	ListNode *ptr;
	ListNode *tmp;

	ptr = pList->headerNode.pLink;
	while (ptr)
	{
		tmp = ptr->pLink;
		free(ptr);
		ptr = tmp;
	}
	free(pList);
}

void displayLinkedList(LinkedList* pList)
{
	ListNode *ptr;

	ptr = pList->headerNode.pLink;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->pLink;
	}
	printf("\n");
}
