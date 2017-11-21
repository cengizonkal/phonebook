#include <memory.h>
#include <malloc.h>
#include "phoneBook.h"

int searchPhoneBook(FILE *fp, char *query, struct phoneEntry **phoneEntries) {

    struct phoneEntry entry;
    int count = 0;
    //from beginning
    fseek(fp, 0, SEEK_SET);

    // for each line read
    *phoneEntries = (struct phoneEntry *) malloc(1 * sizeof(struct phoneEntry));
    while (fread(&entry, sizeof(struct phoneEntry), 1, fp) == 1) {
        if (entry.deleted == 1) {
          //  continue;
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

    for (int i = 0; i < count; i++) {
        printf("\n%04d", i);
        printPhoneEntry(phoneEntries[i]);
    }
}

void printPhoneEntry(struct phoneEntry entry) {

    printf("\n-------------------------------");
    printf("\n First Name:%s", entry.firstName);
    printf("\n Last Name:%s", entry.lastName);
    printf("\n Phone:%s", entry.phone);
    printf("\n City:%s", entry.city);
    printf("\n Address:%s", entry.address);
    printf("\n Location:%li", entry.location);
    printf("\n Deleted:%i", entry.deleted);
    printf("\n-------------------------------");

}


void deletePhoneEntry(FILE *fp, long int location) {

    struct phoneEntry entry;
    fseek(fp, location, SEEK_SET);
    fread(&entry, sizeof(struct phoneEntry), 1, fp);
    entry.deleted = 1;
    fseek(fp, location, SEEK_SET);
    fwrite(&entry, sizeof(struct phoneEntry), 1, fp);
}