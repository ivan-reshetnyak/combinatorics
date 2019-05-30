#pragma once

#include "number.h"

namespace combin {

number Placements( number m, number n );
number PlacementsNoRepeats( number m, number n );
number Permutations( number n );
number Combinations( number m, number n );
number Stirling( number m, number n );
number Bell( number n );

} // End of 'combin' namespace
