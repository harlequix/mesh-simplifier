#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Edge.h"
#include "Vertex.h"
#include <string>
#include <math.h>
/*
 * =====================================================================================
 *
 *       Filename:  Triangle.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/27/2016 01:34:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
class Edge;
class Triangle
{
public:
	Triangle (Edge* v1tov2, Edge* v2tov3, Edge* v3tov1, Vertex* vert1, Vertex* vert2, Vertex* vert3);
	Triangle (Vertex vert1, Vertex vert2, Vertex vert3);
	std::string toString();
	void calculateNorm();	
	void setNormal(double x, double y, double z);
	std::string normToString();
	Edge* edge1;
	Edge* edge2;
	Edge* edge3;
	Vertex* vert1;
	Vertex* vert2;
	Vertex* vert3;
	bool contains(Vertex* vert);
	double normX;
	double normY;
	bool isIn(Vertex* q);
	bool replace(Vertex* old_vert, Vertex* new_vert);
	double normZ;
	virtual ~Triangle ();
	int currentID;

private:
	static int id;
	/* data */
};
bool operator==(Triangle tr1, Triangle tr2);
#endif /* ifndef TRIANGLE_H */
