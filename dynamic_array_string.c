#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINE 80
#define M_CHAR 40

struct vector{
    char *buff[M_CHAR];
    int size;
    int count;
    int pos;
};

struct vector* init(int size);
void add(struct vector* nv,char *string);
void print(struct vector* nv);
void delete(struct vector* nv);



int main(){
    struct vector* v=init(6);
    add(v,"HZ");
    add(v,"Suleyman");
    add(v,"Will");
    add(v,"KIll");
    add(v,"US");
    print(v);
    delete(v);
    delete(v);
    print(v);
    add(v,"check-c-files");
    print(v);
    return 0;
}

struct vector* init(int size){
    struct vector* nv = malloc(sizeof(struct vector));
    nv->buff[M_CHAR] = malloc(sizeof(char*) *size);
    for(int i =0 ; i< size;i++){
        nv->buff[i] = malloc(M_CHAR*sizeof(char));
    }
    nv->size = size;
    nv->count = 0;
    nv->pos = -1;
}

void add(struct vector* nv,char *string){
    if(nv->pos >= nv->size-1) return;
    //nv->pos = nv->pos + 1;
    strcpy(nv->buff[++nv->pos],string);
}

void delete(struct vector* nv){
    if(nv->pos < 0) return;
    nv->pos--;
}


void print(struct vector* nv){
    if(nv->pos < 0) return ;
    int i =0 ;
    for (;i <=nv->pos;i++){
        printf("%s\t",nv->buff[i]);
    }
    printf("\n");
}








