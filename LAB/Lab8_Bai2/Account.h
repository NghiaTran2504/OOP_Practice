#pragma once

#include <iostream>
#include <string>
#include "Playlist.h"
using namespace std;


class Account {
protected:
	string username, password;
	Playlist userPlaylist;
public:
	Account() = default;
	virtual ~Account() = default;

	string getUserName() const { return this->username; }
	bool checkPassword(const string& p) { return p == password; }
	void setUsername(const string& s) { username = s; }
	bool setPassword(const string& s);
	virtual bool setMonthlyFee(double p) { return true; }
	virtual double getMonthlyFee() const { return 0; }

	bool addSongToPlaylist(const string& name);
	bool removeSongFromPlaylist(const string& name);

	virtual double calculatePrice();
	virtual int monthSubcribe(int n) { return -1; }
	virtual Song* recommendSong(const string& _genre) { return nullptr; }

	virtual void print(ostream& out) const {
		out << "Username: " << username << " |  Password: " << password << "\n";
		out << userPlaylist << "\n";
	}

	friend ostream& operator << (ostream& out, const Account& acc) {
		acc.print(out);
		return out;
	}
};