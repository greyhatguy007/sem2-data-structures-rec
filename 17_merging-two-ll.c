/*

Write a C Program to Merge two Singly Linked List and Display the elements of Merged List.

Input:

Number of Elements in List1 - m

m Elements in List1

Number of Elements in List2 - n

n Elements in List2

Output:

m+n Elements from List1 and List2

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
void merge(node *list1, node *list2)
{
    node *position = list1;
    while (position->next != NULL)
    {
        position = position->next;
    }
    position->next = list2->next;
    free(list2);
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
    int x, y;
    scanf("%d", &x);
    node *list1 = malloc(sizeof(node));
    list1->next = NULL;
    node *list2 = malloc(sizeof(node));
    list2->next = NULL;
    while (x--)
    {
        int t;
        scanf("%d", &t);
        insert(list1, t);
    }
    scanf("%d", &y);
    while (y--)
    {
        int t;
        scanf("%d", &t);
        insert(list2, t);
    }
    merge(list1, list2);
    traverse(list1);
    return 0;
}