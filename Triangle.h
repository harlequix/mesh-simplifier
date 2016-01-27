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
	Triangle (Edge* edge1, Edge* edge2, Edge* edge3, Vertex* vert1, Vertex* vert2, Vertex* vert3);
	Edge* edge1;
	Edge* edge2;
	Edge* edge3;
	Vertex* vert1;
	Vertex* vert2;
	Vertex* vert3;
	virtual ~Triangle ();

private:
	/* data */
};
