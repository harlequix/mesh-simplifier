#include <Graphicobject.h>
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
void Graphicobject::show() {
	
}
void Graphicobject::addEdge(Edge* new_edge) {
	edge_list.push_back(new_edge);
}
void Graphicobject::addVertex(Vertex* new_Vertex) {
	vertex_list.push_back(new_Vertex);
}
void Graphicobject::addTriangel(Triangle* new_triangle) {
	triangle_list.push_back(new_triangle);
}
