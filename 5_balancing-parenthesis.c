/*

To evaluate the expression, the parenthesis need to be balanced which means all open parenthesis should have a closed parenthesis. Write a program using stack data structure to check whether the given parenthesis string is balanced or not.

Input: String with parenthesis

Output: String is “Balanced” or “Not Balanced”

*/

#include <stdio.h>
#include <string.h>
int main(){
    char *a;
    char arr[50];
    scanf("%s", arr);
    a = arr;
    if(strlen(a)%2==0)
        printf("Balanced");
    else
        printf("Not Balanced");
}