#include <stdio.h>

#include "phoneBook.h"
#include "strhlp.h"


int main() {
    int choice = 1;
    char query[50];
    struct phoneEntry *activeEntries;
    struct phoneEntry activeEntry;
    int phoneEntryCount = 0;
    int index = 0;
    FILE *fp;

    // open file
    fp = fopen("phonebook.dat", "r+");
    if (fp == NULL) {
        fp = fopen("phonebook.dat", "w+");
    }


    for (; choice != 0;) {
        printMenu();
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
                createPhoneEntry(&activeEntry);
                addToPhoneBook(fp, activeEntry);
                printPhoneEntry(activeEntry, 1);
                printSuccess("\n Entry Saved ...");
                break;
            case 3:

                printf("\nQuery:");
                scanf("%s", query);
                phoneEntryCount = searchPhoneBook(fp, query, &activeEntries);
                printPhoneEntries(activeEntries, phoneEntryCount);
                if (phoneEntryCount == 0) {
                    printWarning("\nNo records found");
                    break;
                }

                do {
                    printf("\nPlease select record index to delete:");
                    scanf("%d", &index);

                } while (index < 0 || index >= phoneEntryCount);
                deletePhoneEntry(fp, activeEntries[index].location);
                printSuccess("\nDeleted");
                break;
            case 4:
                printf("\nQuery:");
                scanf("%s", query);
                phoneEntryCount = searchPhoneBook(fp, query, &activeEntries);
                printPhoneEntries(activeEntries, phoneEntryCount);
                if (phoneEntryCount == 0) {
                    printf("\nNo records found");
                    break;
                }

                do {
                    printf("\nPlease select record index to update:");
                    scanf("%d", &index);

                } while (index < 0 || index >= phoneEntryCount);

                createPhoneEntry(&activeEntries[index]);
                updatePhoneEntry(fp, activeEntries[index]);
                printSuccess("\nUpdated");
                break;
            default:
                break;
        }
    }
    fclose(fp);
    clearPhonebook(); // remove soft deleted records
    printf("Bye...\n");
    return 0;
}

