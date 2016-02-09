#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>
#include "Triangle.h"


/*
 * =====================================================================================
 *
 *       Filename:  Vertex.h
 *
 *    Description:  Containerclass for Vertex
 *
 *        Version:  1.0
 *        Created:  01/27/2016 01:39:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
class Triangle;
class Vertex
{
public:
	Vertex (double x, double y, double z);
	double x;
	double y;
	double z;
	virtual ~Vertex ();
	std::string toString();
	void addTriangle(Triangle* tri);
	std::vector<Triangle*> tr_list;

private:
	/* data */
};

double operator*(Vertex l, Vertex r);
Vertex operator*(Vertex v, double s);

#endif /* ifndef VERTEX_H */
