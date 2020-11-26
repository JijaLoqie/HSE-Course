#include <iostream>
#include <string>
#include <vector>
#include "biginteger.h"

void my_reverse(std::string& a)
{
        size_t n = a.size();
        for (size_t i = 0; i < n / 2; ++i)
        {
                std::swap(a[i], a[n - i - 1]);
        }
}
void BigInteger::remove_leading_zeros()
{
        while (_digits.size() > 1 && _digits.back() == 0)
        {
                _digits.pop_back();
        }
        if (_digits.size() == 1 && _digits[0] == 0)
                minus = false;
}

BigInteger::BigInteger() : minus(false)
{}
BigInteger::BigInteger(std::string NewCur)
{
        if (NewCur.empty())
        {
                minus = false;
        }
        else
        {
                if (NewCur[0] == '-')
                {
                        NewCur = NewCur.substr(1);
                        minus = true;
                }
                else
                {
                        minus = false;
                }
                for (int i = NewCur.length(); i > 0; i -= 9)
                {
                        if (i < 9)
                        {
                                _digits.push_back(atoi(NewCur.substr(0, i).c_str()));
                        }
                        else
                        {
                                _digits.push_back(atoi(NewCur.substr(i - 9, 9).c_str()));
                        }
                }
                remove_leading_zeros();
        }
}
BigInteger::BigInteger(int newCur)
{
        if (newCur < 0)
        {
                minus = true;
                newCur = -newCur;
        }
        else
        {
                minus = false;
        }
        if (newCur == 0)
        {
                _digits.push_back(0);
        }
        while (newCur != 0)
        {
                _digits.push_back(newCur % BigInteger::MOD);
                newCur /= BigInteger::MOD;
        }
}
std::string BigInteger::toString() const
{
        int n = _digits.size();
        std::string result;
        if (n != 0 && !(n == 1 && _digits[0] == 0))
        {
                for (int i = 0; i + 1 < n; ++i)
                {
                        for (int j = 1; j < BigInteger::MOD; j *= 10)
                        {
                                result.push_back('0' + (_digits[i] / j % 10));
                        }
                }
                for (int i = 1; i < BigInteger::MOD; i *= 10)
                {
                        if (_digits[n - 1] / i)
                        {
                                result.push_back('0' + (_digits[n - 1] / i % 10));
                        }
                }
                if (minus)
                {
                        result.push_back('-');
                }
                my_reverse(result);
        }
        else
        {
                result = "0";
        }
        return result;
}
std::ostream& operator<<(std::ostream& out, const BigInteger& bi)
{
        out << bi.toString();
        return out;
}
std::istream& operator>>(std::istream& in, BigInteger& bi)
{
        std::string newS;
        in >> newS;
        bi = BigInteger(newS);
        return in;
}
bool operator<(const BigInteger& left, const BigInteger& right)
{
        if (left.minus != right.minus)
        {
                return left.minus;
        }
        if (left.minus)
        {
                if (left._digits.size() != right._digits.size())
                {
                        return left._digits.size() > right._digits.size();
                }
                for (int i = left._digits.size() - 1; i >= 0; --i)
                {
                        if (left._digits[i] != right._digits[i])
                        {
                                return left._digits[i] > right._digits[i];
                        }
                }
        }
        else
        {
                if (left._digits.size() != right._digits.size())
                {
                        return left._digits.size() < right._digits.size();
                }
                for (int i = left._digits.size() - 1; i >= 0; --i)
                {
                        if (left._digits[i] != right._digits[i])
                        {
                                return left._digits[i] < right._digits[i];
                        }
                }
        }
        return false;
}
bool operator!=(const BigInteger& left, const BigInteger& right)
{
        return left < right || right < left;
}

bool operator==(const BigInteger& left, const BigInteger& right)
{
        return !(left != right);
}
bool operator>(const BigInteger& left, const BigInteger& right)
{
        return right < left;
}
bool operator<=(const BigInteger& left, const BigInteger& right)
{
        return !(right < left);
}
bool operator>=(const BigInteger& left, const BigInteger& right)
{
        return !(left < right);
}
BigInteger::operator bool() const { return !_digits.empty(); }

BigInteger BigInteger::operator-() const
{
        BigInteger result(*this);
        if (result)
        {
                result.minus = !result.minus;
        }
        return result;
}
BigInteger operator+(const BigInteger& left, const BigInteger& right)
{
        BigInteger result(left);
        result += right;
        return result;
}
bool BigInteger::abs_low(const BigInteger& right)
{
        if (_digits.size() != right._digits.size())
        {
                return _digits.size() < right._digits.size();
        }
        for (std::size_t i = right._digits.size() - 1; i >= 0; --i)
        {
                if (_digits[i] != right._digits[i])
                {
                        return _digits[i] < right._digits[i];
                }
        }
        return false;
}

void BigInteger::abs_add(const BigInteger& right)
{
        int max = std::max(right._digits.size(), _digits.size());
        _digits.resize(max);
        for (int i = 0; i < right._digits.size(); ++i)
        {
                _digits[i] += right._digits[i];
                if (_digits[i] >= BigInteger::MOD)
                {
                        if (i == max - 1)
                        {
                                _digits.push_back(0);
                        }
                        _digits[i + 1] += _digits[i] / BigInteger::MOD;
                        _digits[i] %= BigInteger::MOD;
                }
        }
}

void BigInteger::abs_dif(const BigInteger& right, bool is_lower)
{
        int min = std::min(right._digits.size(), _digits.size());
        int max = std::max(right._digits.size(), _digits.size());
        _digits.resize(max);
        for (int i = 0; i < min; ++i)
        {
                _digits[i] = islower ? (right._digits[i] - _digits[i]) : (_digits[i] - right._digits[i]);
        }
        if (is_lower)
        {
                for (int i = min; i < max; ++i)
                {
                        _digits[i] = right._digits[i];
                }
        }
        for (int i = 0; i < min; ++i)
        {
                if (_digits[i] < 0)
                {
                        if (i + 1 != max)
                        {
                                _digits[i] += BigInteger::MOD;
                                _digits[i + 1]--;
                        }
                }
        }
        for (int i = min; i + 1 < max && _digits[i] < 0; ++i)
        {
                _digits[i] += BigInteger::MOD;
                _digits[i + 1]--;
        }
        remove_leading_zeros();
}

const BigInteger operator*(const BigInteger& left, const BigInteger& right)
{
        BigInteger result;
        result._digits.resize(left._digits.size() + right._digits.size() + 1);
        for (int i = 0; i < left._digits.size(); ++i)
        {
                int carry = 0;
                for (int j = 0; j < right._digits.size() || carry != 0; ++j)
                {
                        long long curr = result._digits[i + j] + carry;
                        if (j < right._digits.size())
                        {
                                curr += 1ll * left._digits[i] * right._digits[j];
                        }
                        result._digits[i + j] = curr % BigInteger::MOD;
                        carry = curr / BigInteger::MOD;
                }
        }
        result.minus = left.minus != right.minus;
        result.remove_leading_zeros();
        return result;
}

void BigInteger::shift_left()
{
        if (_digits.empty())
        {
                _digits.push_back(0);
                return;
        }
        _digits.push_back(_digits[_digits.size() - 1]);
        for (size_t i = _digits.size() - 2; i > 0; --i)
        {
                _digits[i] = _digits[i - 1];
        }
        _digits[0] = 0;
}
BigInteger& BigInteger::operator+=(const BigInteger& right)
{
        if (minus == right.minus)
        {
                abs_add(right);
        }
        else
        {
                bool is_lower = abs_low(right);
                if (is_lower)
                {
                        minus = !minus;
                }
                abs_dif(right, is_lower);
        }
        return (*this);
}
BigInteger& BigInteger::operator++() { return (*this) += BigInteger(1); }

BigInteger& BigInteger::operator--() { return (*this) -= BigInteger(1); }
BigInteger BigInteger::operator++(int)
{
        ++(*this);
        return (*this) + BigInteger(-1);
}

BigInteger BigInteger::operator--(int)
{
        --(*this);
        return (*this) + BigInteger(1);
}

BigInteger& BigInteger::operator-=(const BigInteger& right)
{
        return (*this) += (-right);
}
BigInteger operator-(const BigInteger& left, const BigInteger& right)
{
        BigInteger ans(left);
        ans -= right;
        return ans;
}

BigInteger operator/(const BigInteger& left, const BigInteger& right)
{
        BigInteger b = right;
        b.minus = false;
        BigInteger result, curr;
        result._digits.resize(left._digits.size());
        for (int i = left._digits.size() - 1; i >= 0; --i)
        {
                curr.shift_left();
                curr._digits[0] = left._digits[i];
                curr.remove_leading_zeros();
                int x = 0;
                int l = 0;
                int r = BigInteger::MOD;
                while (l <= r)
                {
                        int m = (l + r) / 2;
                        BigInteger t = b * BigInteger(m);
                        if (t <= curr)
                        {
                                x = m;
                                l = m + 1;
                        }
                        else
                        {
                                r = m - 1;
                        }
                }
                result._digits[i] = x;
                curr = curr - b * BigInteger(x);
        }
        result.minus = left.minus != right.minus;
        result.remove_leading_zeros();
        return result;
}
BigInteger& BigInteger::operator*=(const BigInteger& right)
{
        return (*this) = (*this) * right;
}
BigInteger& BigInteger::operator/=(const BigInteger& right)
{
        return (*this) = (*this) / right;
}

const BigInteger operator%(const BigInteger& left, const BigInteger& right)
{
        BigInteger result = left - (left / right) * right;
        if (result.minus)
        {
                result += right;
        }
        if (result == BigInteger(0))
                return BigInteger(0);
        return result;
}

BigInteger& BigInteger::operator%=(const BigInteger& right)
{
        return (*this) = (*this) % right;
}