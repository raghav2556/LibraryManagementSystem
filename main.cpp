#include<iostream>
using namespace std;
#include"function.h"

int main() {
    int choice;

    while(true) {
        cout << "Enter 1.Add 2.Display 3.Exit";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) displayBooks();
        else break;
    }
    return 0;
}