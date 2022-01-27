/*

더블 링크드 리스트



*/

#include "data_structure.h"

DoublyList* createDoublyList()
{
	DoublyList* lst;

	lst = (DoublyList *)malloc(sizeof(DoublyList) * 1);
	lst->currentElementCount = 0;
	lst->headerNode.pLLink = NULL;
	lst->headerNode.pRLink = NULL;
	return (lst);
}

void deleteDoublyList(DoublyList* pList)
{
	DoublyListNode* tmp;
	DoublyListNode* ptr;

	ptr = pList->headerNode.pRLink;
	while (pList->currentElementCount--)
	{
		tmp = ptr->pRLink;
		free(ptr);
		ptr = tmp;
	}
	free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode* ptr;
	DoublyListNode* new_elem;

	if (position < 0)
		return (FALSE);

	new_elem = (DoublyListNode *)malloc(sizeof(DoublyListNode) * 1);
	if (!new_elem)
		return (FALSE);
	new_elem->data = element.data;

	ptr = pList->headerNode.pRLink;
	if (position == 0)
	{
		if (pList->currentElementCount > 0)
		{
			pList->headerNode.pRLink->pLLink = new_elem;
			new_elem->pRLink = pList->headerNode.pRLink;
			pList->headerNode.pRLink = new_elem;

		}
		else
		{
			pList->headerNode.pRLink = new_elem;
			pList->headerNode.pLLink = new_elem;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
	else if (position == pList->currentElementCount)
	{
		pList->headerNode.pLLink->pRLink = new_elem;
		new_elem->pRLink = pList->headerNode.pLLink;
		pList->headerNode.pLLink = new_elem;
		pList->currentElementCount++;
		return (TRUE);
	}
	else
	{
		while (position--)
			ptr = ptr->pRLink;
		ptr->pLLink->pRLink = new_elem;
		new_elem->pLLink = ptr->pLLink;
		new_elem->pRLink = ptr;
		ptr->pLLink = new_elem;
		pList->currentElementCount++;
		return (TRUE);
	}
	free(new_elem);
	return (FALSE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode* ptr;

	if (position < 0 || pList->currentElementCount <= 0 || position > pList->currentElementCount - 1)
		return (FALSE);

	ptr = pList->headerNode.pRLink;
	if (position == 0)
	{
		if (pList->currentElementCount == 1)
		{
			free(pList->headerNode.pRLink);
			pList->headerNode.pRLink = NULL;
			pList->headerNode.pLLink = NULL;
		}
		else
		{
			ptr = pList->headerNode.pRLink->pRLink;
			free(pList->headerNode.pRLink);
			ptr->pLLink = NULL;
			pList->headerNode.pRLink = ptr;
		}
		pList->currentElementCount--;
		return (TRUE);
	}
	else if (position == pList->currentElementCount - 1)
	{
		ptr = pList->headerNode.pLLink;
		ptr->pLLink->pRLink = NULL;
		pList->headerNode.pLLink = ptr->pLLink;
		free(ptr);
		pList->currentElementCount--;
		return (TRUE);
	}
	else
	{
		while (position--)
			ptr = ptr->pRLink;
		ptr->pRLink->pLLink = ptr->pLLink;
		ptr->pLLink->pRLink = ptr->pRLink;
		free(ptr);
		pList->currentElementCount--;
		return (TRUE);
	}
	return (FALSE);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode* ptr;

	ptr = pList->headerNode.pRLink->pRLink;
	while (pList->currentElementCount--)
	{
		free(ptr->pLLink);
		ptr = ptr->pRLink;
	}
}

int getDoublyListLength(DoublyList* pList)
{
	return pList->currentElementCount;
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode* ptr;

	ptr = pList->headerNode.pRLink;
	while (position--)
		ptr = ptr->pRLink;
	return ptr;
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode* ptr;

	ptr = pList->headerNode.pRLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d ", ptr->data);
		ptr = ptr->pRLink;
	}
	printf("\n");
}
