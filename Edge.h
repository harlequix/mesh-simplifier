#ifndef EDGE_H
#define EDGE_H
#include "Triangle.h"
#include "Vertex.h"
/*
 * =====================================================================================
 *
 *       Filename:  Edge.h
 *
 *    Description:  Container class for Edges
 *
 *        Version:  1.0
 *        Created:  01/27/2016 01:24:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
class Vertex;
class Triangle;
class Edge
{
public:
	Edge (Vertex* vert1, Vertex* vert2);
	virtual ~Edge ();
	double length();
	double cost();
	bool setTriangle(Triangle* tri);
	Vertex* vert1;
	Vertex* vert2;
	Triangle* tri1;
	Triangle* tri2;
	static int id;
	int currentID;
	std::string toString();
private:
	/* data */
};
#endif /* ifndef EDGE_H */
