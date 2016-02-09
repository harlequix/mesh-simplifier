#ifndef GRAPHICOB_H
#define GRAPHICOB_H
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "Triangle.h"
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
	int simplify();
	void revert();
	std::vector<Edge*> edge_list;
	std::vector<Vertex*> vertex_list;
        std::vector<Triangle*> triangle_list;
private:

};
class PriorityItem
{
public:
	double cost;
	Edge* content;
	PriorityItem (Edge* new_edge, double cost){
		this->content = new_edge;
		this->cost = cost;
	};
	~PriorityItem (){};


private:
	/* data */
};
struct compare {
	bool operator()(const PriorityItem l, const PriorityItem r){
		return l.cost > r.cost;
	}
};
#endif /* ifndef GRAPHICOB_H */
