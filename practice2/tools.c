#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "tools.h"
#include "struct.h"
#include <string.h>
#include"hashFunction.h"

void getString(char **string) {
    int size = 0;
    int realSize = 8;
    *string = (char *) malloc(realSize * sizeof(char));
    rewind(stdin);
    char check;
    while (true) {
        check = (char) getchar();
        if (check == '\n') {
            if (size + 1 < realSize) {
                *string = (char *) realloc(*string, (size + 1) * sizeof(char));
            }
            (*string)[size] = '\0';
            return;
        }

        (*string)[size] = check;
        size++;
        if (size + 1 == realSize) {
            realSize *= 2;
            *string = (char *) realloc(*string, realSize * sizeof(char));
        }
    }
}

void addUser(User **users, const User user, int *size, int *capacity) {

    if (*size + 1 == *capacity) {
        *capacity *= 2;
        *users = (User *) realloc(*users, (*capacity) * sizeof(User));
    }
    (*users)[*size] = user;
    (*size)++;

}

void fillUser(User *users) {
    User user;
    char *tempArray = NULL;
    printf("input login > 6 symbols\n");
    getString(&tempArray);
    if (strlen(tempArray) < 6) {
        printf("out of memory\n");
        free(tempArray);
        return;
    } else {
        user.hashLogin = hash(tempArray, (int) strlen(tempArray));
        free(tempArray);
    }
    printf("input password > 6 symbols\n");
    getString(&tempArray);
    if (strlen(tempArray) < 6) {
        printf("out of memory\n");
        free(tempArray);
        return;
    } else {
        user.hashPassword = hash(tempArray, (int) strlen(tempArray));
        free(tempArray);
    }
    *users = user;
}


void authorization(User *users) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("error open file\n");
        return;
    }
    char *buffer = NULL;
    size_t len = 0;
    int found = 0;
    while (getline(&buffer, &len, file) != -1) {
        int loginHash = -1, passwordHash = -1;
        if (sscanf(buffer, "%d %d", &loginHash, &passwordHash) != 2 || loginHash < 0 || passwordHash < 0) {
            printf("Invalid data format in file\n");
            return;
        }
        found = 0;
        if (users->hashLogin == loginHash) {
            printf("User is already authorized\n");
            found = 1;
            break;
        }

    }

    if (!found) {
        printf("User is not authorized\n");
        return;
    }

    fclose(file);
}


void hashData(User **users, const int size) {
    FILE *file = fopen("data.txt", "a");
    if (file == NULL) {
        printf("error open file\n");
        fclose(file);
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %d\n", (*users)[i].hashLogin, (*users)[i].hashPassword);

    }
    fclose(file);
}

unsigned int hashSum(User *users, int num, int size) {
    if (num == 0 || size == 0) {
        return 0;
    }
    return (users[num - 1].hashLogin + users[num - 1].hashPassword);
}

