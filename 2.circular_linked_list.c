/*
원형 링크드 리스트

head
tail
맨 마지막 -> 맨 처음 가리키고 있어야함

head 추가
중간 추가
tail 추가

head 제거
중간 제거
tail 제거

*/

# include "data_structure.h"

LinkedList* createCircularLinkedList()
{
	LinkedList *lst;

	lst = (LinkedList *)malloc(sizeof(LinkedList) * 1);
	lst->headerNode.pLink = NULL;
	lst->currentElementCount = 0;
	return (lst);
}

int addCLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *new_elem;
	ListNode *ptr;
	ListNode *tmp;

	ptr = pList->headerNode.pLink;

	new_elem = (ListNode *)malloc(sizeof(ListNode) * 1);
	if (!new_elem)
		return (FALSE);

	new_elem->pLink = NULL;
	new_elem->data = element.data;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);

	if (position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			pList->headerNode.pLink = new_elem;
			new_elem->pLink = new_elem;
		}
		else
		{
			for (int i = 0; i < pList->currentElementCount - 1; i++)
				ptr = ptr->pLink;
			ptr->pLink = new_elem;
			new_elem->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new_elem->pLink;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
	else
	{
		while (position--)
		{
			tmp = ptr;
			ptr = ptr->pLink;
		}
		tmp->pLink = new_elem;
		new_elem->pLink = ptr;
		pList->currentElementCount++;
		return (TRUE);
	}
	free(new_elem);
	return (FALSE);
}

int removeCLLElement(LinkedList* pList, int position)
{
	ListNode *tmp;
	ListNode *ptr;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount <= 0)
		return (FALSE);

	ptr = pList->headerNode.pLink;

	if (position == 0)
	{
		if (pList->currentElementCount == 1)
		{
			free(pList->headerNode.pLink);
			pList->headerNode.pLink = NULL;
		}
		else
		{
			for (int i = 0; i < pList->currentElementCount - 1; i++)
				ptr = ptr->pLink;
			ptr->pLink = pList->headerNode.pLink->pLink;
			free(pList->headerNode.pLink);
			pList->headerNode.pLink = ptr->pLink;
		}
		pList->currentElementCount--;
		return (TRUE);
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
		pList->currentElementCount--;
		return (TRUE);
	}
	return (FALSE);
}

ListNode* getCLLElement(LinkedList* pList, int position)
{
	ListNode *ptr;

	ptr = pList->headerNode.pLink;
	while (position--)
		ptr = ptr->pLink;
	return (ptr);
}

void clearCircularLinkedList(LinkedList* pList)
{
	ListNode *tmp;
	ListNode *ptr;

	ptr = pList->headerNode.pLink;
	while (pList->currentElementCount--)
	{
		tmp = ptr->pLink;
		free(ptr);
		ptr = tmp;
	}
	pList->headerNode.pLink = NULL;
}

int getCircularLinkedListLength(LinkedList* pList)
{
	return pList->currentElementCount;
}

void deleteCircularLinkedList(LinkedList* pList)
{
	ListNode *tmp;
	ListNode *ptr;

	ptr = pList->headerNode.pLink;
	while (pList->currentElementCount--)
	{
		tmp = ptr->pLink;
		free(ptr);
		ptr = tmp;
	}
	free(pList);
}

void displayCircularLinkedList(LinkedList* pList)
{
	ListNode *ptr;

	ptr = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d ", ptr->data);
		ptr = ptr->pLink;
	}
	printf("\n");
}
