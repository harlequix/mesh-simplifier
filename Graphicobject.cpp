#include "Graphicobject.h"
#include <algorithm>
#include <assert.h>
#include <stdlib.h>

/*
 * =====================================================================================
 *
 *       Filename:  Graphicobject.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/27/2016 01:46:04 PM
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
template<class T> void  Remove(std::vector<T> & c, T t){ auto it = std::find(begin(c), end(c), t); assert(it != end(c)); c.erase(it); }


Graphicobject::Graphicobject() {

}
Graphicobject::~Graphicobject(){

}
/*bool Graphicobject::containsEdge(Vertex* v1, Vertex* v2, std::vector<Edge> check) {
	for (Edge i : check) {
		if(v1 == i->v1 && v2 == i->v2){
			return true;
		}
	}
	return false;
}*/
int Graphicobject::simplifytil(int num_tris, std::string algorithm) {
	while(this->triangle_list.size()>num_tris){
		simplify(algorithm);
	}
}
void Graphicobject::collapse(Vertex* from, Vertex* to) {
	for (Triangle* trie : from->tr_list) {
		trie->replace(from, to);
		to->addTriangle(trie);
			//from->removeTriangle(trie);
		to->addNeighbour(trie->vert1);
		to->addNeighbour(trie->vert2);
		to->addNeighbour(trie->vert3);
		trie->vert1->addNeighbour(to);
		trie->vert2->addNeighbour(to);
		trie->vert3->addNeighbour(to);
		trie->calculateNorm();

	}
	for (Vertex* i : from->neighbour_list) {
		i->removeNeighbour(from);
	}
	for (std::vector<Triangle*>::iterator it = from->tr_list.begin(); it!=from->tr_list.end();it++) {
		Triangle* trie = *it;
		if(trie->invalid()){
			trie->unregisterVertices();
			if(Contains(this->triangle_list, trie)){
			Remove(this->triangle_list, trie);
			}
		}
		else{trie->calculateNorm();}
	}

	/* for (Triangle* trie : from->tr_list) {
		if(!trie->isIn(to)){
			trie->replace(from, to);
			to->addNeighbour(trie->vert1);
			to->addNeighbour(trie->vert2);
			to->addNeighbour(trie->vert3);
			trie->vert1->addNeighbour(to);
			trie->vert2->addNeighbour(to);
			trie->vert3->addNeighbour(to);
		}
		else{
			std::cout << trie->toString() << std::endl;
			std::cout << from->toString() << std::endl;
			trie->vert1->removeNeighbour(from);
			trie->vert2->removeNeighbour(from);
			trie->vert3->removeNeighbour(from);
			from->addNeighbour(trie->vert1);
			from->addNeighbour(trie->vert2);
			from->addNeighbour(trie->vert3);
			trie->vert1->removeTriangle(trie);
			trie->vert2->removeTriangle(trie);
			trie->vert3->removeTriangle(trie);
			if(Contains(this->triangle_list, trie)){
				Remove(this->triangle_list, trie);
			}
		}
	}
	for (Vertex* neigh : from->neighbour_list) {
		neigh->removeNeighbour(from);
	}
	for (Triangle* tr : from->tr_list) {
		if(tr->isIn(from)){
			std::cerr <<"Vertex ist immer noch in Triangles vorhanden!";
		}
	}*/
}
bool myfn(const PriorityItem l, PriorityItem r){
	return l.cost < r.cost;
}
void Graphicobject::simplify(std::string algorithm) {
	std::vector<Edge> edges;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(1, 100);
	for (Triangle* tr : triangle_list) {
		Edge e1(tr->vert1, tr->vert2);
		Edge e2(tr->vert2, tr->vert3);
		Edge e3(tr->vert3, tr->vert1);
		if(tr->invalid()){
			Remove(triangle_list, tr);
		}
		else{
		if(e1.length() > 0){
			AddUnique(edges, e1);
		}
		if(e2.length() > 0){
			AddUnique(edges, e2);
		}
		if(e3.length() > 0){
			AddUnique(edges, e3);
		}}
		/*AddUnique(edges, Edge(tr->vert1, tr->vert2));
		AddUnique(edges, Edge(tr->vert2, tr->vert3));
		AddUnique(edges, Edge(tr->vert3, tr->vert1));*/
	}
	std::vector<PriorityItem> priority_queue;
	if(algorithm.compare("--simple") == 0){
		for (Edge e : edges) {
			priority_queue.push_back(PriorityItem(e, e.cost(e.vert1, e.vert2)));
			priority_queue.push_back(PriorityItem(e, e.cost(e.vert2, e.vert1)));
		}
	}
	else if(algorithm.compare("--random") == 0){
		for (Edge e : edges) {
			priority_queue.push_back(PriorityItem(e,1 + (rand() % (int)(100 - 1 + 1)) ));
		}
	}
	else if(algorithm.compare("--length") == 0){
		for (Edge e : edges) {
			priority_queue.push_back(PriorityItem(e,e.cost(e.vert1, e.vert2) ));
		}
	}
	PriorityItem foo1 = *std::min_element(priority_queue.begin(), priority_queue.end(), myfn);
		static int counter = 0;
	for (Triangle* i : triangle_list) {
		assert(("Counter " + std::to_string(counter),!i->invalid()));
	}
	collapse(foo1.content.vert1, foo1.content.vert2);
	counter++;
}

void Graphicobject::show(std::string output) {
  int vertex_cnt=0;
  int face_cnt=0;
  std::ofstream outfile(output);
  for(Vertex* vertex : vertex_list){
    outfile << "v " << vertex->x << " " << vertex->y << " " << vertex->z << std::endl;
    vertex_cnt++;
  }
    outfile << std::endl;

  for(Triangle* triangle : triangle_list){
      if(triangle != NULL){
      outfile << "f " << IndexOf(this->vertex_list,triangle->vert1)+1 << " " << IndexOf(this->vertex_list, triangle->vert2)+1 << " " << IndexOf(this->vertex_list,triangle->vert3)+1 << std::endl;
      face_cnt++;
    }
  }
  outfile.close();
  std::cout << output  << " created with "<< vertex_cnt <<" vertices and " << face_cnt <<" faces" << std::endl;
  return;
}
void Graphicobject::addEdge(Edge* new_edge) {
	//edge_list.push_back(*new_edge);
}
void Graphicobject::addVertex(Vertex* new_Vertex) {
	vertex_list.push_back(new_Vertex);
}
void Graphicobject::addTriangle(Triangle* new_triangle) {
	triangle_list.push_back(new_triangle);
}
