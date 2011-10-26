#ifndef SKITTLE_RENDERER
#define SKITTLE_RENDERER

#include <vector>
#include "Color.h"

namespace skittle {
	
	using namespace std;
	class Interpreter;

	class Renderer {		
	
	private:
		typedef vector<Interpreter*> interpreters;
		interpreters colors_;
		
	protected:     
		
		int width_;
		int height_;
		bool enableTextures_;
		virtual bool refresh();
		virtual int draw() = 0;
		Interpreter* current_;

	public:
		//initialization;
		Renderer(Interpreter* );
		
		bool push_back(Interpreter* );
		void pop_back();
		
		//information
		bool texturesEnabled(){ return enableTextures_; };
		
		//action
		bool render();
		
		static const int maxSaneWidth = 4000;
		
	};

}

#endif
