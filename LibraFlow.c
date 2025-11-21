#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILE_NAME "library.dat"

struct Book {
    int id;
    char name[100];
    char user[100];
    int day, month, year;
    int issued; // 1 = issued, 0 = returned
};

struct Book books[MAX];
int count = 0;

// -------------------- SAVE TO FILE --------------------
void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(books, sizeof(struct Book), count, fp);
    fclose(fp);
}

// -------------------- LOAD FROM FILE --------------------
void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        return; // File does not exist yet
    }
    fread(&count, sizeof(int), 1, fp);
    fread(books, sizeof(struct Book), count, fp);
    fclose(fp);
}

// -------------------- CHECK FOR DUPLICATE ID --------------------
int isDuplicateID(int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].id == id && books[i].issued == 1)
            return 1;
    }
    return 0;
}

// -------------------- ISSUE A BOOK --------------------
void issueBook() {
    if (count >= MAX) {
        printf("\nCannot issue more books!\n");
        return;
    }

    struct Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);

    if (isDuplicateID(b.id)) {
        printf("Book with this ID is already issued!\n");
        return;
    }

    getchar(); // clear buffer

    printf("Enter Book Name: ");
    fgets(b.name, 100, stdin);
    b.name[strcspn(b.name, "\n")] = '\0';

    printf("Enter User Name: ");
    fgets(b.user, 100, stdin);
    b.user[strcspn(b.user, "\n")] = '\0';

    printf("Enter Issue Date (DD MM YYYY): ");
    scanf("%d %d %d", &b.day, &b.month, &b.year);

    b.issued = 1;
    books[count++] = b;

    saveToFile();

    printf("\nBook issued successfully!\n");
}

// -------------------- RETURN A BOOK --------------------
void returnBook() {
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id && books[i].issued == 1) {
            found = 1;

            int rDay, rMonth, rYear;
            printf("Enter Return Date (DD MM YYYY): ");
            scanf("%d %d %d", &rDay, &rMonth, &rYear);

            int issueTotal = books[i].day + books[i].month * 30 + books[i].year * 365;
            int returnTotal = rDay + rMonth * 30 + rYear * 365;
            int diff = returnTotal - issueTotal;

            printf("\nBook was borrowed for %d days.\n", diff);

            if (diff <= 14) {
                printf("No fine.\n");
            } else {
                int late = diff - 14;
                int fine = late * 2;
                printf("Late by %d days.\n", late);
                printf("Fine Amount = ₹%d\n", fine);
            }

            books[i].issued = 0; 
            saveToFile();

            printf("Book returned successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Book ID not found or already returned!\n");
}

// -------------------- VIEW ALL ISSUED BOOKS --------------------
void viewIssuedBooks() {
    int any = 0;
    printf("\n========== Issued Books ==========\n");

    for (int i = 0; i < count; i++) {
        if (books[i].issued == 1) {
            any = 1;
            printf("ID: %d | Book: %s | User: %s | Date: %d-%d-%d\n",
                   books[i].id, books[i].name, books[i].user,
                   books[i].day, books[i].month, books[i].year);
        }
    }

    if (!any)
        printf("No books are currently issued.\n");
}

// -------------------- EDIT BOOK DETAILS --------------------
void editBook() {
    int id;
    printf("\nEnter Book ID to EDIT: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            printf("\nEditing Book ID %d\n", id);
            printf("Enter New Book Name: ");
            fgets(books[i].name, 100, stdin);
            books[i].name[strcspn(books[i].name, "\n")] = '\0';

            printf("Enter New User Name: ");
            fgets(books[i].user, 100, stdin);
            books[i].user[strcspn(books[i].user, "\n")] = '\0';

            printf("Enter New Issue Date (DD MM YYYY): ");
            scanf("%d %d %d", &books[i].day, &books[i].month, &books[i].year);

            saveToFile();
            printf("Book details updated successfully!\n");
            return;
        }
    }

    printf("Book ID not found!\n");
}

// -------------------- DELETE BOOK RECORD --------------------
void deleteBook() {
    int id;
    printf("\nEnter Book ID to DELETE: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }

            count--;
            saveToFile();

            printf("Book record deleted successfully!\n");
            return;
        }
    }
    printf("Book ID not found!\n");
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    loadFromFile(); 

    int choice;

    while (1) {
        printf("\n=========== Library Management System ===========\n");
        printf("1. Issue a Book\n");
        printf("2. Return a Book & Calculate Fine\n");
        printf("3. View All Issued Books\n");
        printf("4. Edit Book Details\n");
        printf("5. Delete Book Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: issueBook(); break;
            case 2: returnBook(); break;
            case 3: viewIssuedBooks(); break;
            case 4: editBook(); break;
            case 5: deleteBook(); break;
            case 6:
                printf("\nExiting... Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
