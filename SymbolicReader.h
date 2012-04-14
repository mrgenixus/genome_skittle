#ifndef SKITTLE_SYMBOLIC_READER
#define SKITTLE_SYMBOLIC_READER

#include <stdlib.h>
#include "Reader.h"
#include "symbol.h"

namespace skittle {
	using namespace std;
	
	class SymbolicReader : public Reader {
	
	public:
		SymbolicReader(string filename);
		SymbolicReader operator>> (vector<int>&);
	private:
		symbol<char> s;
	};
}

#endif