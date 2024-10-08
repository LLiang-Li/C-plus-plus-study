#ifndef _PUB_AND_SUB_
#define _PUB_AND_SUB_

#define _platform_x86_

#define MAX_SUBER_NUM 10

#define NAME_LEN 10

#define TOPIC_LEN 20

#define SUB_CONNECT_PUB(PUB_VAR, SUB_VAR)     PUB_VAR.register_suber(&PUB_VAR, &SUB_VAR)

#define CREATE_SUB(SUB, TOPIC, CALLBACK)    ConstructSub(#SUB, TOPIC, &SUB, CALLBACK)

typedef struct SUBER Suber;

typedef struct SUBER{
    void (*update)(Suber*, void *);
    char name[NAME_LEN];
    char topic[TOPIC_LEN];
}Suber;

typedef struct PUBER Puber;

typedef struct PUBER{
    char topic[TOPIC_LEN];
    char name[NAME_LEN];
    void* data_ptr;
    Suber* subers[MAX_SUBER_NUM];
    unsigned int suber_num;
    unsigned char(*register_suber)(Puber*, Suber*);
    unsigned char(*delete_suber)(Puber*, Suber*);
    // void(*notify_subers)(Puber*);
    void(*public_data)(Puber*, char*, void *);
}Puber;

void ConstructSub(char* , char*, Suber *, void (*update)(Suber* , void *));

void ConstructPub(char* , Puber*);

#endif