#include <exception>

#include "number.h"

namespace combin {

number::operator uint( void ) const {
  return Value;
}

number & number::operator=( const number &RV ) {
  Value = RV.Value;
  return *this;
}

bool number::operator==( const number &RV ) const {
  return Value == RV.Value;
}

bool number::operator>( const number &RV ) const {
  return Value > RV.Value;
}

bool number::operator>=( const number &RV ) const  {
  return Value >= RV.Value;
}

bool number::operator<( const number &RV ) const  {
  return Value < RV.Value;
}

bool number::operator<=( const number &RV ) const  {
  return Value <= RV.Value;
}

number number::operator+( const number &RV ) const {
  uint Val = Value + RV.Value;
  if (Val < Value || Val < RV.Value)
    throw std::exception("UINT 32 overflow on addition!");

  return number(Val);
}

number & number::operator+=( const number &RV ) {
  uint Val = Value + RV.Value;
  if (Val < Value || Val < RV.Value)
    throw std::exception("UINT 32 overflow on addition!");

  Value = Val;
  return *this;
}

number number::operator-( const number &RV ) const {
  uint Val = Value - RV.Value;
  if (Val > Value)
    throw std::exception("UINT 32 overflow on subtraction!");

  return number(Val);
}

number & number::operator-=( const number &RV ) {
  uint Val = Value - RV.Value;
  if (Val > Value)
    throw std::exception("UINT 32 overflow on subtraction!");

  Value = Val;
  return *this;
}

number number::operator*( const number &RV ) const {
  uint Val = Value * RV.Value;
  if (RV.Value != 0 && Val / RV.Value != Value)
    throw std::exception("UINT 32 overflow on multiplication!");

  return number(Val);
}

number & number::operator*=( const number &RV ) {
  uint Val = Value * RV.Value;
  if (RV.Value != 0 && Val / RV.Value != Value)
    throw std::exception("UINT 32 overflow on multiplication!");

  Value = Val;
  return *this;
}

number number::operator/( const number &RV ) const {
  if (RV.Value == 0)
    throw std::exception("Division by zero!");

  return number(Value / RV.Value);
}

number & number::operator/=( const number &RV ) {
  if (RV.Value == 0)
    throw std::exception("Division by zero!");

  Value /= RV.Value;
  return *this;
}

number number::operator++( int ) {
  number Res = *this;
  Value++;
  return Res;
}

number & number::operator++( void ) {
  Value++;
  return *this;
}

number number::operator--( int ) {
  number Res = *this;
  Value--;
  return Res;
}

number & number::operator--( void ) {
  Value--;
  return *this;
}

number number::pow( number Pow ) const {
  number Res = 1;

  for (number i = 0; i < Pow; i++)
    Res *= *this;
  return Res;
}

std::istream & operator>>( std::istream &Stream, number &Num ) {
  Stream >> Num.Value;
  return Stream;
}

std::ostream & operator<<( std::ostream &Stream, const number &Num ) {
  Stream << Num.Value;
  return Stream;
}

} // End of 'combin' namespace
