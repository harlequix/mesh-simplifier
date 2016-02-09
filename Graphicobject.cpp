#include "Graphicobject.h"
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
Graphicobject::Graphicobject() {
	
}
Graphicobject::~Graphicobject(){

}
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
    outfile << "f " << triangle->vert1->id << " " << triangle->vert2->id << " " << triangle->vert3->id << std::endl;
    face_cnt++;
  }
  outfile.close();
  std::cout << "collapse.obj created with "<< vertex_cnt <<" vertices and " << face_cnt <<" faces" << std::endl;
  return;
}

int Graphicobject::simplify(Vertex* from, Vertex* to) {
	for (Edge* i : from->edge_list) {
		Vertex* partner;
		if(i->vert1 == from){
			partner = i->vert2;
		}
		else{
			partner = i->vert1;
		}
		if(!to->isConnected(partner)){
			i->replace(from, to);
		}
		else{
			this->edge_list[i->currentID] = NULL;
		}
	}
	for (Triangle* i : from->tr_list) {
		if(!i->isIn(to)){
			i->replace(from, to);
		}
		else{
			this->triangle_list[i->currentID] = NULL;
		}
	}
	//this->vertex_list[from->currentID] = NULL;
}

void Graphicobject::addEdge(Edge* new_edge) {
	edge_list.push_back(new_edge);
}
void Graphicobject::addVertex(Vertex* new_Vertex) {
	vertex_list.push_back(new_Vertex);
}
void Graphicobject::addTriangle(Triangle* new_triangle) {
	triangle_list.push_back(new_triangle);
}
