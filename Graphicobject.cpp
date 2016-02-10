#include "Graphicobject.h"
#include <algorithm>
#include <assert.h>

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
int Graphicobject::simplifytil(int num_tris) {
	while(this->triangle_list.size()>num_tris){
		simplify();
	}
}
void Graphicobject::collapse(Vertex* from, Vertex* to) {
	for (Triangle* trie : from->tr_list) {
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
	}
}
void Graphicobject::simplify() {
	std::vector<Edge> edges;
	for (Triangle* tr : triangle_list) {
		AddUnique(edges, Edge(tr->vert1, tr->vert2));
		AddUnique(edges, Edge(tr->vert2, tr->vert3));
		AddUnique(edges, Edge(tr->vert3, tr->vert1));
	}
	for (Edge e : edges) {
		this->cost_queue.push(PriorityItem(&e, e.length()));
	}
	Edge* foo = this->cost_queue.top().content;
	while(!this->cost_queue.empty()){
		//std::cout << "Kosten: " << cost_queue.top().cost << this->cost_queue.top().content->toString() << std::endl;
		this->cost_queue.pop();
	}
	collapse(foo->vert1, foo->vert2);
}
/*void Graphicobject::generate() {
	for (Triangle* i : this->triangle_list) {
		if(containsEdge(i->v1, i->v2, this->edge_list))
	}
}*/

void Graphicobject::show() {
  int vertex_cnt=0;
  int face_cnt=0;
  std::ofstream outfile("collapse.obj");
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
  std::cout << "collapse.obj created with "<< vertex_cnt <<" vertices and " << face_cnt <<" faces" << std::endl;
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
