#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>
#include "Triangle.h"
#include "Edge.h"
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
class Edge;
class Triangle;
class Vertex
{
public:
	Vertex (double x, double y, double z);
  int idd;
	double x;
	double y;
	double z;
	virtual ~Vertex ();
	std::string toString();
	void addTriangle(Triangle* tri);
	std::vector<Triangle*> tr_list;
	std::vector<Edge*> edge_list;
	void addEdge(Edge* new_edge);
	void addNeighbour(Vertex* vert);
	void removeNeighbour(Vertex* vert);
	void replaceNeighbour(Vertex* old, Vertex neww);
	std::vector<Vertex*> neighbour_list;
	bool isConnected(Vertex* q);
	void removeTriangle(Triangle* trie);
	int currentID;
	static int id;
  void setid(int);
private:
	/* data */
};

double operator*(Vertex l, Vertex r);
Vertex operator*(Vertex v, double s);
bool operator==(Vertex v, Vertex q);
#endif /* ifndef VERTEX_H */
