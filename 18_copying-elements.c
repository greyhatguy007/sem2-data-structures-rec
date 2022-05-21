/*

Write a C Program to copy the elements of one List to another List using Linked List Concept.

Input:

m - Elements in List1

m Elements of List1

Output:

m Elements of List2 copied from List1

*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node node;

void insert(node *list, int x)
{
    node *newnode = malloc(sizeof(node));
    newnode->element = x;
    newnode->next = NULL;
    node *position = list;
    while (position->next != NULL)
    {
        position = position->next;
    }
    position->next = newnode;
}
void copy(node *list1, node *list2)
{
    node *pos = list1;
    while (pos->next != NULL)
    {
        pos = pos->next;
        insert(list2, pos->element);
    }
}
void traverse(node *list)
{
    node *position = list;
    while (position->next != NULL)
    {
        position = position->next;
        printf("%d\n", position->element);
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    node *list1 = malloc(sizeof(node));
    list1->next = NULL;
    node *list2 = malloc(sizeof(node));
    list2->next = NULL;
    while (t--)
    {
        int x;
        scanf("%d", &x);
        insert(list1, x);
    }
    copy(list1, list2);
    traverse(list2);
    return 0;
}