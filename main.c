#include <stdio.h>

#include "phoneBook.h"

int main() {
    int choice;
    char query[50];
    long int fileLocation;
    struct phoneEntry activeEntry;
    FILE *fp;
    fp = fopen("phonebook.dat", "a+");

    for (; choice != 0;) {
        printf("\n----------Menu---------");
        printf("\n1- Search");
        printf("\n2- Add");
        printf("\n3- Delete");
        printf("\n4- Update");
        printf("\n0- Exit");
        printf("\nPlease select : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nQuery:");
                scanf("%s", query);
                fileLocation = searchPhoneBook(fp, query);
                fseek(fp,fileLocation,SEEK_SET);
                fread(&activeEntry, sizeof(struct phoneEntry), 1, fp);
            default:
                break;
        }
    }

    return 0;
}