#include "Vertex.h"
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>
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


template<class T> int   Contains(const std::vector<T> & c, const T & t){ return std::count(begin(c), end(c), t); }
template<class T> int   IndexOf(const std::vector<T> & c, const T & v) { return std::find(begin(c), end(c), v) - begin(c); } // Note: Not presently called
template<class T> T &   Add(std::vector<T> & c, T t){ c.push_back(t); return c.back(); }
template<class T> T     Pop(std::vector<T> & c){ auto val = std::move(c.back()); c.pop_back(); return val; }
template<class T> void  AddUnique(std::vector<T> & c, T t){ if (!Contains(c, t)) c.push_back(t); }
template<class T> void  Remove(std::vector<T> & c, T t){ auto it = std::find(begin(c), end(c), t); assert(it != end(c)); c.erase(it); assert(!Contains(c, t)); }




Vertex::Vertex(double x, double y, double z):currentID(++id){
	this->x = x;
	this->y = y;
	this->z = z;
	std::vector<Triangle* > tr_list;
	std::vector<Edge*> edge_list;
}
Vertex::~Vertex(){

}
void Vertex::removeNeighbour(Vertex* vert) {
		if(Contains(neighbour_list, vert)){
			Remove(neighbour_list, vert);
	}
}
void Vertex::removeTriangle(Triangle* trie) {
	if(Contains( tr_list, trie)){
		Remove(tr_list, trie);
	}
}
void Vertex::addNeighbour(Vertex* vert) {
	if(vert != this){
		AddUnique(neighbour_list, vert);
	}
}
bool Vertex::isConnected(Vertex* q) {
	if(q == this){
		return true;
	}
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
	std::ostringstream triangles;
	foo1 << x;
	foo2 << y;
	foo3 << z;
	edges << "Neighbour: ";
	for (Vertex* i : neighbour_list) {
		edges << std::to_string(i->currentID) + ", ";
	}
	triangles << "Triangles: ";
	for (Triangle* i : this->tr_list) {
		triangles << std::to_string(i->currentID) + ", ";
	}
	return std::to_string(this->currentID) + " (" + foo1.str() + ", " + foo2.str() + ", " + foo3.str() + ")"+ "\n\t" + edges.str() +"\n\t" + triangles.str();
}
void Vertex::addTriangle(Triangle* tri){
	AddUnique(this->tr_list,tri);
}

double operator*(Vertex l, Vertex r){
  return l.x*r.x+l.y*r.y+l.z*r.z;
}
void Vertex::addEdge(Edge* new_edge) {
	edge_list.push_back(new_edge);
}

void Vertex::setid(int id){
	this->id=id;
}
bool operator==(Vertex v, Vertex w){
	return v.currentID == w.currentID;
}
Vertex operator*(Vertex v, double s){
	Vertex vertex(v.x * s, v.y * s, v.z * s);
	return vertex;
}
int Vertex::id = 0;
