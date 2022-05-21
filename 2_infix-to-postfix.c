/*

Give an input Infix Expression, write the program to convert the given infix expression to postfix expression using Stack Operations.

Input : Infix Expression

Output : Postfix Expression

*/


#include<stdio.h>
#include<string.h>
#define MAX 20
int top=-1;
char s[MAX];
char stack[MAX];
void push(char c);
char pop();
int priority(char c);
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
          printf("%c",s[i]);
        else if(s[i]=='(')
          push(s[i]);
        else if(s[i]==')')
        {
            while(stack[top]!='(')
              printf("%c",pop());
            pop();
        }
        else
        {
            while(priority(s[i])<=priority(stack[top])&& top!=-1)
              printf("%c",pop());
            push(s[i]);
        }
    }
    for(int i=top;i>=0;i--)
      printf("%c",pop());
    return 0;
}
void push(char c)
{
    top=top+1;
    stack[top]=c;
}
char pop()
{
    char c;
    c=stack[top];
    top=top-1;
    return c;
}
int priority(char c)
{
    int p;
    if(c=='(')
      p=0;
    else if(c=='^')
      p=3;
    else if(c=='*'||c=='/')
      p=2;
    else if(c=='+'||c=='-'||c=='%')
      p=1;
    return p;
}