#include "VipAccount.h"
#include "Song.h"
#include "System.h"

double VipAccount::calculatePrice() {
	double ans = 0;
	auto v = userPlaylist.getFavSong();
	for (int i = 0; i < v.size(); ++i) {
		ans += 0.5 * v[i]->getPrice();
	}

	return ans;
}

int VipAccount::monthSubcribe(int n) {
	if (monthlyFee <= 0) return 0;
	return n / monthlyFee;
}

Song* VipAccount::recommendSong(const string& _genre) {
	return System::getTopSongByGenre(_genre);
}