#pragma once

namespace combin {

class number {
private:
  using uint = unsigned int;
  uint Value;

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

} // End of 'combin' namespace
