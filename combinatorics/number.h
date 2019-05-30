#pragma once

namespace combin {

class number {
private:
  using uint = unsigned int;
  uint Value;

public:
  number() = default;
  number( uint Val ) : Value( Val ) {}

  operator uint( void ) const;
  number & operator=( const number &RV );
  bool operator==( const number &RV ) const;
  number operator+( const number &RV ) const;
  number & operator+=( const number &RV );
  number operator-( const number &RV ) const;
  number & operator-=( const number &RV );
  number operator*( const number &RV ) const;
  number & operator*=( const number &RV );
  number operator/( const number &RV ) const;
  number & operator/=( const number &RV );
};

} // End of 'combin' namespace
