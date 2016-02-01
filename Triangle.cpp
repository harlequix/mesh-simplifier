#include "Triangle.h"
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

Triangle::Triangle (Edge* v1tov2, Edge* v2tov3, Edge* v3tov1, Vertex* vert1, Vertex* vert2, Vertex* vert3){
	this->edge1 = v1tov2;
	this->edge2 = v2tov3;
	this->edge3 = v3tov1;
	this->vert1 = vert1;
	this->vert2 = vert2;
	this->vert3 = vert3;
	//TODO Register Triangle to edges
}
Triangle::~Triangle() {
}
