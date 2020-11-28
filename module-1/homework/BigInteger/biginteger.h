#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H
#pragma once
#include <vector>
#include <string>
#include <iostream>

void my_reverse(std::string &);

class BigInteger
{
private:
  static const int MOD = 1000000000;
  std::vector<int> _digits;
  bool minus;

  void remove_leading_zeros();
  void shift_left();
  bool abs_low(const BigInteger &);
  void abs_add(const BigInteger &);
  void abs_dif(const BigInteger &, bool);

public:
  std::string toString() const;
  BigInteger();
  BigInteger(int);
  explicit BigInteger(std::string);

  operator bool() const;
  BigInteger operator-() const;
  friend bool operator<(const BigInteger &, const BigInteger &);
  BigInteger &operator+=(const BigInteger &);
  BigInteger &operator-=(const BigInteger &);
  BigInteger &operator*=(const BigInteger &);
  BigInteger &operator/=(const BigInteger &);
  BigInteger &operator%=(const BigInteger &);
  friend const BigInteger operator*(const BigInteger &, const BigInteger &);
  friend BigInteger operator/(const BigInteger &, const BigInteger &);
  friend const BigInteger operator%(const BigInteger &, const BigInteger &);
  BigInteger &operator++();
  BigInteger &operator--();
  BigInteger operator++(int);
  BigInteger operator--(int);
};

BigInteger operator+(const BigInteger &, const BigInteger &);
BigInteger operator-(const BigInteger &, const BigInteger &);

std::ostream &operator<<(std::ostream &, const BigInteger &);
std::istream &operator>>(std::istream &, BigInteger &);

bool operator>=(const BigInteger &, const BigInteger &);
bool operator>(const BigInteger &, const BigInteger &);
bool operator<=(const BigInteger &, const BigInteger &);
bool operator!=(const BigInteger &, const BigInteger &);
bool operator==(const BigInteger &, const BigInteger &);

#endif