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
	std::vector<Edge*> edge_list;
}
Vertex::~Vertex(){

}
bool Vertex::isConnected(Vertex* q) {
	for (Edge* i : edge_list) {
		if(i->isIn(q) == true){
			return true;
		}
	}
	return false;
}
std::string Vertex::toString() {
	std::ostringstream foo1;
	std::ostringstream foo2;
	std::ostringstream foo3;
	std::ostringstream edges;
	foo1 << x;
	foo2 << y;
	foo3 << z;
	edges << "Edge: ";
	for (Edge* i : edge_list) {
		edges << std::to_string(i->currentID) + ", ";
	}
	return "(" + foo1.str() + ", " + foo2.str() + ", " + foo3.str() + ")"+ "\n\t" + edges.str();
}
void Vertex::addTriangle(Triangle* tri){
	this->tr_list.push_back(tri);
}
void Vertex::addEdge(Edge* new_edge) {
	edge_list.push_back(new_edge);
}
