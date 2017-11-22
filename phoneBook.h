#ifndef HW3_PHONEBOOK_H
#define HW3_PHONEBOOK_H

#include <stdio.h>
#include "colors.h"

struct phoneEntry {
    long int location; // ftell
    char firstName[25];
    char lastName[25];
    char phone[12];
    char city[25];
    char address[50];
    unsigned char deleted; //soft delete
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

/**
 * print only one record
 * @param entry
 */
void printPhoneEntry(struct phoneEntry entry, int);

/**
 * Print records as table
 * @param phoneEntries
 * @param count
 */
void printPhoneEntries(struct phoneEntry *phoneEntries, int count);

/**
 * delete a record from current point of pointer
 * soft delete
 * @param fp
 * @param location
 */
void deletePhoneEntry(FILE *fp, long int location);

/**
 * update record
 * @param fp
 * @param entry
 */
void updatePhoneEntry(FILE *fp, struct phoneEntry entry);

/**
 * read from input
 * @param entry
 */
void createPhoneEntry(struct phoneEntry *entry);

/**
 * Show user menu
 */
void printMenu();


void clearPhonebook();

#endif //HW3_PHONEBOOK_H
