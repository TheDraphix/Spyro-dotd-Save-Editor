#include <tuple>
#include <cstring>

#include "uuid.hpp"
using namespace uuid;

std::tuple<spawn::Chapter, int> spawn::MatchUUID(UUID id)
{ // returns chapter and location of uuid. TODO: include error handling
	using namespace spawn;
	
	for (int chapter=0; chapter<NUMBER_OF_CHAPTERS; chapter++)
		for (int location=0; location<number_of_locations[chapter]; location++)
			if ( memcmp(id,spawn_point[chapter][location],4) == 0 )
				return std::make_tuple(static_cast<Chapter>(chapter), location);
}
