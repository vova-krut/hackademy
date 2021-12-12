#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  node {
    void        *data;
    struct node *next;
}              node_t;

node_t *list_create(void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    if((*head) == NULL)
    {
        return;
    }
    fp((*head) -> data);
    node_t *current = *head;
    node_t *next;
    while(current != NULL)
    {
        next = current -> next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void list_push(node_t *head, void *data)
{
    node_t *current = head;
    while (current -> next != NULL)
    {
        current = current -> next;
    }
    current -> next = list_create(data);
}
void list_unshift(node_t **head, void *data)
{
    node_t *new_node = list_create(data);
    new_node -> next = *head;
    (*head) = new_node;
}
void *list_pop(node_t **head)
{
    node_t *current = *head;
    while (current -> next -> next != NULL)
    {
        current = current -> next;
    }
    void *data = current -> data;
    free(current -> next);
    current -> next = NULL;
    return data;
}
void *list_shift(node_t **head)
{
    node_t *temp = *head;
    *head = temp -> next;
    void *data = temp -> data;
    free(temp);
    return data;
}
void *list_remove(node_t **head, int pos)
{
    node_t *current = *head;
    node_t *next = current -> next;
    for(int i = 0; i < pos - 1; i++)
    {
        current = current -> next;
        next = next -> next;
    }
    void *data = next -> data;
    current -> next = next -> next;
    free(next);
    return data;
}
void list_print(node_t *head)
{
    while(head -> next != NULL)
    {
        printf("%s\n",(char *)head -> data);
        head = head -> next;
    }
}
void list_visitor(node_t *head, void (*fp)(void *data))
{
    while(head -> next != NULL)
    {
        list_visitor(head -> next, fp);
    }
    fp(head -> data);
}
