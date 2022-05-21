/*

The printer Queue uses the queue concept to store the list of files they get to print in the printer. Write a program to print the  first file in the printer Queue. If the number of print files is more than the print queue size, it should say “overflow” otherwise print the name of the first file.

Input: 

Queue size n , no of inputs m and input file names

Output: 

names of the first file in the queue to be printed or overflow

*/

#include <stdio.h>
#include <string.h>
int main(){
    int m,n;
    char a[10];
    scanf("%d", &m);
    scanf("%d", &n);
    if(n>m){
        printf("Overflow");
    } else {
        scanf("%s", a);
        printf("%s", a);
    }
}