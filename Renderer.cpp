#include "Renderer.h"
#include "Interpreter.h"
#include "Color.h"
#include <QtOpenGL/QGLWidget>
#include <stdlib.h>

using namespace std;
using namespace skittle;

// main constructor
// should be called if your glWidget supports textures
/**
 * Renderer should setup a graph based on a colorlist and some other 
 * details.  We're kindof going to assume everyone else has either done 
 * their job or can live with the consequences.
 * 
 * 
 **/

Renderer::Renderer(Interpreter* abstractGraph){
	colors_ = interpreters();
    enableTextures_ = false;
    push_back(abstractGraph);
}

bool Renderer::push_back(Interpreter* abstractGraph){
	interpreters::iterator iter;
	bool replaced = false; 
	for ( iter=colors_.begin() ; iter < colors_.end(); iter++) {
		if( *iter == abstractGraph ) {
			colors_.erase(iter);
			replaced = true;
		}
	}
    colors_.push_back(abstractGraph);
    
    return replaced;
}

void Renderer::pop_back(){
	return colors_.pop_back();
}

bool Renderer::refresh(){
    return false;
}

bool Renderer::render(){
	interpreters::iterator iter;
	for ( iter=colors_.begin() ; iter < colors_.end(); iter++) {
		current_ = *iter;
		refresh();
		draw();
	}
    return true;
}
