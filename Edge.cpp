#include "Edge.h"
#include <algorithm>
#include <iostream>
//#define NULL 0
template<class T> int   Contains(const std::vector<T> & c, const T & t){ return std::count(begin(c), end(c), t); }
template<class T> int   IndexOf(const std::vector<T> & c, const T & v) { return std::find(begin(c), end(c), v) - begin(c); } // Note: Not presently called
template<class T> T &   Add(std::vector<T> & c, T t){ c.push_back(t); return c.back(); }
template<class T> T     Pop(std::vector<T> & c){ auto val = std::move(c.back()); c.pop_back(); return val; }
template<class T> void  AddUnique(std::vector<T> & c, T t){ if (!Contains(c, t)) c.push_back(t); }
template<class T> void  Remove(std::vector<T> & c, T t){ auto it = std::find(begin(c), end(c), t); assert(it != end(c)); c.erase(it); assert(!Contains(c, t)); }


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

Edge::Edge(Vertex* vert1, Vertex* vert2):currentID(id++){
	this->vert1 = vert1;
	this->vert2 = vert2;
	//this->tri1 = NULL;
	//this->tri2 = NULL;
	vert1->addEdge(this);
	vert2->addEdge(this);
}
Edge::~Edge(){
}
bool Edge::replace(Vertex* old_vert, Vertex* new_vert) {
	if(this->vert1 == old_vert){
		this->vert1 = new_vert;
		return true;
	}
	if (this->vert2 == old_vert) {
		this->vert2 = new_vert;
		return true;
	}
	return false;
}

bool Edge::isIn(Vertex* q) {
	if(this->vert1 == q || this->vert2 ==q){
		return true;
	}
	else{
		return false;
	}
}
double Edge::cost(Vertex* vert, Vertex* vert2){
	//double min1 = 10000;
	//double min2 = 10000;
	std::vector<double> mins;
	std::vector<Triangle*> uv;
	for (Triangle* i : vert->tr_list) {
		if(Contains(vert2->tr_list, i)){
			Add(uv, i);
		}
	}
	double max = 10000000000000;
	for(Triangle* u : uv){
		double min = 100000;
		for (Triangle* trie : vert->tr_list) {
			//double skalarprod = (1-tri1->normX)*trie->normX + (1-tri1->normY)*trie->normY + (1-tri1->normZ)*trie->normZ;
			double skalarprod = u->normX*trie->normX + u->normY*trie->normY * u->normZ*trie->normZ;
			skalarprod = (1-skalarprod)/2;
			if(min > skalarprod){
				min = skalarprod;
			}
		}
		mins.push_back(min);
	}
	if(mins.size() > 0){
		max = *std::max_element(mins.begin(), mins.end());
	}
	return max * length();
}
double Edge::length() {
	return sqrt(pow(this->vert2->x - this->vert1->x, 2)+ pow(this->vert2->y - this->vert1->y,2) + pow(this->vert2->z - this->vert1->z, 2));
}
bool Edge::setTriangle(Triangle* tri) {
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
}
std::string Edge::toString() {
	std::string ret = "Edge" + std::to_string(this->currentID) + "\n";
	if(tri1 != NULL){
		ret += tri1->toString() + "\n";
	}
	if(tri2 != NULL){
		ret += tri2->toString() + "\n";
	}
	return ret;
}
bool operator==(Edge r, Edge l){
	return (r.vert1->currentID == l.vert1->currentID && r.vert2->currentID == l.vert2->currentID);
}
int Edge::id = 1;
