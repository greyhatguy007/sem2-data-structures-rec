/*

read size of the stack

pop the last element of a stack and display the stack as well as print the index of top element

after pop if stack is empty display as "underflow"

*/

#include <stdio.h>
#define max 100
int stack[max];
int top = -1;
void push(int x)
{
    top++;
    stack[top] = x;
}
void peekindex()
{
    printf("%d\n", top);
}
void pop()
{
    top--;
    if (top == -1)
    {
        printf("underflow\n");
    }
}
void traverse()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int t;
        scanf("%d", &t);
        push(t);
    }
    pop();
    if (top != -1)
    {
        traverse();
    }
    peekindex();
    return 0;
}