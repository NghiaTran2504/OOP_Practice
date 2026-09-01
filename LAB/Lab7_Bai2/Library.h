#pragma once

#include "Book.h"
#include <vector>

class Library {
private:
	string nameLibrary;
	vector <Book*> bookList;

public:
	Library() = default;
	Library(string name) : nameLibrary(name) {}
	~Library() {
		for (int i = 0; i < bookList.size(); ++i) {
			delete bookList[i];
		}
		bookList.clear();
	}

	void nhap() {
		cout << "Number of books in library: ";
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			Book* newBook = new Book;
			cout << "\n==== BOOK " << i + 1 << " ====\n";
			cin >> *newBook;
			bookList.push_back(newBook);
		}
	}

	void xuat() {
		cout << "\nNumber of books in library: " << bookList.size() << "\n";
		cout << " ==== LIST BOOKS ====\n";
		for (int i = 0; i < bookList.size(); ++i) {
			cout << "BOOK " << i + 1 << ": " << *bookList[i];
		}
	}
};