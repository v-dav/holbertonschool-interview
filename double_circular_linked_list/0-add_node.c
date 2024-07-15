#include "list.h"

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

/**
 * *add_node_begin - Adds a node at the start of a doubly circular linked list
 * @list: The list to be edited
 * @str: The string to copy into the new node
 *
 * Return: Address of new node or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	if (str == NULL)
	{
		free(new_node);
		return (NULL);
	}


	new_node->str = strdup(str);

	if (*list)
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		((*list)->prev)->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;

	}
	else
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}

	return (new_node);
}

/**
 * *add_node_end - Adds a node at the end of a doubly circular linked list
 * @list: The list to be edited
 * @str: The string to copy into the new node
 *
 * Return: Address of new node or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	if (str == NULL)
	{
		free(new_node);
		return (NULL);
	}

		new_node->str = strdup(str);

	if (*list)
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		((*list)->prev)->next = new_node;
		(*list)->prev = new_node;
	}
	else
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}

	return (new_node);
}
