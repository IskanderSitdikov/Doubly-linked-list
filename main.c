#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    struct Node *previousNode;
    struct Node *nextNode;
    char *string;
};

struct DoublyLinkedList
{
    struct Node *first;
    struct Node *last;
};

struct DoublyLinkedList *createList()
{
    struct DoublyLinkedList *list;
    list = malloc(sizeof(list));
    list->first = NULL;
    list->last = NULL;
    return list;
}

struct Node *createNode(char *string)
{
    struct Node *node;
    node = malloc(sizeof(node));
    node->nextNode = NULL;
    node->previousNode = NULL;
    node->string = string;
    return node;
};

void insert(struct DoublyLinkedList *listPointer, char *string)
{
    struct Node *node = createNode(string);

    if (!listPointer->first)
    {
        listPointer->first = node;
        listPointer->last = node;
    }
    else
    {
        node->previousNode = listPointer->last;
        listPointer->last->nextNode = node;
        listPointer->last = node;
    }
}

void print(struct DoublyLinkedList *list)
{
    printf("Print\n");
    struct Node *node = list->first;
    while (node != NULL)
    {
        printf("%s\n", node->string);
        node = node->nextNode;
    }
}

void printNode(struct Node *node)
{
    if (node == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%s at %d\n", node->string, node);
    }
}

struct Node *find(struct DoublyLinkedList *list, char *string)
{
    struct Node *node = list->first;
    while (node != NULL)
    {
        if (strcmp(node->string, string) == 0)
        {
            return node;
        }

        node = node->nextNode;
    }
}

int delete(struct DoublyLinkedList *list, char *string)
{
    printf("delete\n");
    struct Node *node = find(list, string);

    if (node == NULL)
    {
        return -1;
    }

    if (node == list->first && node == list->last)
    {
        list->first = NULL;
        list->last = NULL;
    }
    else if (node == list->first)
    {
        list->first = node->nextNode;
        node->nextNode->previousNode = NULL;
    }
    else if (node == list->last)
    {
        list->last = node->previousNode;
        node->previousNode->nextNode = NULL;
    }

    free(node);
    return 0;
}

int main()
{
    struct DoublyLinkedList *list = createList();
    insert(list, "item1");
    insert(list, "item2");
    insert(list, "item3");
    // print(list);
    delete (list, "item1");
    // print(list);
    delete (list, "item2");
    // print(list);
    // printNode(find(list, "item1"));
    // printNode(find(list, "item3"));
    // print(list);
}