/*

array stack

*/

#include "data_structure.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack * arr;

    arr = (ArrayStack *) malloc(sizeof(ArrayStack) * 1);
    if (!arr)
        return (NULL);
    
    arr->maxElementCount = maxElementCount;
    arr->currentElementCount = 0;
    arr ->pElement = (ArrayStackNode *) malloc(sizeof(ArrayStackNode) * maxElementCount);

    if (!arr->pElement)
    {
        free(arr);
        return (NULL);
    }

    return arr;
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
    if (!isArrayStackFull(pStack))
    {
        pStack->pElement[pStack->currentElementCount].data = element.data;
        pStack->currentElementCount++;
        return (TRUE);
    }
    else
        return (FALSE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
    if (!isArrayStackEmpty(pStack))
    {
        pStack->pElement[pStack->currentElementCount - 1].data = 0;
        pStack->currentElementCount--;
        return &(pStack->pElement[pStack->currentElementCount - 1]);
    }
    else
        return (NULL);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
    if (!isArrayStackEmpty(pStack))
        return &(pStack->pElement[pStack->currentElementCount - 1]);
    else
        return (NULL);
}

void deleteArrayStack(ArrayStack* pStack)
{
    free(pStack->pElement);
    free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
    if (pStack->currentElementCount >= pStack->maxElementCount)
        return (TRUE);
    else
        return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
    if (pStack->currentElementCount == 0)
        return (TRUE);
    else
        return (FALSE);
}

void displayArrayStack(ArrayStack* pStack)
{
    for (int i = 0; i < pStack->maxElementCount; i++)
        printf("%d ", pStack->pElement[i].data);
    printf("\n");
}