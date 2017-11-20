#ifndef HW3_PHONEBOOK_H
#define HW3_PHONEBOOK_H

#include <stdio.h>

struct phoneEntry {
    char firstName[25];
    char lastName[25];
    char phone[11];
    char city[25];
    char universty[50];
};

// add to file pointer
void addToPhoneBook(FILE *fp, struct phoneEntry);

// return position
long int searchPhoneBook(FILE *fp, char* query);

#endif //HW3_PHONEBOOK_H
