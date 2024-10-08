#include "state_flow.h"

static uint8_t StateRun(void* me, void* data0, void* data1){
    StateFlow* this = (StateFlow*) me;
    if (this->now_state < this->state_counter)
        this->array_funcs[this->now_state](me, data0, data1);
    else
        return 1;
    return 0;
}

uint8_t RegisterStateFlow(StateFlow* sf, StateFunc* funcs, uint8_t counter){
    if(counter < 1U)
        return 1;
    sf->state_counter = counter < States_NUM ? counter : States_NUM;
    sf->now_state = 0;
    sf->run = StateRun;
    memcpy(sf->array_funcs, funcs, sf->state_counter*sizeof(StateFunc));
    return 0;
}