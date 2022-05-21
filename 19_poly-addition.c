/*

Find the sum of two polynomial numbers. Represent the polynomial using single linked list.

Input Format :

First line contains the Degree of the 1st polynomial

Second line contains the Coefficient of 1st polynomial

Third line contains the degree of the 2nd polynomial

Fourth line contains the Coefficient of 2nd polynomial

Sample Input :

3

5 2 0 1

2

4 3 1

Sample Output:

5x^3 + 6x^2 + 3x^1 + 2

Explanation:

5x^3 + 2x^2 + 1   +   4x^2 + 3x^1 + 1 =  5x^3 + 6x^2 + 3x^1 + 2

*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    struct node *next;
    int pow;
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
void sum(node *poly1, node *poly2, node *result)
{
    node *pos1 = poly1->next;
    node *pos2 = poly2->next;
    while (pos1 != NULL && pos2 != NULL)
    {
        if (pos1->pow == pos2->pow)
        {
            int x;
            x = pos1->coeff + pos2->coeff;
            insert(result, x, pos1->pow);
            pos1 = pos1->next;
            pos2 = pos2->next;
        }
        else if (pos1->pow > pos2->pow)
        {
            insert(result, pos1->coeff, pos1->pow);
            pos1 = pos1->next;
        }
        else if (pos1->pow < pos2->pow)
        {
            insert(result, pos2->coeff, pos2->pow);
            pos2 = pos2->next;
        }
    }
}
void traverse(node *poly)
{
    node *pos = poly;
    while (pos->next->next != NULL)
    {
        pos = pos->next;
        printf("%dx^%d", pos->coeff, pos->pow);
        if (pos->next->coeff >= 0)
            printf("+");
    }
    printf("%d", pos->next->coeff);
}
int main()
{
    node *poly1 = malloc(sizeof(node));
    node *poly2 = malloc(sizeof(node));
    node *result = malloc(sizeof(node));
    poly1->next = NULL;
    poly2->next = NULL;
    result->next = NULL;
    int n1, n;
    scanf("%d", &n1);
    n = n1;
    for (int i = 0; i < n1 + 1; i++)
    {
        int j;
        scanf("%d", &j);
        insert(poly1, j, n);
        n--;
    }
    int n2;
    scanf("%d", &n2);
    n = n2;
    for (int i = 0; i < n2 + 1; i++)
    {
        int j;
        scanf("%d", &j);
        insert(poly2, j, n);
        n--;
    }
    sum(poly1, poly2, result);
    traverse(result);
    return 0;
}