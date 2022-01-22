#include "data_structure.h"


int main(int argc, char *argv[])
{
	int number;
	ArrayList* arr;
	LinkedList* lst;

	if (argc == 2)
	{
		number = *argv[1] - '0';
		switch (number)
		{
		case 1:
			// 1.array
			printf("##############ARRAY####################\n");
			arr = createArrayList(10);
			for (int i = 1; i <= 10; i++)
			{
				ArrayListNode node;
				node.data = i;
				addALElement(arr, 0, node);
			}
			displayArrayList(arr);
			for (int i = 9; i >= 0; i--)
			{
				printf("[drop: %d], [arr leng: %d]\n", getALElement(arr, i)->data,
				getArrayListLength(arr));
				removeALElement(arr, i);
				displayArrayList(arr);
			}

			// 1.linked_list
			printf("##############LINKED_LIST##############\n");
			lst = createLinkedList();
			for (int i = 1; i <= 10; i++)
			{
				ListNode node;
				node.data = i;
				addLLElement(lst, 0, node);
			}
			displayLinkedList(lst);
			for (int i = 9; i >= 0; i--)
			{
				printf("[drop: %d], [list leng: %d]\n", getLLElement(lst, i)->data, getLinkedListLength(lst));
				removeLLElement(lst, i);
				displayLinkedList(lst);
			}
			deleteArrayList(arr);
			deleteLinkedList(lst);
			break;

		default:
			break;
			// 2.circular_linked_list


			// 2. double_linked_list


			// 2. polynomial_addition


			// 2. reverse_linked_list


			// 3. stack array


			// 3. stack_linked_list


			// 4. maze


			// 5. circular queue


			// 5. deque


			// 5. queue


			// 6. queue_simulation


			// 7. binary_tree_traversal


			// 7. binary tree

			// 8. binary search tree


			// 8. heap


			// 9. linked_list_graph

			// 10.dijkstra

			// 10. floyd

			// 10. krusckal


			// 10. minimum spanning tree


			// 10. prim

			// 11. sort

			// 12. search
		}
	}
	return (0);
}
