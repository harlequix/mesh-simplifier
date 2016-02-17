#include "Vertex.h"
#include "Edge.h"
#include "FileReader.h"
#include <iostream>
#include <queue>
#include <sstream>
#include <functional>
/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/08/2016 03:00:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
int main(int argc, char *argv[]){
	FileReader reader;
	Graphicobject object=reader.readFile("teapot.obj");
	Graphicobject foo = object;
	for (Vertex* i : object.vertex_list) {
	}
	for (Triangle* i : object.triangle_list) {
	}
	foo.simplify();
	for (Vertex* i : object.vertex_list) {
	}
	for (Triangle* i : foo.triangle_list) {
	}

	foo.simplifytil(500);
	foo.show();
	return 0;
}
