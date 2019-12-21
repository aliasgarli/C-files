#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char *data;
    struct node* next;
};

struct node* create(void){
    struct node* nn = (struct node*) malloc(sizeof(struct node));
    nn->next = NULL;
    return nn;
}
struct node* init(char *data){
    struct node* nn = (struct node*) malloc(sizeof(struct node));
    nn->data = (char*) malloc(sizeof(data));
    strcpy(nn->data,data); 
    nn->next = NULL;
    return nn;
}

void push(struct node** head,char *data){
    struct node* temp =*head;
    struct node* nn =init(data);
    if(*head == NULL){
        *head=nn;
        return;
    }
    nn->next=*head;
    *head = nn;
}

void append(struct node** head,char *data){
    struct node* nn = init(data);
    struct node* temp =*head;
    if(*head == NULL) {
        *head = nn;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nn;
}

void del_pos(struct node** head,int pos){
    struct node* temp = *head;
    struct node* prev = NULL;

    if(*head == NULL) return ;
    int n = 0;
    for(;n<pos;n++){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;    
    //free(prev);
}

void del_data(struct node** head,char *data){
    struct node* temp = *head;
    struct node* prev = NULL;

    if(*head == NULL) return;

    while(strcmp(temp->data,data) != 0){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    //free(prev);
}

void traverse(struct node* head){
    struct node* temp = head;
    if (temp == NULL) return ;

    while(temp != NULL){
        printf("%s\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}



int main(void){
    struct node* head = init("First");
    

    push(&head,"Ali");
    push(&head,"Bilal");
    traverse(head);
    append(&head,"Yusif");

    del_pos(&head,2);
    traverse(head);
    append(&head,"Asgarli");
    append(&head,"Tahir");
    traverse(head);
    del_data(&head,"Asgarli");
    traverse(head);

}







