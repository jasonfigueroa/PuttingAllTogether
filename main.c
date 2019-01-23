#include <stdio.h>
#include "vec.h"

void addData(vec_str_t *v) {
    char tempString[256] = "id,first_name,last_name,email,gender,ip_address";

    //headers
    char *strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, "id,first_name,last_name,email,gender,ip_address");
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    //row 1
    strcpy(tempString, "1,Yale,Semor,ysemor0@bloglovin.com,Male,164.82.195.33");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    //row 2
    strcpy(tempString, "2,Augy,Gwynn,agwynn1@narod.ru,Male,137.35.78.151");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    //row 3
    strcpy(tempString, "3,Deeann,Ferfulle,dferfulle2@slate.com,Female,98.124.73.211");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "4,Levy,Anglim,langlim3@un.org,Male,232.32.78.203");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "5,Leela,Fehners,lfehners4@topsy.com,Female,226.131.38.222");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "6,Olympie,Mugglestone,omugglestone5@symantec.com,Female,76.180.173.96");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "7,Iolanthe,Asals,iasals6@illinois.edu,Female,123.103.148.254");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "8,Kippy,Wiltshaw,kwiltshaw7@godaddy.com,Male,81.132.97.11");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "9,Hedwiga,Di Ruggero,hdiruggero8@barnesandnoble.com,Female,203.254.241.49");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;

    strcpy(tempString, "10,Kristofer,Bruckenthal,kbruckenthal9@seesaa.net,Male,35.174.160.109");
    strPtr = (char*)malloc(strlen(tempString) * sizeof(char));
    strcpy(strPtr, tempString);
    vec_push(&(*v), strPtr);
    strPtr = NULL;
}

int main() {
    vec_str_t v;
    int i;

    vec_init(&v);

    addData(&v);

    for (i = 0; i < v.length; i++) {
        printf("row %d: %s\n", i, v.data[i]);
    }

    vec_deinit(&v);
    return 0;
}