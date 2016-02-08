#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Edge.h"
#include "Vertex.h"
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
class Triangle
{
public:
	Triangle (Edge* v1tov2, Edge* v2tov3, Edge* v3tov1, Vertex* vert1, Vertex* vert2, Vertex* vert3);
	void setNormal(double x, double y, double z);
	Edge* edge1;
	Edge* edge2;
	Edge* edge3;
	Vertex* vert1;
	Vertex* vert2;
	Vertex* vert3;
	double normX;
	double normY;
	double normZ;
	virtual ~Triangle ();

private:
	/* data */
};
#endif /* ifndef TRIANGLE_H */
