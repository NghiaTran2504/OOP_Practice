#include "Fraction.h"

using namespace std;

int main() {
	Fraction ps1, ps2;
	cin >> ps1 >> ps2;

	cout << "===== THONG TIN PHAN SO HIEN TAI =====\n";
	cout << "PHAN SO 1: " << ps1 << "PHAN SO 2: " << ps2;

	cout << "\n===== CHECKING LAY TU SO, MAU SO =====\n";
	cout << "Tu so 1: " << ps1.getTu() << "\n";
	cout << "Mau so 1: " << ps1.getMau() << "\n";
	cout << "Tu so 2: " << ps2.getTu() << "\n";
	cout << "Mau so 2: " << ps2.getMau() << "\n";

	cout << "\n===== CHECKING PHEP GAN, COPY CONSTRUCTOR =====\n";
	Fraction ps3; 
	ps3.resetDem(3);
	ps3 = ps1;
	cout << "PHAN SO 3 = PHAN SO 1: " << ps3;
	Fraction ps4 = ps2;
	cout << "KHOI TAO PHAN SO 4 = PHAN SO 2: " << ps4;

	cout << "\n===== CHECKING LOGIC TOAN TU SO SANH =====\n";
	if (ps1 == ps2) cout << "PHAN SO 1 = PHAN SO 2\n";
	if (ps1 != ps2) cout << "PHAN SO 1 != PHAN SO 2\n";
	if (ps1 < ps2) cout << "PHAN SO 1 < PHAN SO 2\n";
	if (ps1 > ps2) cout << "PHAN SO 1 > PHAN SO 2\n";
	if (ps1 <= ps2) cout << "PHAN SO 1 <= PHAN SO 2\n";
	if (ps1 >= ps2) cout << "PHAN SO 1 >= PHAN SO 2\n";

	cout << "\n===== CHECKING CONG, TRU HAU TO/TIEN TO =====\n";
	++ps1;
	++ps2;
	cout << "===== THUC HIEN PHEP CONG TIEN TO (++FRACTION) ===== \n";
	cout << "PHAN SO 1: " << ps1 << "PHAN SO 2: " << ps2;

	cout << "===== THUC HIEN PHEP CONG HAU TO (FRACTION++) ===== \n";
	cout << "PHAN SO 1: " << ps1++ << "PHAN SO 2: " << ps2++;
	cout << "GIA TRI THUC TE HIEN TAI: \n";
	cout << "PHAN SO 1: " << ps1  << "PHAN SO 2: " << ps2;

	--ps1;
	--ps2;
	cout << "\n===== THUC HIEN PHEP TRU TIEN TO (--FRACTION) =====\n";
	cout << "PHAN SO 1: " << ps1 << "PHAN SO 2: " << ps2;

	cout << "===== THUC HIEN PHEP TRU HAU TO (FRACTION--) ===== \n";
	cout << "PHAN SO 1: " << ps1-- << "PHAN SO 2: " << ps2--;
	cout << "GIA TRI THUC TE HIEN TAI:  \n";
	cout << "PHAN SO 1: " << ps1 << "PHAN SO 2: " << ps2;

	cout << "\n===== CHECKING LOGIC TOAN TU SO HOC ===== \n";
	cout << "PHEP CONG: " << ps1 + ps2;
	cout << "PHEP TRU: " << ps1 - ps2;
	cout << "PHEP NHAN: " << ps1 * ps2;
	cout << "PHEP CHIA: " << ps1 / ps2;

	cout << "\n===== GIA TRI 2 PHAN SO SAU CUNG ====== \n";
	cout << "PHAN SO 1: " << ps1 << "PHAN SO 2: " << ps2;

}