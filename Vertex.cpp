#include "Vertex.h"
#include <sstream>
#include <string>
#include <vector>
/*
 * =====================================================================================
 *
 *       Filename:  Vertex.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/01/2016 10:49:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

Vertex::Vertex(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
	std::vector<Triangle* > tr_list;
}
Vertex::~Vertex(){

}
std::string Vertex::toString() {
	std::ostringstream foo1;
	std::ostringstream foo2;
	std::ostringstream foo3;
	foo1 << x;
	foo2 << y;
	foo3 << z;
	return "(" + foo1.str() + ", " + foo2.str() + ", " + foo3.str() + ")";
}
void Vertex::addTriangle(Triangle* tri){
	this->tr_list.push_back(tri);
}

double operator*(Vertex l, Vertex r){
  return l.x*r.x+l.y*r.y+l.z*r.z;
}

Vertex operator*(Vertex v, double s){
	Vertex vertex(v.x * s, v.y * s, v.z * s);
	return vertex;
}
