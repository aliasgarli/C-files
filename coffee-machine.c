#include<stdio.h>
#include<stdlib.h>
/* This program is intented to create a finiti state machine model 
 * in c programming language using enumeration concept
 */
enum state{
    TOFF,
    TON,
    P_WATER,
    P_MILK,
    BOILS
};
// Function pointer is used to call different functions one line depending on different conditions
void (*func)();
//declarations : global variables
int change_state;
enum state current_state ;
int RUN =1;
//prototypes have been declared before main function
void turn_off();
void turn_on();
void boils();
void pour_water();
void pour_milk();
//driver code
int main(){
    change_state =0;
    current_state = TOFF;
    while(RUN){
        if(current_state == TOFF){
            printf(">>Turned off\n");
            printf("Change State :\n1.Turn on\t0.STOP program\n");
            func = turn_off;
        }
        else if(current_state == TON){
            printf(">>Turned on\n");
            printf("Change State :\n1.Turn off\t2.Boils\n");
            func = turn_on;
        }
        else if(current_state == P_WATER){
            printf(">>Pour Water\n");
            printf("Change State :\n1.Turn on\n"); 
            func = pour_water;
        }
        else if(current_state == P_MILK){
            printf(">>Pour Milk\n");
            printf("Change State :\n1.Turn on\n"); 
            func = pour_milk;
        }
        else if(current_state == BOILS){
            printf(">>Boils\n");
            printf("Change State :\n1.Turn off\t2.Pour Water\t3.Pour Milk\n");
            func = boils;
        }
        scanf("%d",&change_state);
        if(change_state==0){
            RUN = 0;
        }
        func();   
    }
    return 0;
}
//state functions
void turn_off(){ 
    if (change_state==1){
        current_state = TON;
    }
}
void turn_on(){
    if(change_state == 1){
        current_state = TOFF;
    }
    else if(change_state == 2){
        current_state = BOILS;
    }
}
void boils(){   
    if(change_state == 1){
        current_state = TOFF;
    }
    else if(change_state == 2){
        current_state = P_WATER;
    }
    else if(change_state == 3){
        current_state = P_MILK;
    }
}
void pour_water(){
    if(change_state == 1){
        current_state = TON;
    }
}
void pour_milk(){
    if(change_state == 1){
        current_state = TON;
    }
}
