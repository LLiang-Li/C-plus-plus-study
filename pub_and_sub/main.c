#include <stdio.h>
#include <string.h>
#include "pub_sub.h"

typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char u;
    unsigned char v;
    unsigned char w;
}PubSubData;

void display(Suber* sub_ptr, void * data_ptr){
    PubSubData* data = ((PubSubData*)data_ptr);
    // printf("%f,\n", data);
    printf("--%s, %s-\n", sub_ptr->name, sub_ptr->topic);
    char* str = "quxiao";
    memcpy(sub_ptr->topic, str, strlen(str));
    printf("x = %d\n", data->x);
    printf("y = %d\n", data->y);
    printf("z = %d\n", data->z);
    printf("u = %d\n", data->u);
    printf("v = %d\n", data->v);
    printf("w = %d\n", data->w);
}

int main(int argc, char** argv){
    PubSubData data = {.x = 1, .y = 2, .z = 3, .u = 4, .v = 5, .w = 6};
    Suber sub1;
    Suber sub2;
    Suber sub3;
    Suber sub4;
    Suber sub5;
    Suber sub6;
    Suber sub7;
    Suber sub8;
    Suber sub9;
    Suber sub10;
    // ConstructSub("sub12345789", "my", &sub1, display);
    CREATE_SUB(sub1,"my",display);
    ConstructSub("sub2", "lige", &sub2, display);
    ConstructSub("sub3", "my", &sub3, display);
    ConstructSub("sub4", "ge", &sub4, display);
    ConstructSub("sub5", "my", &sub5, display);
    ConstructSub("sub6", "my", &sub6, display);
    ConstructSub("sub7", "li", &sub7, display);
    ConstructSub("sub8", "my", &sub8, display);
    ConstructSub("sub9", "li", &sub9, display);
    ConstructSub("sub10", "my", &sub10, display);

    Puber pub1;
    ConstructPub("pub1", &pub1);
    SUB_CONNECT_PUB(pub1, sub1);
    SUB_CONNECT_PUB(pub1, sub2);
    SUB_CONNECT_PUB(pub1, sub3);
    SUB_CONNECT_PUB(pub1, sub4);
    SUB_CONNECT_PUB(pub1, sub5);
    SUB_CONNECT_PUB(pub1, sub6);
    SUB_CONNECT_PUB(pub1, sub7);
    SUB_CONNECT_PUB(pub1, sub8);
    SUB_CONNECT_PUB(pub1, sub9);
    SUB_CONNECT_PUB(pub1, sub10);
    // pub1.register_suber(&pub1, &sub1);
    // pub1.register_suber(&pub1, &sub2);
    // pub1.register_suber(&pub1, &sub3);
    // pub1.register_suber(&pub1, &sub4);
    // pub1.register_suber(&pub1, &sub5);
    // pub1.register_suber(&pub1, &sub6);
    // pub1.register_suber(&pub1, &sub7);
    // pub1.register_suber(&pub1, &sub8);
    // pub1.register_suber(&pub1, &sub9);
    // pub1.register_suber(&pub1, &sub10);

    printf("**********************************************\n");
    for(unsigned int i = 0; i < pub1.suber_num; i++){
        printf("%s,", pub1.subers[i]->name);
    }
    printf("\n");
    printf("**********************************************\n");
    // double data = 10.0;

    pub1.public_data(&pub1, argv[1], &data);
    printf("%d\n", pub1.suber_num);
    pub1.delete_suber(&pub1, &sub8);
    pub1.delete_suber(&pub1, &sub9);

    printf("**********************************************\n");
    for(unsigned int i = 0; i < pub1.suber_num; i++){
        printf("%s,", pub1.subers[i]->name);
    }
    printf("\n");
    printf("**********************************************\n");
    printf("---------------------------------------------\n");
    pub1.public_data(&pub1, argv[1], &data);
    printf("---------------------------------------------\n");
    printf("%d\n", pub1.suber_num);
    printf("%x; %x; %x; %x", &sub1, &sub2, &sub3, &sub4);

    printf("\n");
    unsigned int test[8] = {0,1,2,3,4,5,6,7};
    for(unsigned int i = 0; i < 8; i++){
        printf("%d,",test[i]);
    }
    printf("\n");
    memcpy(&test[0], &test[1], 7);
    for(unsigned int i = 0; i < 8; i++){
        printf("%d,",test[i]);
    }

    return 0;
}
