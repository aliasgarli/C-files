#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int size);
void sawp(int *a,int *b);
void bubble_sort(int arr[],int n);

int main(){
    int my_arr[] = {71,6,19,83,45,10};
    int size = sizeof(my_arr)/sizeof(my_arr[0]);
    printf("The initial array :\n");
    display(my_arr,size);
    bubble_sort(my_arr,size);
    display(my_arr,size);

    return 0;
}

void display(int arr[],int size){
    for(int i=0;i<size-1;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

}

void swap(int *a,int *b){
    int tm=*a;
    *a = *b;
    *b = tm;
}

void bubble_sort(int arr[],int n){
    int i,j; 
    for(i = 0;i<n-1;i++)
        for(j=0;j < n-i-1;j++)
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
    
    
}

