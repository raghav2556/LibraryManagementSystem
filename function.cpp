#include<bits/stdc++.h>
using namespace std;
#include"function.h"

vector<int> BookId;
vector<int> quantity;
vector<int> available;
vector<string> title;
vector<string> author;
unordered_map<int , vector<string>> issued;


void addBook() {
    int id , qty;
    string t , a;

    cout << "Enter Book Id: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin , t);

    cout << "Enter Author: ";
    getline(cin , a);

    cout << "Enter Quantity: ";
    cin >> qty;


    BookId.push_back(id);
    quantity.push_back(qty);
    available.push_back(qty);
    title.push_back(t);
    author.push_back(a);
    
    cout << "Book added Successfully!!" << endl;

}


void displayBooks() {
    cout << "\nID  Title  Author  Available/Total\n";
    for (int i=0 ; i<BookId.size() ; i++) {
        cout << BookId[i] << " "
             << title[i] << " "
             << author[i] << " "
             << available[i] << "/" << quantity[i] << "\n";
    }
}


void issueBook() {
    int id;
    string student;

    cout << "Enter Book ID to be issued: ";
    cin >> id;

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin , student);


    for (int i=0 ; i<BookId.size() ; i++) {
        if (BookId[i] == id) {
            if (available[i] > 0) {
                issued[id].push_back(student);
                available[i]--;

                cout << "Book issued successfully!!\n";
                
            }
            else {
                cout << "Book not available!!\n";
            }
            return;
        }
    }
    cout << "Book not found!!\n";
}


void returnBook() {
    int id;
    string student;

    cout << "Enter Book ID to be returned: ";
    cin >> id;

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, student);


    if (issued.count(id) == 0) {
        cout << "This Book was not issued!!\n";
        return;
    }


    for (int i=0 ; i<issued[id].size() ; i++) {
        if (issued[id][i] == student) {
            issued[id].erase(issued[id].begin() + i);

            for (int j=0 ; j<BookId.size() ; j++) {
                if (BookId[j] == id) {
                    available[j]++;
                    break;
                }
            }

            cout << "Book returned successfully!!\n";

            if(issued[id].empty()) {
                issued.erase(id);
            }
            return;

        }
    }

    cout << "This Student did not issued this Book!!\n";
}