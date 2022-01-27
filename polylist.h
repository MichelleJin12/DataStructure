#ifndef _POLYLIST_
#define _POLYLIST_

typedef struct PolyListNodeType
{
	int degree; //차수
	float coef; //계수
	struct ListNodeType* pLink;
} PolyListNode;

typedef struct PolyLinkedListType {
	int currentElementCount;
	PolyListNode headerNode;
} PolyLinkedList;

int addPolyNodeLast(PolyLinkedList* pList, float coef, int degree);
PolyLinkedList* PolyAdd(PolyLinkedList* pListA, PolyLinkedList* pListB);
void displayPolyList(PolyLinkedList* pList);

PolyLinkedList* createPolyLinkedList();
int addPLLElement(PolyLinkedList* pList, int position, PolyListNode element);
int removePLLElement(PolyLinkedList* pLIst, int position);
PolyListNode* getPLLElement(PolyLinkedList* pList, int position);

void clearPolyLinkedList(PolyLinkedList* pList);
int getPolyLinkedListLength(PolyLinkedList* pList);
void deletePolyLinkedList(PolyLinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE    1
#define FALSE    0
#endif
