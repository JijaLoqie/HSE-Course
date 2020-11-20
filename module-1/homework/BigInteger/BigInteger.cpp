#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "BigInteger.h"

BigInteger::BigInteger() {}
BigInteger::BigInteger(int x) {
        if (x < 0)
        {
            minus = true;
            x = -x;
        } else minus = false;
        do {
                nums.push_back(x % MOD);
                x /= MOD;
        } while (x != 0);
}
std::ostream& operator <<(std::ostream& os, const BigInteger& a) {
        if (a.nums.empty()) os << 0;
        else {
                if (a.minus) os << '-';
                os << a.nums.back();

                for (size_t i = 0; i < a.nums.size(); i++) {
                        os << a.nums[i];
                }
        }
 
        return os;
}
void BigInteger::del_zeros() {
        while (nums.size() > 1 && nums.back() == 0) {
                nums.pop_back();
        }
        if (nums.size() == 1 && nums[0] == 0) minus = false;
}

std::string BigInteger::toString() const {
        std::stringstream ss;
        ss << *this;
        return ss.str();
}
const BigInteger BigInteger::operator-() const {
        BigInteger copy(*this);
        copy.minus = !(copy.minus);
        return copy;
}
const BigInteger operator+(BigInteger a, const BigInteger& b) {
        if (a.minus) {
                if (b.minus) return -(-a + (-b));
                else return b - (-a);
        }
        else if (b.minus) return a - (-b);
        int ost = 0;
        for (size_t i = 0; i < std::max(a.nums.size(), b.nums.size()) || ost != 0; ++i) {
                if (i == a.nums.size()) a.nums.push_back(0);
                a.nums[i] += ost + (i < b.nums.size() ? b.nums[i] : 0);
                ost = a.nums[i] >= BigInteger::MOD;
                if (ost != 0) a.nums[i] -= BigInteger::MOD;
        }
 
        return a;
}
BigInteger& BigInteger::operator+=(const BigInteger& value) {
        return *this = (*this + value);
}

BigInteger& BigInteger::operator-=(const BigInteger& value) {
        return *this = (*this - value);
}
const BigInteger BigInteger::operator++() {
        return (*this += 1);
}

const BigInteger BigInteger::operator ++(int) {
	*this += 1;
	return *this - 1;
}

const BigInteger BigInteger::operator --() {
	return *this -= 1;
}

const BigInteger BigInteger::operator --(int) {
	*this -= 1;
	return *this + 1;
}
const BigInteger operator-(BigInteger a, const BigInteger& b) {
        if (b.minus) return a + (-b);
        else if (a.minus) return -(-a + b);
        else if (a < b) return -(b - a);
        int ost = 0;
        for (size_t i = 0; i < b.nums.size() || ost != 0; ++i) {
                a.nums[i] -= ost + (i < b.nums.size() ? b.nums[i] : 0);
                ost = a.nums[i] < 0;
                if (ost != 0) a.nums[i] += BigInteger::MOD;
        }
 
        a.del_zeros();
        return a;
}
const BigInteger operator*(const BigInteger& a, const BigInteger& b) {
        BigInteger result = 0;
        result.nums.resize(a.nums.size() + b.nums.size());
        for (size_t i = 0; i < a.nums.size(); ++i) {
                int ost = 0;
                for (size_t j = 0; j < b.nums.size() || ost != 0; ++j) {
                        long long cur = result.nums[i + j] +
                                a.nums[i] * 1LL * (j < b.nums.size() ? b.nums[j] : 0) + ost;
                        result.nums[i + j] = static_cast<int>(cur % BigInteger::MOD);
                        ost = static_cast<int>(cur / BigInteger::MOD);
                }
        }

        result.minus = (b.minus != a.minus);
        result.del_zeros();
        return result;
}
void BigInteger::shift() {
        if (this->nums.size() == 0) {
                this->nums.push_back(0);
                return;
        }
        this->nums.push_back(this->nums[this->nums.size() - 1]);
        for (size_t i = this->nums.size() - 2; i > 0; --i) this->nums[i] = this->nums[i - 1];
        this->nums[0] = 0;
}
const BigInteger operator/(const BigInteger& left, const BigInteger& right) {
        // на ноль делить нельзя
        if (right == 0) throw "Divide by zero";
        BigInteger b = right;
        b.minus = false;
        BigInteger result = 0, current = 0;
        result.nums.resize(left.nums.size());
        for (long long i = static_cast<long long>(left.nums.size()) - 1; i >= 0; --i) {
                current.shift();
                current.nums[0] = left.nums[i];
                current.del_zeros();
                int x = 0, l = 0, r = BigInteger::MOD;
                while (l <= r) {
                        int m = (l + r) / 2;
                        BigInteger t = b * m;
                        if (t <= current) {
                                x = m;
                                l = m + 1;
                        }
                        else r = m - 1;
                }
 
                result.nums[i] = x;
                current = current - b * x;
        }
 
        result.minus = left.minus != right.minus;
        result.del_zeros();
        return result;
}
const BigInteger operator %(const BigInteger& a, const BigInteger& b) {
        BigInteger result = a - (a / b) * b;
        if (result.minus) result += b;
        return result;
}
bool operator==(const BigInteger& a, const BigInteger& b) {
        if (a.minus != b.minus) return false;
        if (a.nums.empty()) {
                if (b.nums.empty() || (b.nums.size() == 1 && b.nums[0] == 0)) return true;
                else return false;
        }

        if (b.nums.empty()) {
                if (a.nums.size() == 1 && a.nums[0] == 0) return true;
                else return false;
        }
        if (a.nums.size() != b.nums.size()) return false;
        for (size_t i = 0; i < a.nums.size(); ++i) if (a.nums[i] != b.nums[i]) return false;
 
        return true;
}
bool operator!=(const BigInteger& a, const BigInteger& b) {
    return !(a == b);
}
bool operator<(const BigInteger& a, const BigInteger& b) {
        if (a == b) return false;
        if (a.minus) {
                if (b.minus) return ((-b) < (-a));
                else return true;
        }
        else if (b.minus) return false;
        else {
                if (a.nums.size() != b.nums.size()) {
                        return a.nums.size() < b.nums.size();
                }
                else {
                        for (long long i = a.nums.size() - 1; i >= 0; --i) {
                                if (a.nums[i] != b.nums[i]) return a.nums[i] < b.nums[i];
                        }
                       
                        return false;
                }
        }
}
bool operator<=(const BigInteger& a, const BigInteger& b) {
        return (a < b || a == b);
}

bool operator>(const BigInteger& a, const BigInteger& b) {
        return !(a <= b);
}
 
bool operator>=(const BigInteger& a, const BigInteger& b) {
        return !(a < b);
}

int main() {
        BigInteger p = 1;

        
}