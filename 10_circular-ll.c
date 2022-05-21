/*

Write a Program to implement Circular Linked List which performs the following operations based on the users input.

1 -> Insertion

2 -> Deletion

3 -> Display

4 -> Find the Number of Elements 
5 -> EXIT

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
    newnode->next = list;
    node *pos = list;
    while (pos->next != list)
    {
        pos = pos->next;
    }
    pos->next = newnode;
}
void delete (node *list, int x)
{
    node *pos = list;
    while (pos->next != list && pos->next->element != x)
    {
        pos = pos->next;
    }
    node *tempnode = pos->next;
    pos->next = tempnode->next;
    free(tempnode);
}
void findnoofelements(node *list)
{
    node *pos = list;
    int c = 0;
    while (pos->next != list)
    {
        pos = pos->next;
        c++;
    }
    printf("%d\n", c);
}
void traverse(node *list)
{
    node *pos = list;
    while (pos->next != list)
    {
        pos = pos->next;
        printf("%d ", pos->element);
    }
    printf("\n");
}
int main()
{
    int ch;
    node *list = malloc(sizeof(node));
    list->next = list;
    int x;
    do
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &x);
            insert(list, x);
            break;
        case 2:
            scanf("%d", &x);
            delete (list, x);
            break;
        case 3:
            traverse(list);
            break;
        case 4:
            findnoofelements(list);
            break;
        default:
            break;
        }
    } while (ch < 5);
    return 0;
}