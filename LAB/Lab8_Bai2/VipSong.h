#pragma once
#include "Song.h"

class VipSong : public Song {
private:
	double price = 0;
public:
	VipSong() = default;
	VipSong(string _name, string _lyric, string _singer, string _genre, int _year, int _stream, double p) : Song(_name, _lyric, _singer, _genre, _year, _stream), price(p) {}
	double getPrice() const override { return this->price; }

	void read(istream& inDev) override {
		Song::read(inDev);
		cout << "Premium price: ";
		inDev >> price;
	}

	void print(ostream& outDev) const override {
		Song::print(outDev);
		outDev << " | Price: " << getPrice();
	}
};