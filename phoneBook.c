#include <memory.h>
#include <malloc.h>
#include "phoneBook.h"
#include "strhlp.h"

#define SEARCH_LIMIT 20

int searchPhoneBook(FILE *fp, char *query, struct phoneEntry **phoneEntries) {

    struct phoneEntry entry;

    int count = 0;
    //from beginning
    fseek(fp, 0, SEEK_SET);

    // for each line read
    *phoneEntries = (struct phoneEntry *) malloc(1 * sizeof(struct phoneEntry));
    while (fread(&entry, sizeof(struct phoneEntry), 1, fp) == 1 && count < SEARCH_LIMIT) {
        if (entry.deleted == 1) {
            continue;
        }
        if (strstr(entry.firstName, query) != NULL
            || strstr(entry.lastName, query) != NULL
            || strstr(entry.phone, query) != NULL
            || strstr(entry.city, query) != NULL
            || strstr(entry.address, query) != NULL) {
            *phoneEntries = (struct phoneEntry *) realloc(*phoneEntries, ++count * sizeof(struct phoneEntry));
            entry.location = ftell(fp) - sizeof(struct phoneEntry); // set location to record
            (*phoneEntries)[count - 1] = entry;
        }

    }
    return count;
}

void addToPhoneBook(FILE *fp, struct phoneEntry entry) {
    fseek(fp, 0, SEEK_END); // to end of file
    entry.deleted = 0;
    fwrite(&entry, sizeof(struct phoneEntry), 1, fp);

}


void printPhoneEntries(struct phoneEntry *phoneEntries, int count) {

    printf("\n## %-25s%-25s%-11s%-25s%-50s", "First Name", "Last Name", "Phone", "City", "Addres");

    for (int i = 0; i < count; i++) {
        printSuccess("\n%02d %-25s%-25s%-11s%-25s%-50s",
                     i,
                     phoneEntries[i].firstName,
                     phoneEntries[i].lastName,
                     phoneEntries[i].phone,
                     phoneEntries[i].city,
                     phoneEntries[i].address
        );
    }
}

void printPhoneEntry(struct phoneEntry entry, int index) {

    printf("\n## %-25s%-25s%-11s%-25s%-50s", "First Name", "Last Name", "Phone", "City", "Addres");
    printSuccess("\n%02d %-25s%-25s%-11s%-25s%-50s", index, entry.firstName, entry.lastName, entry.phone, entry.city,
                 entry.address);

}


void deletePhoneEntry(FILE *fp, long int location) {

    struct phoneEntry entry;
    fseek(fp, location, SEEK_SET);
    fread(&entry, sizeof(struct phoneEntry), 1, fp);
    entry.deleted = 1;
    fseek(fp, -sizeof(struct phoneEntry), SEEK_CUR);
    fwrite(&entry, sizeof(struct phoneEntry), 1, fp);
}

void updatePhoneEntry(FILE *fp, struct phoneEntry entry) {
    fseek(fp, entry.location, SEEK_SET);
    fwrite(&entry, sizeof(struct phoneEntry), 1, fp);
}

void createPhoneEntry(struct phoneEntry *entry) {
    printf("\nFirst Name:");
    scanf("%s", entry->firstName);
    printf("\nLast Name:");
    scanf("%s", entry->lastName);
    printf("\nPhone:");
    scanf("%s", entry->phone);
    printf("\nCity:");
    scanf("%s", entry->city);
    getchar();
    printf("\nAddress:");
    fgets(entry->address, 50, stdin);
    entry->address[strcspn(entry->address, "\r\n")] = 0;

}


void printMenu() {
    printWarning("\n--------------Menu-------------");
    printf("\n1- Search");
    printf("\n2- Add");
    printf("\n3- Delete");
    printf("\n4- Update");
    printf("\n0- Exit");
    printWarning("\n-------------------------------");
}

void clearPhonebook() {

    struct phoneEntry entry;

    FILE *fp = fopen("phonebook.dat", "r");
    FILE *tmp = fopen("phonebook.tmp.dat", "w");
    while (fread(&entry, sizeof(struct phoneEntry), 1, fp) == 1) {
        if (entry.deleted == 1) {
            continue;
        }
        entry.location = 0;
        fwrite(&entry, sizeof(struct phoneEntry), 1, tmp);
    }
    fclose(tmp);
    fclose(fp);
    remove("phonebook.dat");
    rename("phonebook.tmp.dat", "phonebook.dat");

}