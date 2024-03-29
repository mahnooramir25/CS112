// 𓂀 𝔽𝕒𝕚𝕫𝕒𝕟 𝟚𝟘𝟚𝟙𝟛𝟞𝟠 𓂀
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <time.h>

using namespace std;

struct Book
{
    int ID, price, pages;
    string BookName, author, ISBN;

    void PrintBook() {
        cout << "\nID: " << ID << "\nBook name: " << BookName
            << "\nAuthor: " << author << "\nISBN: " << ISBN
            << "\nPrice: " << price << "\nPages: " << pages << endl;
    }
};

struct BookList
{
    Book books[5];
    int numberOfBooks = 0;

    int FindBookIndex(int ID) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (books[i].ID == ID)
                return i;
        }
        return 10;
    }

    void PrintAll(Book bookslist_local[]) {
        for (int i = 0; i < numberOfBooks; i++) {
            bookslist_local[i].PrintBook();
            cout << endl;
        }
    }

    void PrintSpecifiedBook(int ID) {
        int bookIndex = FindBookIndex(ID);
        if (bookIndex != 10)
            books[bookIndex].PrintBook();
        else
            cout << "BOOK NOT FOUND!\n";
    }

    void PrintSortedBooks(bool ascending_descending) {
        for (int i = 0; i < numberOfBooks; i++) {
            for (int j = 0; j < numberOfBooks - 1; j++) {
                if (ascending_descending == 1) {
                    if (books[j].ID > books[j + 1].ID)
                        swap(books[j], books[j+1]);
                }
                else {
                    if (books[j].ID < books[j + 1].ID)
                        swap(books[j], books[j+1]);

                }
            }
        }
        // printing the books
        PrintAll(books);
    }

    void AddBook() {
        int BookID;
        cout << "FOR BOOK " << numberOfBooks + 1 << endl;
        cout << "\tEnter ID: ";
        cin >> BookID;
        if(FindBookIndex(BookID) != 10){
            cout << "Book ID already Exists in the system!\n";
            return;
        }
        books[numberOfBooks].ID = BookID;
        cout << "\tEnter BookName: ";
        cin >> books[numberOfBooks].BookName;
        cout << "\tEnter author: ";
        cin >> books[numberOfBooks].author;
        cout << "\tEnter ISBN: ";
        cin >> books[numberOfBooks].ISBN;
        cout << "\tEnter price: ";
        cin >> books[numberOfBooks].price;
        cout << "\tEnter pages: ";
        cin >> books[numberOfBooks].pages;

        numberOfBooks++;
    }

    void DeleteBook() {
        int ID_toBeDeleted;
        cout << "Enter ID to be deleted: ";
        cin >> ID_toBeDeleted;

        int i = FindBookIndex(ID_toBeDeleted);
        if(i == 10){
            cout << "Book ID cannot be found!\n";
            return;
        } 

        for (i; i < numberOfBooks - 1; i++) {
            swap(books[i], books[i+1]);
        }
        numberOfBooks--;
    }

    // NO USE FOR THIS FUNCTION
    void AddBook_SpecificIndex(int i){
        int BookID;
        cout << "FOR BOOK " << numberOfBooks + 1 << endl;
        cout << "\tEnter ID: ";
        cin >> BookID;
        if(FindBookIndex(BookID) != 10){
            cout << "Book ID already Exists in the system!\n";
            return;
        }
        books[i].ID = BookID;
        cout << "\tEnter BookName: ";
        cin >> books[i].BookName;
        cout << "\tEnter author: ";
        cin >> books[i].author;
        cout << "\tEnter ISBN: ";
        cin >> books[i].ISBN;
        cout << "\tEnter price: ";
        cin >> books[i].price;
        cout << "\tEnter pages: ";
        cin >> books[i].pages;

        numberOfBooks++;
    }
};

struct Student {
    int ID, RollNo;
    string StdName;

    void PrintStudent() {
        cout << "\nID: " << ID << "\nStudent name: " << StdName
            << "\nRoll No: " << RollNo << endl;
    }
};

struct StudentList {
    Student students[5];
    int numberOfStudents = 0;

    // these functions are copy pasted as is from the booksList structure with names changed

    void PrintAll(Student bookslist_local[]) {
        for (int i = 0; i < numberOfStudents; i++) {
            bookslist_local[i].PrintStudent();
            cout << endl;
        }
    }

    int FindStdIndex(int ID) {
        for (int i = 0; i < numberOfStudents; i++) {
            if (students[i].ID == ID)
                return i;
        }
        return 10;
    }

    void AddStudent() {
        cout << "FOR STUDENT " << numberOfStudents + 1 << endl;
        int ID;
        cout << "\tEnter ID: ";
        cin >> ID;
        if(FindStdIndex(ID) != 10){
            cout << "Student ID cannot be found!\n";
            return;
        }
        students[numberOfStudents].ID = ID;
        cout << "\tEnter Name: ";
        cin >> students[numberOfStudents].StdName;
        cout << "\tEnter Roll No: ";
        cin >> students[numberOfStudents].RollNo;

        numberOfStudents++;
    }

    void DeleteStudent() {
        int ID_toBeDeleted;
        cout << "Enter ID to be deleted: ";
        cin >> ID_toBeDeleted;

        int i =  FindStdIndex(ID_toBeDeleted);
        if(i == 10){
            cout << "Student ID cannot be found!\n";
            return;
        }
        for (i; i < numberOfStudents - 1; i++) {
            swap(students[i], students[i+1]);
        }
        numberOfStudents--;
    }
};

int Menu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char key_press;
    int ascii_value;
    int current_menu = 1;

    while (1) {
        system("CLS");

        SetConsoleTextAttribute(hConsole, 15);
        cout << "\tMAIN MENU \nUSE ARROW KEYS TO NAVIGATE!\n";

        switch (current_menu) {

        case 1:
            SetConsoleTextAttribute(hConsole, 112);
            cout << "\n1. Add New Student. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "2. Delete Existing Student. \n3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "2. Delete Existing Student.\n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "3. Show all Students. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "4. Add New Book. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n4. Add New Book. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "5. Delete Existing Book. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 6:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "6. Show particular Book. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 7:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "7. Show all Books. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 8:
            SetConsoleTextAttribute(hConsole, 8);   
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "8. Sort Books in Ascending order. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "9. Sort Books in Descending order. \n10. Exit\n";
            break;
        case 9:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "9. Sort Books in Descending order. \n";
            SetConsoleTextAttribute(hConsole, 8);
            cout << "10. Exit\n";
            break;
        case 10:
            SetConsoleTextAttribute(hConsole, 8);
            cout << "\n1. Add New Student. \n2. Delete Existing Student.\n3. Show all Students. \n4. Add New Book. \n5. Delete Existing Book. \n6. Show particular Book. \n7. Show all Books. \n8. Sort Books in Ascending order. \n9. Sort Books in Descending order. \n";
            SetConsoleTextAttribute(hConsole, 112);
            cout << "10. Exit OR PRESS ESC KEY\n";
            SetConsoleTextAttribute(hConsole, 8);
            break;
        }

        key_press = _getch();
        ascii_value = key_press;

        if (ascii_value == 72){
            if (current_menu > 1){
                Beep(500, 120);
                current_menu--;
            } else{
                Beep(500, 120);
                current_menu = 10;
            }
        }
        else if (ascii_value == 80) {
            if (current_menu < 10){
                Beep(500, 150);
                current_menu++;
            } else{
                Beep(500, 120);
                current_menu = 1;
            }
        }
        else if (ascii_value == 27)
            return 10;
        else if (ascii_value == 13)
            return current_menu;
    }
}

void Loading(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // mciSendString("open \"Loading_Sound.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    cout<<"\a";
    system("CLS");
    // SetConsoleTextAttribute(hConsole, 15);
    // PlaySound(TEXT("Added_Student.wav"), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
    // mciSendString(TEXT("Added_Student.wav"), NULL, 0, NULL);
    cout << "\n\n\n\n\n\tLoading...\n";
    // mciSendString("play mp3", NULL, 0, NULL);
    for(int i = 0; i< 10; i++){
        Beep(1500, 150);
        Sleep(50);
        SetConsoleTextAttribute(hConsole, 20 + (15*i));
        cout << "  ";
        SetConsoleTextAttribute(hConsole, 8);
        cout << " ";      
    }

}

int main() {

    BookList listOfBooks;
    StudentList listOfStudents;

    // menu
    Loading();

    bool running = 1;
    while (running) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int mmoption = Menu();
        system("CLS");
        SetConsoleTextAttribute(hConsole, 15);
        switch (mmoption)
        {
        case 1:
            if (listOfStudents.numberOfStudents < 5)
                listOfStudents.AddStudent();
            else
                cout << "System already has 5 students!\n";
            break;

        case 2:
            if (listOfStudents.numberOfStudents > 0)
                listOfStudents.DeleteStudent();
            else
                cout << "The system currently has 0 students!\n";
            break;

        case 3:
            if (listOfStudents.numberOfStudents > 0)
                listOfStudents.PrintAll(listOfStudents.students);
            else
                cout << "The system currently has 0 students!\n";
            break;

        case 4:
            if (listOfBooks.numberOfBooks < 5)
                listOfBooks.AddBook();
            else
                cout << "System already has 5 Books!\n";
            break;

        case 5:
            if (listOfBooks.numberOfBooks != 0)
                listOfBooks.DeleteBook();
            else
                cout << "The system currently has 0 Books!\n";
            break;

        case 6:
            int ID_toShow;
            cout << "Enter Book ID to print: ";
            cin >> ID_toShow;
            listOfBooks.PrintSpecifiedBook(ID_toShow);
            break;

        case 7:
            if (listOfBooks.numberOfBooks != 0)
                listOfBooks.PrintAll(listOfBooks.books);
            else
                cout << "No Books to show!\n";
            break;

        case 8:
            if (listOfBooks.numberOfBooks != 0) {
                listOfBooks.PrintSortedBooks(1);
                cout << "\nBooks List has been sorted in Ascending order\n";
            }
            else
                cout << "No Books to show!\n";
            break;

        case 9:
            if (listOfBooks.numberOfBooks != 0) {
                listOfBooks.PrintSortedBooks(0);
                cout << "\nBooks List has been sorted in Descending order\n";
            }
            else
                cout << "No Books to show!\n";
            break;

        case 10:
            running = 0;
            cout << "\nEXITING";
            for (int i = 0; i < 3; i++) {
                Sleep(500);
                cout << ".";
            }
            break;
        }
        
        if (running)
            system("PAUSE");
    }

    return 0;
}