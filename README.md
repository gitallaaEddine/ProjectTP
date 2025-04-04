# Library Management System (C)

## Overview

This is a simple library management system implemented in C. It allows users to perform basic library operations such as adding books with validation, searching for books by title, displaying all books, and deleting books. The system emphasizes input validation and provides a user-friendly experience.

## How to Run

1.  **Compile the program:**

    ```bash
    gcc TpLibrary.c -o library
    ```

2.  **Run the program:**

    ```bash
    ./library
    ```

## Features and Functionality

### 1. Add a Book (`addBook` function)

This function allows users to add new books to the library. It enforces strict validation rules to ensure data integrity.

**Validation Rules:**

*   **Title:** Must be at least 2 characters long.
*   **Author:** Must be a real name with at least 5 characters.
*   **ISBN:** Must be exactly 13 digits (numbers only).

**Quit Functionality:**

*   The user can quit the `addBook` function at any input prompt by entering `*`.

**Example of Invalid Input Handling:**

```yaml
Enter the book title: A
Please enter a correct title: Harry Potter

Enter the book author: J.K
Please enter a correct full author name: J.K. Rowling

Enter the book ISBN: 12345A7890123
ISBN must be 13 digits and contain only numbers: 9783161484100
```
Screenshot:

[Insert Screenshot of Adding a Book Here]

2. Search for a Book by Title (searchBook function)
This function enables users to search for books by their title.

Key Features:

Case-insensitive search.

Displays book details if a match is found.
The user can quit by entering *.
Example:
```yaml
Type book title: harry potter
Matching title found:
   Title: Harry Potter
   Author: J.K. Rowling
   ISBN: 9783161484100
```
Screenshot:

[Insert Screenshot of Searching for a Book Here]

3. Display All Books (displayLibrary function)
This function lists all the books currently stored in the library, providing full details for each book.

Output Format:
```yaml
Books in library:
1.
   Title: Harry Potter
   Author: J.K. Rowling
   ISBN: 9783161484100

2.
   Title: The Great Gatsby
   Author: F. Scott Fitzgerald
   ISBN: 9780743273565
```
Screenshot:

[Insert Screenshot of Displaying Books Here]

4. Delete a Book (deleteBook function)
This function allows users to delete a book from the library by specifying its index.

Input:

The user is prompted to enter the index of the book to delete.
The user can quit by entering *.
Note:

The index is based on the order in which the books are displayed.
5. Quit the Program
To exit the program, choose option 0 from the main menu.

Example:
```yaml
Enter your choice: 0
Exiting the program...
```
