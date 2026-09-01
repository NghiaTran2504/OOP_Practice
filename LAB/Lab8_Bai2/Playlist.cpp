#include "Song.h"
#include "System.h"
#include "Playlist.h"

// HELPER FUNCTION
bool Playlist::addPlaylist(const string& name) {
	Song* tmp = System::findSong(name);
	if (tmp == nullptr) {
		cout << "NO SONG\n";
		return false;
	}
	else {
		favSong.push_back(tmp);
		cout << "ADDED TO PLAYLIST\n";
		return true;
	}
}
bool Playlist::removePlaylist(const string& s) {
	for (int i = 0; i < favSong.size(); ++i) {
		if (favSong[i]->getName() == s) {
			swap(favSong[i], favSong[favSong.size() - 1]);
			favSong.pop_back();
			cout << "Successfully removed.\n";
			return true;
		}
	}
	cout << "Not found song.\n";
	return false;
}
// ==========================================================

istream& operator >> (istream& in, Playlist& p) {
	cout << "Song name: ";
	string s;
	getline(in >> ws, s);
	p.addPlaylist(s);
	return in;
}

ostream& operator << (ostream& out, const Playlist& p) {
	cout << "\n----- USER PLAYLIST -----\n";
	if (p.favSong.empty()) {
		cout << "\n----- EMPTY -----\n";
	}
	else {
		for (int i = 0; i < p.favSong.size(); ++i) {
			out << *(p.favSong[i]) << "\n";
		}
	}
	return out;
}