#pragma once

#include <iostream>
#include <string>

class Fraction {
private:
    int num;
    int den;

    void reduce();

public:
    Fraction(int n = 0, int d = 1);

    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator==(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
};
