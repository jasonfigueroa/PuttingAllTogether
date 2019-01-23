//TODO add csv parsing
//TODO add database functionality

#include <stdio.h>
#include "vec.h"

void addData(vec_str_t *v) {
    int totalRecords = 10;
    int i;
    char content[11][256] = {
            {"id,first_name,last_name,email,gender,ip_address"},
            {"1,Yale,Semor,ysemor0@bloglovin.com,Male,164.82.195.33"},
            {"2,Augy,Gwynn,agwynn1@narod.ru,Male,137.35.78.151"},
            {"3,Deeann,Ferfulle,dferfulle2@slate.com,Female,98.124.73.211"},
            {"4,Levy,Anglim,langlim3@un.org,Male,232.32.78.203"},
            {"5,Leela,Fehners,lfehners4@topsy.com,Female,226.131.38.222"},
            {"6,Olympie,Mugglestone,omugglestone5@symantec.com,Female,76.180.173.96"},
            {"7,Iolanthe,Asals,iasals6@illinois.edu,Female,123.103.148.254"},
            {"8,Kippy,Wiltshaw,kwiltshaw7@godaddy.com,Male,81.132.97.11"},
            {"9,Hedwiga,Di Ruggero,hdiruggero8@barnesandnoble.com,Female,203.254.241.49"},
            {"10,Kristofer,Bruckenthal,kbruckenthal9@seesaa.net,Male,35.174.160.109"}
    };
    char tempString[256];
    char *newStrPtr;

    //initializing i to 1 to skip headers
    for(i = 1; i < totalRecords + 1; i++) {
        strcpy(tempString, content[i]);
        char *newStrPtr = (char*)malloc(strlen(tempString) * sizeof(char));
        strcpy(newStrPtr, tempString);
        vec_push(&(*v), newStrPtr);
    }
}

typedef struct {
    char *id;
    char *firstName;
    char *lastName;
    char *email;
    char *gender;
    char *ipAddress;
} record;

typedef vec_t(record*) vec_record_t;

void buildRecords(vec_str_t *str_vec, vec_record_t *record_vec) {
    int totalRecords = str_vec->length;
    int i;
    record *rec;
    char *token;
    char *tempStr;

    for (i = 0; i < totalRecords; i++) {
        rec = (record*)malloc(sizeof(record));

        /* get the first token */
        token = strtok(str_vec->data[i], ",");

        tempStr = (char*)malloc(strlen(token) * sizeof(char));
        strcpy(tempStr, token);

        if (token != NULL) {

            rec->id = tempStr;
            token = strtok(NULL, ",");

            tempStr = (char*)malloc(strlen(token) * sizeof(char));
            strcpy(tempStr, token);

            rec->firstName = token;
            token = strtok(NULL, ",");

            tempStr = (char*)malloc(strlen(token) * sizeof(char));
            strcpy(tempStr, token);

            rec->lastName = token;
            token = strtok(NULL, ",");

            tempStr = (char*)malloc(strlen(token) * sizeof(char));
            strcpy(tempStr, token);

            rec->email = token;
            token = strtok(NULL, ",");

            tempStr = (char*)malloc(strlen(token) * sizeof(char));
            strcpy(tempStr, token);

            rec->gender = token;
            token = strtok(NULL, ",");

            tempStr = (char*)malloc(strlen(token) * sizeof(char));
            strcpy(tempStr, token);

            rec->ipAddress = token;
        }

        vec_push(&(*record_vec), rec);
    }
}

void printRecords(vec_record_t *record_vec) {
    int i;
    for (i = 0; i < record_vec->length; i++) {
        printf("Record %d\n", i + 1);
        printf("--------------------------\n");
        printf("id: %s\n", record_vec->data[i]->id);
        printf("first name: %s\n", record_vec->data[i]->firstName);
        printf("last name: %s\n", record_vec->data[i]->lastName);
        printf("email: %s\n", record_vec->data[i]->email);
        printf("gender: %s\n", record_vec->data[i]->gender);
        printf("ip address: %s\n", record_vec->data[i]->ipAddress);
        printf("\n\n");
    }
}

int main() {
    vec_str_t v;
    int i;

    vec_init(&v);

    addData(&v);

    //initializing record vector
    vec_record_t rec_v;
    vec_init(&rec_v);

    buildRecords(&v, &rec_v);

    printRecords(&rec_v);

//    for (i = 0; i < v.length; i++) {
//        printf("row %d: %s\n", i, v.data[i]);
//    }

    vec_deinit(&v);
    vec_deinit(&rec_v);
    return 0;
}