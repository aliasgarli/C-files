#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b);
int partition(int arr[],int start,int end);
void quick_sort(int arr[],int start,int end);
void display(int arr[],int size);
int binary_search(int key,int arr[],int low,int high);

int main(void){
    int arr[] = {34,21,90,11,23,7,56,89,45,67};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    display(arr,arr_size);
    quick_sort(arr,0,arr_size-1);

    display(arr,arr_size);
    
    int key;
    printf("Enter an item to search : ");
    scanf("%d",&key);

    int result = binary_search(key,arr,0,arr_size-1);
    if(result >= 0){
        printf("%d is found at index %d\n",key,result);
    }
    else{
        printf("%d is not found in the array.\n",key);
    }
        
    return 0;
}

int binary_search(int key,int arr[],int low,int high){
    if (low > high) return -1;
    int mid;
    int len=sizeof(arr)/sizeof(arr[0]);
    mid = (low+high)/2;

    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        return binary_search(key,arr,low,mid-1);
    }
    else if(arr[mid] < key){
        return binary_search(key,arr,mid+1,high);
    }
}
void display(int arr[],int size){
    for(int i = 0 ; i < size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int* a, int* b){
    int temp = *a ;
    *a = *b;
    *b = temp;
}
void quick_sort(int arr[],int start,int end){
    if(start < end ){
        int pi = partition(arr,start,end);

        quick_sort(arr,start,pi-1);
        quick_sort(arr,pi+1,end);
    }
}
int partition(int arr[],int start, int end){
    int pivot = arr[end];
    int i = (start-1); //index of smaller element 

    for(int j = start; j<= end -1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }   
    }
    swap(&arr[i+1],&arr[end]);
    return (i+1);
}
