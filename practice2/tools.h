#ifndef PRACTICE_TOOLS_H
#define PRACTICE_TOOLS_H

#include "struct.h"

void getString(char **string);

void addUser(User **users, User user, int *size, int *capacity);

void hashData(User **users, int size);

void authorization(User *users);

unsigned int hashSum(User *users, int num,int size);
void ask(char *symbol);
void inputNumberWithBoundsForMenu(int *number, int leftBound, int rightBound);

void inputNumberWithBounds(int *number, int leftBound, int rightBound);

void fillUser(User *users);

#endif
