#pragma once
#include <vector>
#include <string>
#include <sstream>
class BigInteger {
public:
    BigInteger(int x);
	static const int MOD = 1000000000;
    void del_zeros() {};
    std::string toString() const {};
	// внутреннее хранилище числа
	std::vector<int> nums;

	// знак числа
	bool minus;
    const BigInteger operator-() const {}
    BigInteger& operator+(const int& b){}
    BigInteger& operator-(const int& b){}
    BigInteger& operator*(const int& b){}
    BigInteger& operator%(const int& b){}
    BigInteger& operator/(const int& b){}
    BigInteger& operator+=(const BigInteger& value) {}
    BigInteger& operator-=(const BigInteger& value) {}
    const BigInteger operator++() {}
    const BigInteger operator++(int) {}
    const BigInteger operator--() {}
    const BigInteger operator--(int) {}


};
BigInteger& operator+(int& a, const BigInteger& b){}
BigInteger& operator-(int& a, const BigInteger& b){}
BigInteger& operator*(int& a, const BigInteger& b){}
BigInteger& operator%(int& a, const BigInteger& b){}
BigInteger& operator/(int& a, const BigInteger& b){}
bool operator==(const BigInteger& a, const BigInteger& b){}
bool operator==(const BigInteger& a, const BigInteger& b){}
bool operator!=(const BigInteger& a, const BigInteger& b){}
bool operator!=(const int& a, const BigInteger& b){}
bool operator<(const BigInteger& a, const int& b){}
bool operator<(const BigInteger& a, const BigInteger& b) {}
bool operator>(const BigInteger& a, const int& b){}
bool operator>(const BigInteger& a, const BigInteger& b) {}
bool operator<=(const BigInteger& a, const BigInteger& b){}
bool operator<=(const BigInteger& a, const int& b){}
bool operator>=(const BigInteger& a, const int& b){}
bool operator>=(const BigInteger& a, const BigInteger& b) {}