/*

Read size of a stack No and insert n elements into the stack. print stack print the top element of the stack

*/

#include <stdio.h>

int max=30;
int stack[10];
int top=-1;

void push(int x){
    stack[++top]=x;
}

void pop(){
    printf("%d ", stack[top--]);
}

int main(){
    int n,x;
    int p;
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        scanf("%d", &x);
        push(x);
    }
    
    scanf("%d", &p);
    push(p);
    while(top!=-1){
        pop();
    } printf("\n%d", p);
}