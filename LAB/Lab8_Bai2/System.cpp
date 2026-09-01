#include "System.h"
#include "Song.h"
#include "Account.h"
#include "VipAccount.h"
#include <algorithm>

vector<Song*> System::allSong;
vector<Account*> System::allAccount;

Song* System::findSong(string s) {
	for (int i = 0; i < allSong.size(); ++i) {
		if (allSong[i]->getName() == s)
			return allSong[i];
	}
	return nullptr;
}

void System::displayTop5HotSong() {
	if (allSong.empty()) {
		cout << "No songs available.\n";
		return;
	}
	vector <Song*> tmp = allSong;
	sort(tmp.begin(), tmp.end(), [](const Song* a, const Song* b) {
		return a->getStream() > b->getStream();
		});

	cout << "\n---TOP 5 HOT SONGS ---\n";
	int limit = min(5, static_cast<int>(tmp.size()));
	for (int i = 0; i < limit;++i) {
		cout << "#" << i + 1 << ": " << *tmp[i] << "\n";
	}
}

Song* System::getTopSongByGenre(const string& _genre) {
	Song* tmp = nullptr;
	int maxx = 0;
	for (int i = 0; i < allSong.size(); ++i) {
		if (allSong[i]->getGenre() == _genre && allSong[i]->getStream() > maxx) {
			maxx = allSong[i]->getStream();
			tmp = allSong[i];
		}
	}
	return tmp;
}

bool System::signUp(const string& name, const string& pass, bool isVip, double monthlyFee) {
	// Check trung username
	for (auto account : allAccount) {
		if (name == account->getUserName()) {
			cout << "Username already existed.\n";
			return false;
		}
	}

	Account* newAcc = nullptr;
	if (isVip) {
		VipAccount* vipAcc = new VipAccount();

		// Kiem tra tai khoan vip co phi hang thang khong?
		if (!vipAcc->setMonthlyFee(monthlyFee)) {
			delete vipAcc;
			return false;
		}
		newAcc = vipAcc;
	}
	else {
		newAcc = new Account();
	}

	newAcc->setUsername(name);
	if (!newAcc->setPassword(pass)) {
		cout << "Invalid. Must >= 8 characters & no spaces.\n";
		return false;
	}

	allAccount.push_back(newAcc);
	cout << "Sign up sucessfully!\n";
	return true;
}

Account* System::logIn(const string& name, const string& pass) {
	for (auto* acc : allAccount) {
		if (acc->getUserName() == name && acc->checkPassword(pass)) {
			cout << "Login sucessfully.\n";
			return acc;
		}
	}

	cout << "Invalid username or password.\n";
	return nullptr;
}

// ================================================

void System::print() {
	cout << "\n----- ALL SONGS ------\n";
	if (allSong.empty()) {
		cout << "\n----- EMPTY ------\n";
	}
	else {
		for (auto song : allSong) {
			cout << *song << "\n";
		}
	}

	cout << "\n----- ALL ACCOUNT ------\n";
	if (allAccount.empty()) {
		cout << "\n----- EMPTY ------\n";
	}
	else {
		for (auto acc : allAccount) {
			cout << *acc << "\n";
		}
	}
}