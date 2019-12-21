#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>    
//-> isspace(char character);

int counter(char *str){
    int c = 0;
    int i = 0;
    int len = strlen(str);
    if (!isspace(str[i])){
        c++;
    }
    for(;i<len;i++){
        if(str[i] == '\t' || str[i] =='\n' || str[i] ==' ' || str[i] =='\v' || str[i] =='\f' || str[i] =='\r'){
            c++;
        }
    }
    return c;
}

int main(){
    char name[]= "Salam World, Necesen?\nHZ.Slyman Niye,\tbele edir\vaxi?";
    printf("The given text :\n%s\n",name);
    int count = counter(name);
    /*int ln=strlen(name);
     *
     *IF YOU WANT TO show the number of characters in string 
     *
     *printf("%d\n",ln);
     */
    printf("The number of words in string:\t%d\n",count);
    return 0;
}
