#include "myStringVIP.hpp";

int main()
{
	MyStringVip str1, str2, str3;
	std::cout << "Nhap chuoi 1: "; std::cin >> str1;
	std::cout << "Nhap chuoi 2: "; std::cin >> str2;
	str3 = str1;
	if (str3 == str2) std::cout << "Chuoi 2 bang chuoi 1\n";
	else if (str3 != str2) {
		if (str3 < str2) std::cout << "Chuoi 2 lon hon chuoi 1 \n";
		else if (str3 > str2) std::cout << "Chuoi 2 nho hon chuoi 1 \n";
	}

	int n;
	std::cout << "Nhap so n: "; std::cin >> n;
	str3.set(n);
	std::cout << "Chuoi 3 sau khi set(" << n << "): " << str3 << "\n";
	std::cout << "Nhap chuoi c: ";
	char* c = new char[1000];
	std::cin >> std::ws;
	std::cin.getline(c, 1000);
	str3.set(c);
	std::cout << "Chuoi 3 sau khi set(" << c << "): " << str3 << "\n";
	MyStringVip kq = "T" + str1 + str2 + " " + str3;
	std::cout << "Ket qua: " << kq;
	
	return 0;
}