#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 *
 * Description: The idea is to use Floyd's Tortoise & Hare Algorithm
 * Space complexity O(1)
 * Time complexity O(n)
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *head = list;
	listint_t *fast = head;
	listint_t *slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (true);
	}
	return (false);
}
