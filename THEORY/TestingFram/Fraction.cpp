#include "Fraction.h"
#include <cmath>

static int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction::Fraction(int n, int d) : num(n), den(d == 0 ? 1 : d) {
    reduce();
}

void Fraction::reduce() {
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int g = gcd(num, den);
    if (g > 0) {
        num /= g;
        den /= g;
    }
}

bool Fraction::operator<(const Fraction& other) const {
    return static_cast<long long>(num) * other.den < static_cast<long long>(other.num) * den;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

bool Fraction::operator==(const Fraction& other) const {
    return num == other.num && den == other.den;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    if (f.den == 1) {
        os << f.num;
    } else {
        os << f.num << "/" << f.den;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    std::string s;
    if (is >> s) {
        size_t pos = s.find('/');
        if (pos != std::string::npos) {
            f.num = std::stoi(s.substr(0, pos));
            f.den = std::stoi(s.substr(pos + 1));
        } else {
            f.num = std::stoi(s);
            f.den = 1;
        }
        f.reduce();
    }
    return is;
}
