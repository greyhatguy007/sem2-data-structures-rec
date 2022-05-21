/*

A lady gardener collects roses from garden and puts them into bags. After filling bag1, she takes bag2 and fills with roses and so on. Later she counts the roses in each bag. Given the count of roses in each bag as data part of a linked list, print the total count of roses found in all bags.

Example

If the roses in each bags has the following counts-  100->115->105 the print the output as 320

Input Format

The first line contains an integer n, the number of bags.
Each of the next n, lines contains an integer, that represents the count of roses in each bag

Sample Input

3
100

115

105

Sample Output

320

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
void sum(node *list)
{
    node *pos = list;
    int sum = 0;
    while (pos->next != NULL)
    {
        pos = pos->next;
        sum += pos->element;
    }
    printf("%d\n", sum);
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
    sum(list);
    return 0;
}