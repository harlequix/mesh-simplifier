#include "Vertex.h"
#include "Edge.h"
#include "Triangle.h"
#include "FileReader.h"
#include <iostream>

/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main.c for mesh-simplifier
 *
 *        Version:  1.0
 *        Created:  01/30/2016 12:04:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

int main(int argc, char *argv[]){
	//Vertex vert1(0, 0, 0);
	//Vertex vert2(1, 0, 0);
	//Vertex vert3(0, 1, 0);
	//Edge v1tov2(&vert1, &vert2);
	//Edge v2tov3(&vert2, &vert3);
	//Edge v3tov1(&vert3, &vert1);
	//Triangle tri1(&v1tov2, &v2tov3, &v3tov1, &vert1, &vert2, &vert3);
  FileReader fileReader;
  fileReader.readFile("test.obj");
	return 0;
}
