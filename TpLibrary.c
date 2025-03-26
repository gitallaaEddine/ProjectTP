#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    return choice;
}
//STOP ADDING BOOKS AND QUIT FROM THE ADDING OPTION
int stopAdding(Library s, int done){
    char stop[] = "*";

    for (int i = 0; i < 30; i++)
    {
       if (s.title[i] == stop[0] ||s.author[i] == stop[0] || s.ISBN[i] == stop[0])
    {
        return done = 1;
    }else {return done=0;}
    }
}

// CHECKING FOR ISBN VALIDATIONS
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
            return 0; 
        }
    }

    if (i != 13) { 
        valid = 0;
        return 0; 
    }

    return valid;
}

// ADD BOOK FUNCTION 
int addBook(Library b) {
    int n = 0;
    int done;
    int digit;
    char stop[] = "*";
    printf("when you are done adding books enter * \n\n");
        do
    {
        getchar();
        printf("book : %d \n", n+1);
        printf(" enter the book title:");
        fgets(b.title, sizeof(b.title), stdin);
        if (strlen(b.title) < 2) //i did some researches and i found that the shortest book title is one letter
        {
            do
            {
                printf("please enter a correct title:");
                fgets(b.title, sizeof(b.title), stdin);
                done = stopAdding(b,done);
            } while (strlen(b.title) < 2 && done == 0);
        }
        if (stopAdding(b, done) == 0)
        {
            printf(" enter the book author:");
            fgets(b.author, sizeof(b.author), stdin);  
            done = stopAdding(b,done); 
            if (strlen(b.author) < 5 && done == 0) // and the shortest author full name is 5 letters
        {
            do
            {
                printf("please enter a correct full author name:");
                fgets(b.author, sizeof(b.author), stdin);
                done = stopAdding(b,done);
            } while (strlen(b.author) < 5 && done == 0);
        } 
                if (stopAdding(b, done) == 0)
                {
                    printf("enter the book ISBN:");
                    fgets(b.ISBN, sizeof(b.ISBN), stdin);
                    done = stopAdding(b,done);
                    do {
                        if (done != 0)
                        {
                            break;
                        }
                        
                    
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
        done = stopAdding(b,done);
        n++;
    } while (done == 0);
}


int main() {
    Library lbr[50];
    int choiceValue;
    do
    {
        choiceValue = userChoice();
        
        if (choiceValue == 1)
        {
        addBook(lbr[50]);   
        }
         
    } while(choiceValue != 0);
    

    
        
return 0;
}