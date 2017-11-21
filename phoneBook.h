#ifndef HW3_PHONEBOOK_H
#define HW3_PHONEBOOK_H

#include <stdio.h>

struct phoneEntry {
    long int location;
    char firstName[25];
    char lastName[25];
    char phone[11];
    char city[25];
    char address[50];
    unsigned char deleted;
};

/**
 * Add to phone book
 * @param fp
 * @param entry
 */
void addToPhoneBook(FILE *fp, struct phoneEntry entry);

/**
 * search phone book
 * @param fp
 * @param query
 * @param list
 * @return int list count
 */
int searchPhoneBook(FILE *fp, char *query, struct phoneEntry **list);

void printPhoneEntry(struct phoneEntry entry);

void printPhoneEntries(struct phoneEntry *phoneEntries, int count);

/**
 * delete a record from current point of pointer
 * soft delete
 * @param fp
 * @param location
 */
void deletePhoneEntry(FILE *fp, long int location);

#endif //HW3_PHONEBOOK_H
