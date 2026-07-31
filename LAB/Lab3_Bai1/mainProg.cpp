#include "NhanVien.hpp"

int main()
{
	NhanVien a("Dat Thanh", 800);
	NhanVien b(a);
	b.SetHoTen("Hai Dang");
	for (int i = 0; i < 5; i++)
	{
		NhanVien clone = b;
		clone.SetHoTen("De tu thu " + to_string(i) + " cua "
			+ b.get_chucDanh() + " " + b.get_fullName());
	}

	return 0;
}