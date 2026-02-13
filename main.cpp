#include<iostream>
using namespace std;
#include"function.h"

int main() {
    int choice;

    while(true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add\n";
        cout << "2. Display\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) displayBooks();
        else break;
    }
    return 0;
}