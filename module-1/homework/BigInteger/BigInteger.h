#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <vector>
#include <string>
#include <ostream>

void my_reverse(std::string&);

class BigInteger {
  static const int MOD = 1000000000;
  std::vector<int> nums;
  bool minus;

  void remove_zeros();
  void shift_left();
  bool _abs_low(const BigInteger&);
  void _abs_add(const BigInteger&);
  void _abs_dif(const BigInteger&, bool);
  std::string _to_str() const;

 public:
  BigInteger();
  BigInteger(int32_t);
  explicit BigInteger(std::string);

  operator bool() const;
  std::string toString() const;
  BigInteger operator-() const;
  friend bool operator<(const BigInteger&, const BigInteger&);
  BigInteger& operator+=(const BigInteger&);
  BigInteger& operator-=(const BigInteger&);
  BigInteger& operator*=(const BigInteger&);
  BigInteger& operator/=(const BigInteger&);
  BigInteger& operator%=(const BigInteger&);
  friend const BigInteger operator*(const BigInteger&, const BigInteger&);
  friend BigInteger operator/(const BigInteger&, const BigInteger&);
  friend const BigInteger operator%(const BigInteger&, const BigInteger&);
  BigInteger& operator++();
  BigInteger& operator--();
  BigInteger operator++(int);
  BigInteger operator--(int);
};

BigInteger operator+(const BigInteger&, const BigInteger&);
BigInteger operator-(const BigInteger&, const BigInteger&);

std::ostream& operator<<(std::ostream&, const BigInteger&);
std::istream& operator>>(std::istream&, BigInteger&);

bool operator>=(const BigInteger&, const BigInteger&);
bool operator>(const BigInteger&, const BigInteger&);
bool operator<=(const BigInteger&, const BigInteger&);
bool operator!=(const BigInteger&, const BigInteger&);
bool operator==(const BigInteger&, const BigInteger&);

#endif