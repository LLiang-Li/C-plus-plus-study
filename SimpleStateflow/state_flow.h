#ifndef _STATE_FLOW_
#define _STATE_FLOW_
#include<stdint.h>
#include<string.h>

typedef void(*StateFunc)(void* ,void*, void*);

#define States_NUM 10

typedef struct SF
{
    uint8_t now_state;
    uint8_t state_counter;
    StateFunc array_funcs[States_NUM];
    uint8_t (*run)(void*, void*, void*);
} StateFlow;

uint8_t RegisterStateFlow(StateFlow* sf, StateFunc* funcs, uint8_t counter);

#endif