#include<stdlib.h>
#include"struct.h"


User *memory(const int number) {
    User *user;
    user = (User *) malloc(number * sizeof(User));
    return user;
}

void freeUser(User *users) {
    users->hashLogin = 0;
    users->hashPassword = 0;
    free(users);
}