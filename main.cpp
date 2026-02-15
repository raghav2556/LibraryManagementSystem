#include<iostream>
using namespace std;
#include"function.h"

int main() {
    int choice;

    while(true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add\n";
        cout << "2. Display\n";
        cout << "3. Issue\n";
        cout << "4. Return\n";
        cout << "5. Remove\n";
        cout << "6. Show Issues\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) displayBooks();
        else if (choice == 3) issueBook();
        else if (choice == 4) returnBook();
        else if (choice == 5) removeBook();
        else if (choice == 6) showissuedBook(); 
                
        else break;

    }
    return 0;
}