#include "Song.h"

void Song::read(istream& in) {
	cout << "Name song: ";
	getline(in >> ws, this->name);
	cout << "Lyric: ";
	getline(in >> ws, this->lyric);
	cout << "Singer: ";
	getline(in >> ws, this->singer);
	cout << "Genre (vpop/us-uk/kpop): ";
	getline(in >> ws, this->genre);
	cout << "Year publish: ";
	in >> this->yearPublish;
	cout << "Current streams: ";
	in >> this->currStream;
}

void Song::print(ostream& out) const{
	out << "Song name: " << this->name << " | Lyric: " << this->lyric << " | Genre: " << this->genre << " | Singer: " << this->singer  << " | Year publish: " << this->yearPublish
		<< " | Current stream: " << this->currStream;
}