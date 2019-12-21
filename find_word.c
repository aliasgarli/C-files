#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define RED "\033[3;31m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int search(char* key_word,char* myText);

int main(int argc,char *argv[]){
    if(argc != 2)
        exit(1);
    char key_word[32] ;
    strcpy(key_word,argv[1]);
    printf("My key : %s\n",key_word);
    char myText[]="Hello my world!";
    int FLAG_KEY = search(key_word,myText);
    printf("%s\n",myText); 
    if(FLAG_KEY == 1){
        printf(ANSI_COLOR_YELLOW "The word :\t\"%s\" is found"ANSI_COLOR_RESET"\n",key_word);
    }
    else{
        printf(RED"The word :\t\"%s\" is NOT found"ANSI_COLOR_RESET"\n",key_word);
    }

    return 0;
}


int search(char *key_word,char *myText){
    int FLAG_KEY = 0;
    
    int kln= strlen(key_word);

    //char myText[]="Hello my world!";
    int ln = strlen(myText);
    int i =0;
    while(myText[i] != '\0'){
        if(myText[i]==key_word[0]){
            for(int k=0;k<kln && myText[i+k]!='\0';k++){
                //printf("%c\n",myText[i+k]);
                if(myText[i+k]==key_word[k]){
                    //printf("1\n");
                    FLAG_KEY = 1;
                    
                }
                else{
                    FLAG_KEY = 0;
                    //printf("0\n");
                    break;
                }
            }
            if(FLAG_KEY == 1) break;
        }
 
        i++;
    }
    return FLAG_KEY;
}


