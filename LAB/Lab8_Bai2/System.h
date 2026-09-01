#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Song;
class Account;
class System {
private:
	static vector <Song*> allSong;
	static vector <Account*> allAccount;
public:
	System() = default;
	~System() {
		for (int i = 0; i < allSong.size(); ++i) {
			delete allSong[i];
		}

		for (int i = 0; i < allAccount.size(); ++i) {
			delete allAccount[i];
		}
		allAccount.clear();
		allSong.clear();
	}
	
	static vector <Song*>& getAllSong() { return allSong; }
	static vector <Account*>& getAllAccount() { return allAccount; }

	static Song* findSong(string s);
	static void addSong(Song* s) {
		if (s == nullptr) return;
		allSong.push_back(s);
	}

	// Top song
	static void displayTop5HotSong();
	static Song* getTopSongByGenre(const string& _genre);

	// Sign up & Log in
	static bool signUp(const string& name, const string& pass, bool isVip, double monthlyFee);
	static Account* logIn(const string& name, const string& pass);

	static void print();
};