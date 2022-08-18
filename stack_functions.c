#include "monty.h"
/**
 * add_dnodeint_end - Write a function that adds a new node
 * at the end of a dlistint_t list.
 * @head: pointer to pointer head node
 * @n: data
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t  *new_node;
	stack_t *last = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node)
	{
		new_node->n = n;
		new_node->next = NULL;
		if (*head == NULL)
		{
			*head = new_node;
			new_node->prev = NULL;
		}
		else
		{
			while (last->next != NULL)
				last = last->next;
			last->next = new_node;
			new_node->prev = last;
		}
	}
	else
		free(new_node);
	return (new_node);
}

/**
 * *add_dnodeint - Write a function that adds a new node at
 * the beginning of a dlistint_t list.
 * @head: pointer to pointer of head node
 * @n: data
 * Return: address of the new element or null
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *nnode = NULL;

	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error_exit(head);
	}


	nnode->n = n;
	if (*head)
	{
		nnode->next = *head;
		nnode->prev = (*head)->prev;
		(*head)->prev = nnode;
		*head = nnode;
		return (*head);
	}

	nnode->next = *head;
	nnode->prev = NULL;
	*head = nnode;
	return (*head);
}
