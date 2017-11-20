#include <memory.h>
#include "phoneBook.h"

long int searchPhoneBook(FILE *fp, char *query) {

    struct phoneEntry entry;
    while (fread(&entry, sizeof(struct phoneEntry), 1, fp) == 1) {

        if (strcmp(entry.firstName, query) == 0) {
            fseek(fp, -sizeof(struct phoneEntry), SEEK_CUR);
            return ftell(fp);
        }
    }

}