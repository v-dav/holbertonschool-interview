#include "lists.h"

/**
 * insert_node - inserts a node in a sorted linked list at the right position
 * @head: pointer to pointer of the first node of listint_t list
 * @number: integer to be included in the new node
 * Return: address of the new element or NULL if it fails
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *current = NULL;

	current = *head;
	new = (listint_t *)malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else if (current->n > new->n)
	{
		new->next = current;
		*head = new;
		current = NULL;
	}
	else
	{
		while (current->next != NULL && current->next->n < new->n)
			current = current->next;
		new->next = current->next;
		current->next = new;
	}

	return (*head);
}
