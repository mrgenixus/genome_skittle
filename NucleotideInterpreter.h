#ifndef SKITTLE_NUCLEOTIDE_INTERPRETER
#define SKITTLE_NUCLEOTIDE_INTERPRETER

#include <stdlib.h>
#include "Interpreter.h"

namespace skittle {
	
	using namespace std; 
	class NucleotideInterpreter : public Interpreter {
		
	public:
		NucleotideInterpreter(string *seq, int width, int start, int scale, int display_size)
			:Interpreter::Interpreter(seq,width,start,scale,display_size)
		{
			
		}
	};
}

#endif