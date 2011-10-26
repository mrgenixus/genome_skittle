#ifndef SKITTLE_READER
#define SKITTLE_READER

#include <stdlib.h>
#include <string>
#include <fstream>

namespace skittle {

	class Reader {    
		
	public:

		Reader(std::string filename);
		~Reader();
		   
		Reader& operator>>(std::string&);
		static const int BlockSize = 500000;
		
		bool eof();
		bool is_complete();
		void setComplete();
		void setIncomplete();
			
		int getProgress();
		void setProgress(int);

	protected:

		std::streamsize fileSize;
		
	private:
		
		int progress;
		bool done;
		std::ifstream wordFile;
		
	};

}

#endif
