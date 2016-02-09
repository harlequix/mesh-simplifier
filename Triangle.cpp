#include "Triangle.h"
#include <string>
/*
 * =====================================================================================
 *
 *       Filename:  Triangle.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/01/2016 10:49:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

Triangle::Triangle (Edge* v1tov2, Edge* v2tov3, Edge* v3tov1, Vertex* vert1, Vertex* vert2, Vertex* vert3):currentID(id++){
	this->edge1 = v1tov2;
	this->edge2 = v2tov3;
	this->edge3 = v3tov1;
	this->vert1 = vert1;
	this->vert2 = vert2;
	this->vert3 = vert3;
	this->edge1->setTriangle(this);
	this->edge2->setTriangle(this);
	this->edge3->setTriangle(this);
	this->vert1->addTriangle(this);
	this->vert2->addTriangle(this);
	this->vert3->addTriangle(this);
	//this->id++;
	//this->currentID = this->id;
	calculateNorm();
	//this->normX = 1;
	//this->normY = 1;
	//this->normZ = 1;
	//TODO Register Triangle to edges
}
Triangle::Triangle(Vertex vert1, Vertex vert2, Vertex vert3):currentID(id++){
	this->vert1 = &vert1;
	this->vert2 = &vert2;
	this->vert3 = &vert3;
}
Triangle::~Triangle() {
}
void Triangle::calculateNorm() {
	Vertex v1(vert2->x - vert1->x, vert2->y -vert1->y, vert2->z -vert1->z);
	Vertex v2(vert3->x - vert1->x, vert3->y -vert1->y, vert3->z -vert1->z);
	double normX = v1.y*v2.z - v1.z*v2.y;
	double normY = v1.z*v2.x - v1.x*v2.z;
	double normZ = v1.x*v2.y - v1.y*v2.x;
	double length = sqrt(pow(normX,2) + pow(normY, 2) + pow(normZ, 2));
	this->normX = normX/length;
	this->normY = normY/length;
	this->normZ = normZ/length;
}
std::string Triangle::toString() {
	return "Triangle " + std::to_string(this->currentID) + "\n" + "\t" + vert1->toString() + "\n\t" + vert2->toString() + "\n\t" + vert3->toString() + "\n"; 
}
void Triangle::setNormal(double x, double y, double z) {
	normX = x;
	normY = y;
	normZ = z;
}
std::string Triangle::normToString() {
	return "Norm " + std::to_string(this->normX) + ", " + std::to_string(this->normY) + ", " +  std::to_string(this->normZ);
}
int Triangle::id = 0;
