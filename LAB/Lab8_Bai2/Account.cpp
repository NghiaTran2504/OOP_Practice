#include "Account.h"
#include "Song.h"

bool Account::setPassword (const string& s) {
	if (s.size() < 8) {
		return false;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ')
			return false;
	}

	this->password = s;
	return true;
}

bool Account::addSongToPlaylist(const string& name) {
	return userPlaylist.addPlaylist(name);
}

bool Account::removeSongFromPlaylist(const string& name) {
	return userPlaylist.removePlaylist(name);
}

double Account::calculatePrice() {
	double ans = 0;
	const auto& v = userPlaylist.getFavSong();
	for (int i = 0; i < v.size(); ++i) {
		ans += v[i]->getPrice();
	}
	return ans;
}