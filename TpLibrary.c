
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct 
{
    char title[30];
    char author[30];
    //long long int ISBN; i was unable to store this value until i looked up and found this long long thing, i stopped using it because it doesn't work when the user doesn't enter a digit
    char ISBN[30];
} Library;

//CHOICE FUNCTION
int userChoice() {
    int choice;
    printf("                === library === \n          1. add a book\n          2. look for a book by title\n          3. log all books\n          4. delete a book\n          0. quite\n\n enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    printf("choice : %d \n\n", choice);
    while (getchar() != '\n');  
    return choice;
}
//STOP ADDING BOOKS AND QUIT FROM THE ADDING OPTION
int stopAdding(Library s, int done){
    char stop[] = "*";
// i would like to call this high stopping detecter and here is why :
    for (int i = 0; i < 30; i++)
    {
       if (s.title[i] == stop[0] ||s.author[i] == stop[0] || s.ISBN[i] == stop[0]) //with this we are comparing each letter with the stop sign *
    { 
        return done = 1;
    }
    }return done=0;
}

// CHECKING FOR ISBN VALIDATIONS REALTED TO ADD BOOK FUNCTION
int ISBNvalidation(Library I) {
    int i = 0;
    int valid;
    while (i < 13) {
        if (isdigit(I.ISBN[i])) {//isdigit() is a life saver
            i++;
        } else {
            valid = 0; 
            printf("ISBN must be 13 and only contains digits:\n");
            fgets(I.ISBN, sizeof(I.ISBN), stdin);
            return  i = 0; 
        }
    }

    if (i != 13) { 
        valid = 0;
        return 0; 
    }

    return valid;
}

// ADD BOOK FUNCTION 
Library addBook(Library b, int done) {
    int n = 0;
    int digit;
    char stop[] = "*";
        do
    {
        printf("book : %d \n", n+1);
        printf(" enter the book title:");
        fgets(b.title, sizeof(b.title), stdin);
        if (strlen(b.title) < 2) //i did some researches and i found that the shortest book title is one letter
        {
            do
            {
                printf("please enter a correct title:");
                fgets(b.title, sizeof(b.title), stdin);
                done = stopAdding(b ,done);
            } while (strlen(b.title) < 2 && done == 0);
        }
        if (stopAdding(b, done) == 0)
        {
            printf(" enter the book author:");
            fgets(b.author, sizeof(b.author), stdin);  
            done = stopAdding(b ,done); 
            if (strlen(b.author) < 5 && done == 0) // and the shortest author full name is 5 letters
        {
            do
            {
                printf("please enter a correct full author name:");
                fgets(b.author, sizeof(b.author), stdin);
                done = stopAdding(b ,done);
            } while (strlen(b.author) < 5 && done == 0);
        } 
                if (stopAdding(b, done) == 0)
                {
                    printf("enter the book ISBN (13 digits):");
                    fgets(b.ISBN, sizeof(b.ISBN), stdin);
                    done = stopAdding(b ,done);
                    do {
                        if (done != 0)break;
                    
                        if (strlen(b.ISBN) == 14 && done == 0) {
                            do {
                                if (ISBNvalidation(b) == 0) { // Check return value
                                    // we already did when the ISBN is not valid 
                                } else {
                                  break; 
                                }
                    
                                done = stopAdding(b, done);
                    
                            } while (strlen(b.ISBN) == 14 && done == 0);
                    
                        } else {
                            printf("ISBN must be 13 and only contains digits:\n");
                            fgets(b.ISBN, sizeof(b.ISBN), stdin);
                            done = stopAdding(b, done);
                        }
                    } while (strlen(b.ISBN) != 14 && done == 0);
                        // getchar();    
         //i tried using this but it doesn't work when the user doesn't enter a digit
                    // printf(" enter the book ISBN:");
                    // scanf("%lld", &b.ISBN);
                    // if (ISBNvalidation(b.ISBN) < 14) // ISBN number contains 13 digit
                    //     {
                    //         do
                    //         {
                    //             printf("please enter a correct ISBN number 13 digit:");
                    //             scanf("%lld", &b.ISBN);
                    //         } while (ISBNvalidation(b.ISBN) == 14 );
                    //     }
                    // if (b.ISBN == 0)
                    //     {
                    //         return done = 1;
                    //     }
                }     
    }
        done = stopAdding(b ,done);
        n++;
        return b;
    } while (done == 0);
    
}

//SEARCH BOOK FUNCTION 
int searchBook(Library lbr[], int bookCount) { 
    char bookTitle[30];
    int match = 0;

    getchar(); 
    printf("Type book title: ");
    fgets(bookTitle, sizeof(bookTitle), stdin);
    bookTitle[strcspn(bookTitle, "\n")] = '\0'; 

    // Loop through all books to find a match
    for (int i = 0; i < bookCount; i++) {
        lbr[i].title[strcspn(lbr[i].title, "\n")] = '\0'; 
        if (stricmp(lbr[i].title, bookTitle) == 0) {
            printf("Matching title found: %s\n", lbr[i].title);
            match = 1;
            break;
        }
    }

    if (match != 1) {
        printf("No matching titles\n");
    }
}

// LOG ALL BOOK FUNCTION
int displayLibrary(Library lbr[],int bookCount) {
    for (int i = 0; i < bookCount; i++)
    {
        printf("book:%d \n",i+1);
        printf("    title: %s", lbr[i].title);
        printf("    author: %s", lbr[i].author);
        printf("    ISBN: %s\n", lbr[i].ISBN);
    }
    
}

//DELETE BOOK FUNCTION
int deleteBook(Library lbr[], int bookCount) {
    int done = 0, valid, index;
    char input[100];
    char stop[] = "*";

    do {
        valid = 1; 
        printf("Type book number to delete or * to quit: ");
        scanf("%s", input); 

        // Check if the input contains only digits
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                if (input[i] == stop[0]) {
                    done = 1;
                    valid = 1;
                    break; 
                } else {
                    valid = 0;
                    break;
                }
            }
        }

        index = atoi(input); 
    } while (index > bookCount || valid == 0);

    if (done != 1) {
        for (int i = index - 1; i < bookCount - 1; i++) {
            lbr[i] = lbr[i + 1];
        }
        bookCount--;
    }

    return bookCount;  
}

int main() {
    Library lbr[50];
    int choiceValue;
    int bookCount = 0;
    int done ,index, valid, match;
    char input[100]; 
    char stop[] = "*";
    char bookTitle[30];
    
    do
    {
        choiceValue = userChoice();
        
        if (choiceValue == 1) // adding books
        {
        printf("when you are done adding books enter * \n\n");
            do
            {
                lbr[bookCount] = addBook(lbr[bookCount], done);   // each time the user enter a book , it is added to lbr[]
                done = stopAdding(lbr[bookCount], done);
                bookCount++;
            } while (done == 0);
            done = 0;
        }else if (choiceValue == 2) // looking for books
        {
            searchBook(lbr, bookCount);

        }else if (choiceValue == 3) // displaying books
        {
            displayLibrary(lbr, bookCount);
        }else if (choiceValue == 4) // deleting books
        {
            bookCount = deleteBook(lbr, bookCount);

             } 

            } while(choiceValue != 0);
return 0;
}