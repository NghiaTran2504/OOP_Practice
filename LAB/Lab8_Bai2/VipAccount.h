#pragma once
#include "Account.h"

class VipAccount : public Account {
private:
	double monthlyFee = 0;
public:
	VipAccount() = default;
	~VipAccount() = default;

	double calculatePrice() override;
	int monthSubcribe(int n) override;
	
	bool setMonthlyFee(double p) override {
		if (p < 0) return false;
		monthlyFee = p;
		return true;
	}
	double getMonthlyFee() const override { return monthlyFee; }

	void print(ostream& out) const override {
		Account::print(out);
		out << "Montly Fee: " << monthlyFee << "\n";
	}

	Song* recommendSong(const string& _genre);
};