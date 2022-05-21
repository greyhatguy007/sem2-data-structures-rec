/*

In a goods train, all the wagons attached to the train have a sheet of paper pasted that tells how much is the total weight of the goods in each wagon. The first wagon is attached to the engine, the second wagon is attached to the first wagon and so on and the last one is guard van. Given the weights of goods in the wagon  as input, print the weights in the reverse order.

Example

If the weights of the wagons starting from wagon 1 are as follows-   100->200->300->NULL then print the weights in the following order  300->200->100->NULL

Input Format

The first line contains an integer n, the number of elements in the linked list.
Each of the next n, lines contains an integer, the data values of the elements in the linked list.

Constraints

    1 <=n <= 1000

    1 <= list[i] <= 1000, where list[i] is the ith element in the list.

Sample Input

5
1
2
3
4
5

Sample Output

5 4 3 2 1 

Explanation

The initial linked list is: 1->2->3->4->5

The reversed linked list is: 5->4->3->2->1

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
    newnode->next = list->next;
    list->next = newnode;
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
        insert(list, x);
    };
    traverse(list);
    return 0;
}