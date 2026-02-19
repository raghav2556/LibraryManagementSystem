#include<bits/stdc++.h>
using namespace std;
#include"function.h"

vector<int> BookId;
vector<int> quantity;
vector<int> available;
vector<string> title;
vector<string> author;
unordered_map<int , vector<string>> issued;
unordered_map<int , int> bookid;


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

    if (bookid.count(id)) {
        available[bookid[id]] += qty;
        quantity[bookid[id]] += qty;

        cout << "Books is already Present , Quantity Upated!!\n";
        return;
    }


    BookId.push_back(id);
    bookid[id] = BookId.size() - 1;
    quantity.push_back(qty);
    available.push_back(qty);
    title.push_back(t);
    author.push_back(a);
    
    cout << "Book added Successfully!!" << endl;

}


void displayBooks() {
    if (BookId.empty()) {
        cout << "No Books available to display!!\n";
        return;
    }
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


   if (bookid.count(id)) {
            for (string s : issued[id]) {
                if (s == student) {
                    cout << "Student already has this book!!\n";
                    return;
                }
            }
            if (available[bookid[id]] > 0) {
                issued[id].push_back(student);
                available[bookid[id]]--;

                cout << "Book issued successfully!!\n";
                
            }
            else {
                cout << "Book not available!!\n";
            }
            return;
        
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

    bool found = false;

    if (bookid.count(id)) found = true;

    if (!found) {
        cout << "Book is not present in Library!!\n";
        return;
    }


    if (issued.count(id) == 0) {
        cout << "This Book was not issued!!\n";
        return;
    }


    for (int i=0 ; i<issued[id].size() ; i++) {
        if (issued[id][i] == student) {
            issued[id].erase(issued[id].begin() + i);

            available[bookid[id]]++;

            cout << "Book returned successfully!!\n";

            if(issued[id].empty()) {
                issued.erase(id);
            }
            return;

        }
    }

    cout << "This Student did not issued this Book!!\n";
}

void removeBook() {
    int id;

    cout << "Enter Book ID to be removed: ";
    cin >> id;

    
        if (bookid.count(id)) {
            int idx = bookid[id];
          
            if (available[idx] != quantity[idx]) {
                cout << "Some copies are still issued , Cannot be removed!!\n";
                return;
            }
            BookId.erase(BookId.begin() + idx);
            title.erase(title.begin() + idx);
            author.erase(author.begin() + idx);
            available.erase(available.begin() + idx);
            quantity.erase(quantity.begin() + idx);

            bookid.erase(id);

            for (int i = idx; i < BookId.size(); i++) {
                 bookid[BookId[i]] = i;
            }

            cout << "Book removed successfully!!\n";
            return;
           }
        

        cout << "Book not found!!\n";
    }


void showissuedBook() {
    int id;

    cout << "Enter Book ID to be checked: ";
    cin >> id;

    if (issued.count(id) == 0) {
        cout << "This Book was not issued!!\n";
        return;
    }
    
    bool found = false;

    if (bookid.count(id)) found = true;

    if (!found) {
        cout << "Book is not present in Library!!\n";
        return;
    }


    cout << "Book is issued to: ";
    for (int i=0 ; i<issued[id].size() ; i++) {
        cout << issued[id][i];
        if (i != issued[id].size()-1) {
            cout << ", ";
        }
    }
}
   