#include <stdio.h>
#include <stdlib.h>

struct contact {
    char name[50];
    char phno[15]; 
};

struct contact cont[100];
int i;
int count = 0;

void add() {
    int count1, n;
    printf("Enter number of contacts to be added: ");
    scanf("%d", &count1);
    n = count;
    count += count1;

    for (i = 0; i < count1; i++) {
        printf("Enter contact name: ");
        scanf("%s", cont[n].name);
        printf("Enter phone number: ");
        scanf("%s", cont[n].phno);
        n++;
    }
}

void display() {
    for (i = 0; i < count; i++) {
        printf("Contact Name: %s\n", cont[i].name);
        printf("Contact Number: %s\n", cont[i].phno);
    }
}

void save() {
    FILE *fp;
    fp = fopen("contact.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    } else {
        for (i = 0; i < count; i++) {
            fprintf(fp, "%s,%s\n", cont[i].name, cont[i].phno); 
        }
        fclose(fp);
        printf("Contacts saved permanently successfully\n");
    }
}

void retrieve() {
    FILE *fp;
    fp = fopen("contact.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    } else {
        count = 0; 
        while (fscanf(fp, "%[^,],%s\n", cont[count].name, cont[count].phno) != EOF) { 
            count++;
        }
        fclose(fp);
        printf("Data retrieved successfully\n");
    }
}

int main() {
    int s, op;
    s = 1;
    while (s == 1) { 
        printf("Choose option 1 for adding contact, 2 for printing, 3 for saving, 4 for retrieving: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                save();
                break;
            case 4:
                retrieve();
                break;
            default:
                printf("Wrong option\n");
                break;
        }
        printf("Press 1 to continue else 0: ");
        scanf("%d", &s);
    }

    return 0;
}
