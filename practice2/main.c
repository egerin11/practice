#include "struct.h"
#include "init.h"
#include "tools.h"
#include <stdio.h>
#include"allForMenu.h"

#define EXIT 'n'
#define ADD_USER 1
#define HASH 2

int main() {
    int size = 0;
    int capacity = 8;
    char symbol;

    User *users = memory(capacity);
    User user;
    int choice = 0;
    do {
        showMenu();
        inputNumberWithBoundsForMenu(&choice, 0, 2);
        switch (choice) {
            case ADD_USER: {
                fillUser(&user);
                addUser(&users, user, &size, &capacity);
                authorization(&user);
                hashData(&users, size);
                getchar();
            }
                break;
            case HASH: {
                int num = -1;
                inputNumberWithBounds(&num, 0, size);
                unsigned int sum = hashSum(users, num, size);
                if (sum == 0) {
                    printf("no such user\n");
                } else printf("\n%d \n", sum);
                getchar();
            }

                break;
            default: {

            }
        }
        printf("would you like to continue?[y/n]\n");
        ask(&symbol);
    } while (symbol != EXIT);

    freeUser(users);
    return 0;
}
