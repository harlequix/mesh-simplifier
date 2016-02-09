#ifndef GRAPHICOB_H
#define GRAPHICOB_H
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "Triangle.h"
#include <queue>
#include "PriorityItem.h"
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
	void addTriangle(Triangle* new_triangle);
	void show();
	int simplify(Edge* from, Edge* to);
	void revert();
	std::vector<Edge*> edge_list;
	std::vector<Vertex*> vertex_list;
        std::vector<Triangle*> triangle_list;
	std::priority_queue<PriorityItem, std::vector<PriorityItem>, compare> cost_queue;

private:

};
#endif /* ifndef GRAPHICOB_H */
