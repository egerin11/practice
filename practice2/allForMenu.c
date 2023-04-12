#include "allForMenu.h"
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check(int *number) {
    return scanf("%d", number) != 1 || getchar() != '\n';
}

void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void inputNumber(int *number) {
    while (check(number)) {
        printf("Enter a valid number: ");
        clearStdin();
    }

}

void inputNumberWithBoundsForMenu(int *number, const int leftBound, const int rightBound) {

    do {
        printf("Enter a number: ");
        inputNumber(number);
    } while (*number <= leftBound || *number > rightBound);

}

void inputNumberWithBounds(int *number, const int leftBound, const int rightBound) {
    do {
        printf("number user\n");
        inputNumber(number);
    } while (*number < leftBound || *number > rightBound);

}

void ask(char *symbol) {
    do {
        scanf("%c", symbol);

    } while (*symbol != 'y' && *symbol != 'n');
}

void clearScreen() {

#if defined(__linux__)
    system("clear");
#elif defined(_WIN32)
    system("cls");
#else
    for (int i = 0; i < 32; i++)
        printf("\n");
#endif
}

void showMenu() {
    clearScreen();
    printf("\t\tMENU\n");
    printf("\tADD USER 1\n");
    printf("\tHASH SUM USER 2\n");
}