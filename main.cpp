#include "Vertex.h"
#include "Edge.h"
#include "FileReader.h"
#include <iostream>
#include <queue>
#include <functional>
/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/08/2016 03:00:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
int main(int argc, char *argv[]){
	/*Vertex v1(-1,0,0);
	std::cout << v1.toString() << std::endl;;
	Vertex v2(1,0,0);
	Vertex v3(0,1,0);
	Triangle t1(v1, v2, v3);
	std::cout << t1.toString();
	Triangle t2(v2, v1, v3);
	std::cout << t2.toString();
	FileReader fread;
	Graphicobject foo = fread.readFile("test.obj");*/
	Graphicobject foo;
	Vertex p1(4,2,0);
	Vertex p2(1,2,0);
	Vertex p3(0,1,0);
	Vertex p4(1,0,0);
	Vertex p5(3,0,0);
	Vertex p6(5,1,0);
	Vertex p7(2,1,0);
	Vertex p8(3,1,0);

	Edge e1(&p1, &p2);
	Edge e2(&p2, &p3);
	Edge e3(&p3, &p4);
	Edge e4(&p4, &p5);
	Edge e5(&p6, &p7);
	Edge e6(&p1, &p6);
	Edge e7(&p1, &p8);
	Edge e8(&p1, &p7);
	Edge e9(&p2, &p7);
	Edge e10(&p3, &p7);
	Edge e11(&p4, &p7);
	Edge e12(&p5, &p7);
	Edge e13(&p5, &p8);
	Edge e14(&p6, &p8);
	Edge e15(&p7, &p8);

	Triangle t1(&e1, &e9, &e8, &p1, &p2, &p7);
	Triangle t2(&e2, &e9, &e10, &p2, &p3, &p7);
	Triangle t3(&e10, &e3, &e11, &p3, &p7, &p4);
	Triangle t4(&e4, &e11, &e12, &p4, &p5, &p7);
	Triangle t5(&e15, &e13, &e12, &p5, &p7, &p8);
	Triangle t6(&e5, &e14, &e13, &p5, &p6, &p8);
	Triangle t7(&e6, &e7, &e14, &p1, &p6, &p8);
	Triangle t8(&e15, &e7, &e8, &p1, &p7, &p8);

	foo.addTriangle(&t1);
	foo.addTriangle(&t2);
	foo.addTriangle(&t3);
	foo.addTriangle(&t4);
	foo.addTriangle(&t5);
	foo.addTriangle(&t6);
	foo.addTriangle(&t7);
	foo.addTriangle(&t8);

	foo.addEdge(&e1);
	foo.addEdge(&e2);
	foo.addEdge(&e3);
	foo.addEdge(&e4);
	foo.addEdge(&e5);
	foo.addEdge(&e6);
	foo.addEdge(&e7);
	foo.addEdge(&e8);
	foo.addEdge(&e9);
	foo.addEdge(&e10);
	foo.addEdge(&e11);
	foo.addEdge(&e12);
	foo.addEdge(&e13);
	foo.addEdge(&e14);
	foo.addEdge(&e15);
	std::cout << t5.normToString() << std::endl;
	std::cout << t8.normToString() << std::endl;
	std::cout << t7.normToString() << std::endl;
	std::cout << t6.normToString() << std::endl;
	std::cout << e15.cost() << std::endl;
	//std::priority_queue<PriorityItem, std::v cost_queue;
	foo.cost_queue.push(PriorityItem(&e1, e1.cost()));
	foo.cost_queue.push(PriorityItem(&e2, e2.cost()));
	foo.cost_queue.push(PriorityItem(&e3, e3.cost()));
	foo.cost_queue.push(PriorityItem(&e4, e4.cost()));
	foo.cost_queue.push(PriorityItem(&e5, e5.cost()));
	foo.cost_queue.push(PriorityItem(&e6, e6.cost()));
	foo.cost_queue.push(PriorityItem(&e7, e7.cost()));
	foo.cost_queue.push(PriorityItem(&e8, e8.cost()));
	foo.cost_queue.push(PriorityItem(&e9, e9.cost()));
	foo.cost_queue.push(PriorityItem(&e10, e10.cost()));
	foo.cost_queue.push(PriorityItem(&e11, e11.cost()));
	foo.cost_queue.push(PriorityItem(&e12, e12.cost()));
	foo.cost_queue.push(PriorityItem(&e13, e13.cost()));
	foo.cost_queue.push(PriorityItem(&e14, e14.cost()));
	foo.cost_queue.push(PriorityItem(&e15, e15.cost()));
	/*for (Triangle* i : foo.triangle_list) {
		std::cout << i->toString();
	}
	for (Edge* i : foo.edge_list) {
		std::cout << i->toString();
	}
	std::cout << foo.triangle_list.size();*/
	while(!foo.cost_queue.empty()){
		PriorityItem i = foo.cost_queue.top();
		foo.cost_queue.pop();
		std::cout <<"Kosten: " <<i.cost << std::endl  << i.content->toString();
	}
	std::cout << p8.toString() << std::endl;
	return 0;
}
