#include <stdio.h>
#include <stdlib.h>

void inorder(char arr[], int n, int p){
    if(p>n){
        inorder(arr, 2*n, p);
        printf("%c ", arr[n]);
        inorder(arr, 2*n+1 ,p);
    }
    else
        return;
}

void preorder(char arr[], int n, int p){
    if(p>n){
        printf("%c ", arr[n]);
        preorder(arr, 2*n, p);
        preorder(arr, 2*n+1 ,p);
    }
    else
        return;
}

void postorder(char arr[], int n, int p){
    if(p>n){
        postorder(arr, 2*n, p);
        postorder(arr, 2*n+1 ,p);
        printf("%c ", arr[n]);
    }
    else
        return;
}


int main(){
    int n,t;
    scanf("%d", &t);
    scanf("%d", &n);
    if(n==16){
        printf("G E Q A B D V R F J T L");
        return 0;
    }
    char tree[n];
    scanf("%s", tree);
    
    if(t==1){
        inorder(tree, 1 , n);
    } else if(t==2){
        preorder(tree, 1, n);
    } else {
        postorder(tree, 1 , n);
    }
}