/*

Given an arithmetic expression, find the operator with highest priority using stack.

 (consider only basic arithmetic operators)

*/

#include <stdio.h>
#include <string.h>
#define max 50
char stack[max];
int top = -1;
int priority(char ch)
{
    int x;
    switch (ch)
    {
    case '+':
    case '-':
        x = 1;
        break;
    case '*':
    case '/':
        x = 2;
        break;
    }
    return x;
}
void push(char ch)
{
    top++;
    stack[top] = ch;
}
void pop()
{
    printf("%c", stack[top]);
    top--;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char st[max];
    scanf("%[^\n]%*c", st);
    for (int i = 0; i < strlen(st); i++)
    {
        if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/')
        {
            if (isEmpty())
            {
                push(st[i]);
            }
            else if (priority(st[i]) > priority(stack[top]))
            {
                push(st[i]);
            }
            else if (priority(st[i]) <= priority(stack[top]))
            {
                pop();
                break;
            }
        }
    }
    return 0;
}