#include <stdio.h>

#include "phoneBook.h"

int main() {
    int choice = 1;
    char query[50];
    struct phoneEntry *activeEntries;
    struct phoneEntry activeEntry;
    int phoneEntryCount = 0;
    int index = 0;

    FILE *fp;

    fp = fopen("phonebook.dat", "r+");
    if (fp == NULL) {
        fp = fopen("phonebook.dat", "w+");
    }

    for (; choice != 0;) {
        printf("\n--------------Menu-------------");
        printf("\n1- Search");
        printf("\n2- Add");
        printf("\n3- Delete");
        printf("\n4- Update");
        printf("\n0- Exit");
        printf("\n-------------------------------");
        printf("\nPlease select : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nQuery:");
                scanf("%s", query);
                phoneEntryCount = searchPhoneBook(fp, query, &activeEntries);
                printPhoneEntries(activeEntries, phoneEntryCount);
                break;
            case 2:
                printf("\nFirst Name:");
                scanf("%s", activeEntry.firstName);
                printf("\nLast Name:");
                scanf("%s", activeEntry.lastName);
                printf("\nPhone:");
                scanf("%s", activeEntry.phone);
                printf("\nCity:");
                scanf("%s", activeEntry.city);
                printf("\nAddress:");
                scanf("%s", activeEntry.address);
                addToPhoneBook(fp, activeEntry);
                printPhoneEntry(activeEntry);
                printf("\n Entry Saved ...");
                break;
            case 3:

                printf("\nQuery:");
                scanf("%s", query);
                phoneEntryCount = searchPhoneBook(fp, query, &activeEntries);
                printPhoneEntries(activeEntries, phoneEntryCount);

                if (phoneEntryCount == 0) {
                    printf("\nNo records found");
                    break;
                }

                do {
                    printf("\nPlease select record index to delete:");
                    scanf("%d", &index);

                } while (index < 0 || index >= phoneEntryCount);
                deletePhoneEntry(fp, activeEntries[index].location);
                printf("\nDeleted");
                break;
            default:
                break;
        }
    }
    fclose(fp);
    printf("Bye...\n");
    return 0;
}