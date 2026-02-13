#include<bits/stdc++.h>
using namespace std;
#include"function.h"

vector<int> BookId;
vector<int> quantity;
vector<int> available;
vector<string> title;
vector<string> author;


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
    
    cout << "Book added Successfully" << endl;

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