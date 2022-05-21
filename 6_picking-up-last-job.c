/*

Computer handles multiuser, multiprogramming environment and time-sharing environment. In this environment a system (computer) handles several jobs at a time; to handle these jobs the concept of a queue is used. Write a program to pick up the last job in the queue of a multi-tasking environment.

Input: queue size n and list of jobs

Output: name of the last job

*/

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char a[10];
    for(int i=0;i<n;i++)
        scanf("%s", a);
    printf("%s",a);
}