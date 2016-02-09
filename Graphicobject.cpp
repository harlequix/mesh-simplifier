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
	
}
int Graphicobject::simplify(Edge* from, Edge* to) {
	
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
