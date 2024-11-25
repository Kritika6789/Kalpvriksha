#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Users{
    char name[50];
    int id;
    int age;
};

void createFile() {
    FILE *fptr = fopen("Users.txt", "w");
    fclose(fptr);
}

void createUser() {
    FILE *fptr = fopen("Users.txt", "a");
    FILE *temp = fopen("Users.txt", "r");
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    Users user;
    int found = 0;
    char line[100];
    while (fgets(line, sizeof(line), temp)) {
        sscanf(line, "%49[^\t]\t%d\t%d", user.name, &user.id, &user.age);
        if (user.id == id) {
            found = 1;
            break;
        }
    }
    fclose(temp);

    if (found) {
        printf("ID already exists.\n");
    } else {
        getchar();
        printf("Enter User Name: ");
        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = '\0';

        user.id = id;
        printf("Enter Age: ");
        scanf("%d", &user.age);
        fprintf(fptr, "%s\t%d\t%d\n", user.name, user.id, user.age);
        printf("User added successfully.\n");
    }
    fclose(fptr);
}

void displayUsers() {
    FILE *fptr = fopen("Users.txt", "r");
    Users user;
    char line[100];
    printf("\nUser Data:\n");

    while (fgets(line, sizeof(line), fptr)) {
        sscanf(line, "%49[^\t]\t%d\t%d", user.name, &user.id, &user.age);

        printf("Username: %s\tUserID: %d\tUserAge: %d\n", user.name, user.id, user.age);
    }
    fclose(fptr);
}

void updateUser() {
    FILE *fptr = fopen("Users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    Users user;
    char line[100];

    while (fgets(line, sizeof(line), fptr)) {
        sscanf(line, "%49[^\t]\t%d\t%d", user.name, &user.id, &user.age);

        if (user.id == id) {
            found = 1;
            getchar();
            printf("Enter New Name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%s\t%d\t%d\n", user.name, user.id, user.age);
    }

    fclose(fptr);
    fclose(temp);

    remove("Users.txt");
    rename("temp.txt", "Users.txt");

    if (!found) {
        printf("ID not found.\n");
    } else {
        printf("User updated successfully.\n");
    }
}

void deleteUser() {
    FILE *fptr = fopen("Users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    int id;
    int found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Users user;
    char line[100];

    while (fgets(line, sizeof(line), fptr)) {
        sscanf(line, "%49[^\t]\t%d\t%d", user.name, &user.id, &user.age);

        if (user.id == id) {
            found = 1;
            continue;
        }
        fprintf(temp, "%s\t%d\t%d\n", user.name, user.id, user.age);
    }

    fclose(fptr);
    fclose(temp);

    remove("Users.txt");
    rename("temp.txt", "Users.txt");

    if (!found) {
        printf("ID not found.\n");
    } else {
        printf("User deleted successfully.\n");
    }
}

int main() {
    
    createFile();
    int choice=1;;
    while (choice!=5) {
        printf(" enter 1 to  create User\n");
        printf(" enter 2 to display Users\n");
        printf(" enter 3 to update User\n");
        printf(" enter 4 to delete User\n");
        printf("enter  5 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:createUser();
                break;
            case 2:displayUsers();
                break;
            case 3:updateUser();
                break;
            case 4:deleteUser();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}