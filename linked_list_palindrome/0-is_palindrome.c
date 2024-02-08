#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the pointer of the head of the list
 *
 * Desciption: Time complexity O(n), space complexity O(1)
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev, *temp;

	if (*head == NULL)
		return (1);
	/**
	 * Find the middle of the list with "slow" by
	 * Floyd's Cycle Detection Algorithm
	 */
	while (slow && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	/*Set up for reversing*/
	prev = slow;
	slow = slow->next;
	prev->next = NULL;
	/*Reversing the second half of the list*/
	while (slow)
	{
		temp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = temp;
	}
	/*Moving fast and slow to extremities of the list*/
	fast = *head;
	slow = prev;

	/*Check if its a palindrome*/
	while (slow && fast)
	{
		if (slow->n != fast->n)
			return (0);
		slow = slow->next;
		fast = fast->next;
	}
	return (1);
}
