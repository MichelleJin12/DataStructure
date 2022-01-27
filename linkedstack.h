#ifndef _LINKEDSTACK_
#define _LINKEDSTACK_

typedef struct LinkedStackNodetype {
	char data;
	struct LinkedStackNodetype *pLink;		//링크
}	LinkedStackNode;

typedef struct LinkedStacktype {
	int currentCount;
	LinkedStackNode *pTop;				// 탑 노드의 포인터
}	LinkedStack;

LinkedStack	*createLinkedStack(void);
int	pushLS(LinkedStack *pStack, char data);
int	isLinkedStackEmpty(LinkedStack *pStack);
LinkedStackNode *popLS(LinkedStack *pStack);
LinkedStackNode *peekLS(LinkedStack *pStack);
void	deleteLinkedStack(LinkedStack *pStack);
void	displayLinkedStack(LinkedStack *pStack);

#endif
