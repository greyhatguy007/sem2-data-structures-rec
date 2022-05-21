/*

Develop a menu driven program to insert a node in the linked list and display the same. Based on the options given in the input, the corresponding subroutine should be executed. The options are as follows-

option 1 - to insert a node in the beginning of the linked list 

option 2 - to insert a node in the end of the linked list.

Input Format

no. of nodes n

next n lines denotes the values of the nodes

option 

value of the node to insert

Sample Input

4

55

33

44

22

1

88

Sample Output

88

55

33

44

22

*/


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node node;
void insertBeg(node *list, int x)
{
    node *newnode = malloc(sizeof(node));
    newnode->element = x;
    newnode->next = list->next;
    list->next = newnode;
}
void insertLast(node *list, int x)
{
    node *newnode = malloc(sizeof(node));
    newnode->element = x;
    newnode->next = NULL;
    node *pos = list;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = newnode;
}
void traverse(node *list)
{
    node *pos = list;
    while (pos->next != NULL)
    {
        pos = pos->next;
        printf("%d\n", pos->element);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    node *list = malloc(sizeof(node));
    list->next = NULL;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        insertLast(list, x);
    };
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {
        int t;
        scanf("%d", &t);
        insertBeg(list, t);
    }
    else
    {
        int t;
        scanf("%d", &t);
        insertLast(list, t);
    }
    traverse(list);
    return 0;
}