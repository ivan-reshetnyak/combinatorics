#pragma once

#include <iostream>

namespace combin {

class number {
private:
  using uint = unsigned int;
  uint Value;
  friend std::istream & operator>>( std::istream &, number & );
  friend std::ostream & operator<<( std::ostream &, const number & );

public:
  number() = default;
  number( uint Val ) : Value( Val ) {}

  explicit operator uint( void ) const;
  number & operator=( const number &RV );
  number operator+( const number &RV ) const;
  number & operator+=( const number &RV );
  number operator-( const number &RV ) const;
  number & operator-=( const number &RV );
  number operator*( const number &RV ) const;
  number & operator*=( const number &RV );
  number operator/( const number &RV ) const;
  number & operator/=( const number &RV );
  number operator++( int );
  number & operator++( void );
  number operator--( int );
  number & operator--( void );

  bool operator==( const number &RV ) const;
  bool operator>( const number &RV ) const;
  bool operator>=( const number &RV ) const;
  bool operator<( const number &RV ) const;
  bool operator<=( const number &RV ) const;

  number pow( number Pow ) const;
};

std::istream & operator>>( std::istream &Stream, number &Num );
std::ostream & operator<<( std::ostream &Stream, const number &Num );

} // End of 'combin' namespace
