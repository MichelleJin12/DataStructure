#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct ArrayStackNodeType {
    char data;
}ArrayStackNode;

typedef struct ArrayStackType {
    int maxElementCount;
    int currentElementCount;
    ArrayStackNode* pElement;    //노드 저장을 위한 1차원 배열
}ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
void displayArrayStack(ArrayStack* pStack);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE    1
#define FALSE    0
#endif
