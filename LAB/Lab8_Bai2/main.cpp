#include <iostream>
#include "System.h"
#include "Playlist.h"
#include "Account.h"
#include "VipAccount.h"
#include "Song.h"
#include "VipSong.h"

using namespace std;


int main() {
	Song* normalSong1 = new Song ("A", "B", "C", "kpop", 2000, 10);
	Song* normalSong2 = new Song("B", "C", "D", "us-uk", 2000, 20);
	Song* normalSong3 = new Song("C", "D", "E", "vpop", 2000, 30);

	Song* vipSong1 = new VipSong("a", "b", "c", "vpop", 2020, 1000, 20000);
	Song* vipSong2 = new VipSong("b", "c", "d", "kpop", 2020, 2000, 100000);
	Song* vipSong3 = new VipSong("c", "d", "e", "us-uk", 2020, 3000, 50000);

	System::addSong(normalSong1);
	System::addSong(normalSong2);
	System::addSong(normalSong3);

	System::addSong(vipSong1);
	System::addSong(vipSong2);
	System::addSong(vipSong3);

	System::signUp("nghia1", "25127431", false, 0); // Tai khoan thuong
	System::signUp("nghia2", "25127431", true, 5000);	// Tai khoan vip
	System::signUp("nghia3", "2512 7431", true, 5000);	// Sai mat khau
	System::signUp("nghia4", "2512 7", true, 5000);	// Sai mat khau
	System::signUp("nghia5", "25127431", true, -1);	// Acc vip nhung montlyFee bi sai
	System::signUp("nghia2", "25127431", true, 5000);	// Trung username
	
	System::logIn("nghia1", "25127431"); // Login thanh cong
	System::logIn("nghia1", "2512743");	 // Sai mat khau
	System::logIn("nghia3", "25127431");	 // Sai username


	// tai khoan thuong
	System::getAllAccount()[0]->addSongToPlaylist("A");
	System::getAllAccount()[0]->addSongToPlaylist("B");
	System::getAllAccount()[0]->addSongToPlaylist("a");
	
	// tai khoan vip
	System::getAllAccount()[1]->addSongToPlaylist("a");
	System::getAllAccount()[1]->addSongToPlaylist("b");
	System::getAllAccount()[1]->addSongToPlaylist("A");

	// Tinh tien
	cout << "Tai khoan thuong: " << System::getAllAccount()[0]->calculatePrice() << '\n';
	cout << "Tai khoan vip: " << System::getAllAccount()[1]->calculatePrice() << "\n\n";

	System::print();
	System::displayTop5HotSong();

	cout << endl;
	cout << *System::getAllAccount()[1]->recommendSong("us-uk") << "\n";
	cout << *System::getAllAccount()[1]->recommendSong("vpop") << "\n";
	cout << *System::getAllAccount()[1]->recommendSong("kpop") << "\n";

	cout << System::getAllAccount()[1]->monthSubcribe(10000) << '\n'; // 2

	return 0;
}