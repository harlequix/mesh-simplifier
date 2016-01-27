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

class Edge
{
public:
	Edge (Vertex* vert1, Vertex* vert2, Triangle* tri1, Triangle* tri2);
	virtual ~Edge ();
	Vertex* vert1;
	Vertex* vert2;
	Triangle* tri1;
	Triangle* tri2;
private:
	/* data */
};
