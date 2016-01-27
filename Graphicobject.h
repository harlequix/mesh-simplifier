#include <vector>
#include <Edge.h>
#include <Vertex.h>
#include <Triangle.h>
/*
 * =====================================================================================
 *
 *       Filename:  Graphicobject.cpp
 *
 *    Description:  contains Graphic Object
 *
 *        Version:  1.0
 *        Created:  01/27/2016 01:10:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
class Graphicobject
{
public:
	Graphicobject ();
	virtual ~Graphicobject ();
	void addVertex(Vertex*new_Vertex);
	void addEdge(Edge* new_edge);
	void addTriangel(Triangle* new_triangle);
	void show();
	int simplify();
	void revert();
private:
	std::vector<Edge*> edge_list;
	std::vector<Triangle*> triangle_list;
	std::vector<Vertex*> vertex_list;
};
