#include "pub_sub.h"
#include <string.h>

#ifdef _platform_x86_
#include <stdio.h>
#endif

void ConstructSub(char* name, char* topic, Suber *suber, void (*update)(Suber*, void*)){
    // static Suber suber;
    memset(suber->name, 0, NAME_LEN);
    memset(suber->topic, 0, TOPIC_LEN);
    memcpy(suber->name, name, strlen(name) < NAME_LEN ? strlen(name) : NAME_LEN - 1);
    memcpy(suber->topic, topic, strlen(topic) < TOPIC_LEN ? strlen(topic) : TOPIC_LEN - 1);
    suber->update = update;
#ifdef _platform_x86_
    printf("create a suber: %s;", suber->name);
    printf("topic: %s\n", suber->topic);
#endif
    // return suber;
}

static unsigned char RegisterSuber(Puber* this,Suber* suber){
    if(this == NULL || suber == NULL)
        return 3;
    if(this->suber_num < MAX_SUBER_NUM){
        for(unsigned int i = 0; i < this->suber_num; i++){
            if(this->subers[i] == suber){
#ifdef _platform_x86_
                printf("Suber [%s] is exist!\n", suber->name);
#endif
                return 2;
            }
        }
        this->subers[this->suber_num++] = suber;
#ifdef _platform_x86_
    printf("pub [%s] register sub [%s] success!\n", this->name, suber->name);
#endif
        return 0;
    }
    return 1;
}

static unsigned char DeleteSuber(Puber* this, Suber* suber){
    //Suber is null
    if(this->suber_num ==0){
#ifdef _platform_x86_
    printf("Pub [%s] is null\n", this->name);
#endif
        return -1;
    }
    for(unsigned int i=0; i < this->suber_num; i++){
        if(this->subers[i] == suber){
            memcpy(&this->subers[i], &this->subers[i+1], (this->suber_num - i - 1)*sizeof(Suber*));
            // for(unsigned int j = i; j < this->suber_num - 1; j++){
            //     this->subers[j] = this->subers[j + 1];
            // }
            this->suber_num--;
            //found
#ifdef _platform_x86_
            printf("pub [%s] is deleted in sub [%s]\n", this->name, suber->name);
#endif
            return 0;
        }
    }
    //Not found
#ifdef _platform_x86_
    printf("pub [%s] is not found in sub [%s]\n", this->name, suber->name);
#endif
    return 1;
}

static void NotifySubers(Puber* this, char* topic){
    if(topic == NULL)
        return;
    for(unsigned int i = 0; i < this->suber_num; i++){
        if (!strcmp(this->subers[i]->topic, topic))
            this->subers[i]->update(this->subers[i], this->data_ptr);
    }
}

static void PublicData(Puber* this, char* topic, void* data_ptr){
    // memcpy(&this->data, data, sizeof(PubSubData));
    this->data_ptr = data_ptr;
    NotifySubers(this, topic);
}

void ConstructPub(char* name, Puber* puber){
    // static Puber puber = {.subers = {NULL}};
    Suber set_numm[MAX_SUBER_NUM] = {NULL};
    memset(&puber->name, 0, NAME_LEN);
    memcpy(&puber->subers[0], set_numm, MAX_SUBER_NUM);
    memcpy(&puber->name, name, strlen(name) < NAME_LEN ? strlen(name) : NAME_LEN - 1);
    puber->suber_num = 0;
    puber->delete_suber = DeleteSuber;
    // puber.notify_subers = NotifySubers;
    puber->register_suber = RegisterSuber;
    puber->public_data = PublicData;
#ifdef _platform_x86_
    printf("create a puber: %s\n", puber->name);
#endif
    // return puber;
}