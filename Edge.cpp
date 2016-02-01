#include "Edge.h"
#define NULL 0
/*
 * =====================================================================================
 *
 *       Filename:  Edge.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/01/2016 10:49:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

Edge::Edge(Vertex* vert1, Vertex* vert2){
	this->vert1 = vert1;
	this->vert2 = vert2;
	//this->tri1 = NULL;
	//this->tri2 = NULL;
}
Edge::~Edge(){
}
/*bool Edge::setTriangle(Triangle* tri) {
	if (this->tri1 == NULL) {
		this->tri1 = tri;
		return true;
	}
	if(this->tri2 == NULL){
		this->tri2 = tri;
		return true;
	}
	else{
		return false;
	}
}*/
