#include <stdio.h>

#include "state_flow.h"

enum{
    init, 
    STATE_A, //00
    STATE_B, //01
    STATE_C, //10
    STATE_D  //11
};

void Init(void* me, void* data1, void* data2){
     StateFlow* this = (StateFlow*) me;
     printf("Init\n");
     this->now_state = STATE_A;
     printf("Next state A\n");
}

void State_A(void* me, void* data1, void* data2){
     StateFlow* this = (StateFlow*) me;
     printf("A\n");
     if(*(uint8_t*)data1 == 0U && *(uint8_t*)data2 == 1U){
        this->now_state = STATE_B;
        printf("Next state B\n");
        return;
     }
     if(*(uint8_t*)data1 == 1U && *(uint8_t*)data2 == 0U){
        this->now_state = STATE_C;
        printf("Next state C\n");
        return;
     }
     if(*(uint8_t*)data1 == 1U && *(uint8_t*)data2 == 1U){
        this->now_state = STATE_D;
        printf("Next state D\n");
        return;
     }
}

void State_B(void* me, void* data1, void* data2){
     StateFlow* this = (StateFlow*) me;
     printf("B\n");
     if(*(uint8_t*)data1 == 0U && *(uint8_t*)data2 == 0U){
        this->now_state = STATE_A;
        printf("Next state A\n");
        return;
     }
     if(*(uint8_t*)data1 == 1U && *(uint8_t*)data2 == 0U){
        this->now_state = STATE_C;
        printf("Next state C\n");
        return;
     }
     if(*(uint8_t*)data1 == 1U && *(uint8_t*)data2 == 1U){
        this->now_state = STATE_D;
        printf("Next state D\n");
        return;
     }
}

void State_C(void* me, void* data1, void* data2){
     StateFlow* this = (StateFlow*) me;
     printf("C\n");
     if(*(uint8_t*)data1 == 0U && *(uint8_t*)data2 == 0U){
        this->now_state = STATE_A;
        printf("Next state A\n");
        return;
     }
     if(*(uint8_t*)data1 == 0U && *(uint8_t*)data2 == 1U){
        this->now_state = STATE_B;
        printf("Next state B\n");
        return;
     }
     if(*(uint8_t*)data1 == 1U && *(uint8_t*)data2 == 1U){
        this->now_state = STATE_D;
        printf("Next state D\n");
        return;
     }
}

void State_D(void* me, void* data1, void* data2){
     StateFlow* this = (StateFlow*) me;
     printf("D\n");
     if(*(uint8_t*)data1 == 0U && *(uint8_t*)data2 == 0U){
        this->now_state = STATE_A;
        printf("Next state A\n");
        return;
     }
     if(*(uint8_t*)data1 == 0U && *(uint8_t*)data2 == 1U){
        this->now_state = STATE_B;
        printf("Next state B\n");
        return;
     }
     if(*(uint8_t*)data1 == 1U && *(uint8_t*)data2 == 0U){
        this->now_state = STATE_C;
        printf("Next state C\n");
        return;
     }
}


int main(int argc, char** argv){
    StateFlow sf;
    StateFunc func[5] = {Init, State_A, State_B, State_C, State_D};
    // printf("%d", sizeof(StateFunc));
    RegisterStateFlow(&sf, func, 5);
    sf.run((void*)(&sf), NULL, NULL);
    int data1, data2;
    for(;;){
        printf("input data1 and data2\n");
        scanf("%d,%d", &data1, &data2);
        sf.run((void*)(&sf), (void*)&data1, (void*)&data2);
        printf("---------------------------------\n");
    }
    
}
