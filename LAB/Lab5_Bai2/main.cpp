#include "MangSoNguyen.h"

using namespace std;

int main() {
	MangSoNguyen a, b;
	cout << "MANG A:\n";
	cin >> a;

	cout << "\nMANG B: \n";
	cin >> b;

	cout << "\n===== CHECKING LOGIC KHOI TAO VA GAN ======\n";
	MangSoNguyen c = a;
	cout << "Khoi tao mang C = A: " << c << "\n";
	c = b;
	cout << "Mang C = B: " << c << "\n";
	MangSoNguyen d(10);
	cout << "Khoi tao mang D voi 10 phan tu: " << d << "\n";

	cout << "\n===== CHECKING LOGIC CAC PHEP TOAN ====== \n";
	cout << "PHEP CONG 2 MANG: " << a + b << "\n";
	cout << "++A: " << ++a << "\n";
	cout << "--B: " << --b << "\n";
	cout << "A++: " << a++ << "\n";
	cout << "B--: " << b-- << "\n";

	cout << "\n===== 2 MANG HIEN TAI ======\n";
	cout << "MANG A: " << a << "\nMANG B: " << b << "\n";
	return 0;
}