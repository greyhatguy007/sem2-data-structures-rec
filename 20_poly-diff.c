/*

Find the differentiation of the polynomial equation using Singly Linked List.

Input Format :

First line contains the highest degree of the polynomial

Second line contains the Coefficient of polynomial

Sample Input :

5

3 0 -2 0 1 5

Sample Output:

15x^4 - 6x^2 + 1x^0

Explanation:

Differentiation (3x^5 + 0x^4 - 2x^3 + 0x^2 + 1x^1 + 5x^0) = 15x^4 - 6x^2 + 1x^0

*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
typedef struct node node;
void insert(node *poly, int c, int x)
{
    node *newnode = malloc(sizeof(node));
    newnode->coeff = c;
    newnode->pow = x;
    newnode->next = NULL;
    node *pos = poly;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = newnode;
}
void diff(node *poly, node *result)
{
    node *pos1 = poly;
    node *pos2 = result;
    while (pos1->next != NULL)
    {
        pos1 = pos1->next;
        insert(result, pos1->coeff * pos1->pow, pos2->pow = pos1->pow - 1);
    }
}
int main()
{
    node *poly = malloc(sizeof(node));
    node *result = malloc(sizeof(node));
    poly->next = NULL;
    result->next = NULL;
    int n, x;
    scanf("%d", &n);
    int f = n + 1;
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &x);
        if (x != 0)
        {
            insert(poly, x, n);
        }
        n--;
    }
    diff(poly, result);
    node *pos = result;
    while (pos->next->next != NULL)
    {
        pos = pos->next;
        printf("%dx^%d", pos->coeff, pos->pow);
        if (pos->next->coeff > 0)
        {
            printf(" + ");
        }
    }

    return 0;
}