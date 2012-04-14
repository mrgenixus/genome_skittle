#ifndef SKITTLE_SYMBOL
#define SKITTLE_SYMBOL

#include <stdlib.h>
#include <vector>
#include <map>

namespace skittle {
	
	using namespace std; 
	
	template <class T> class symbol{
		
	private: 
		static map<T,int> my_values;
		static bool read_only;
		
		static int add_value(T value){
			if ( ! is_locked() ){
				if(my_values.find(value) == my_values.end()){
					my_values[value] = (my_values.size());
				}
			}
			return my_values[value];
		};
		
	protected:
		static void lock(){
			read_only = true;
		}
		static void unlock(){
			read_only = false;
		}
		
	public:

		symbol() {} //: read_only(false){}
			
		
		int operator()(T value){
			return add_value(value);
		}
		
		static vector<T> get_values(){
			
			typename map<T,int>::iterator iter;
			vector<T> out;
			
			for(iter = my_values.begin(); iter != my_values.end(); iter++)
				out.push_back((*iter).first);
				
			return out;
		};
		
		static int symBy(T value){
			int symbol = 0;
			typename map<T,int>::iterator iter = my_values.find(value);
			if ( iter != my_values.end()) symbol = (*iter).second;

			return symbol;
		};
		
		static vector<T> syms(int sym){
			vector<T> value;
			typename map<T,int>::iterator it = my_values.begin()+sym - 1;
			
			if (it != my_values.end()) value.push_back( (*it).first );
			
			return value;
		}

		static bool is_locked(){
			return read_only;
		}
		static void assign(T value, int sym){
			add_value(value);
			if(! is_locked()) my_values[value] = sym;
		}
	};
	
	template <class T> map<T,int> symbol<T> ::my_values;
	template <class T> bool symbol<T>::read_only = false;
}

#endif