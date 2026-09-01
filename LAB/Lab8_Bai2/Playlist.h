#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Song;
class System;

class Playlist {
private:
	vector <Song*> favSong;
public:
	Playlist() = default;
	~Playlist() {
		favSong.clear();
	}

	bool addPlaylist(const string& name);
	bool removePlaylist(const string& name);
	const vector<Song*>& getFavSong() const { return favSong; }

	friend istream& operator >> (istream& in, Playlist& p);
	friend ostream& operator << (ostream& out, const Playlist& p);
};