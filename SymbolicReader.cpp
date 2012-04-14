#include "SymbolicReader.h"
#include <string>

using namespace skittle;

SymbolicReader::SymbolicReader(string filename) : Reader(filename){
	s('A');
	s('C');
	s('T');
	s('G');
}

SymbolicReader SymbolicReader::operator>> (vector<int>& cont){
	string mystring;
	*this >> mystring;
	string::iterator it;
	for (it = string.begin(); it != string.end(); it++)
		cont.push_back(s.symBy(*it));
	return *this;
}