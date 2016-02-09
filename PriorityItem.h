#include "Edge.h"
/*
 * =====================================================================================
 *
 *       Filename:  PriorityItem.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/09/2016 11:26:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
class PriorityItem
{
public:
	double cost;
	Edge* content;
	PriorityItem (Edge* new_edge, double cost){
		this->content = new_edge;
		this->cost = cost;
	};
	~PriorityItem (){};


private:
	/* data */
};
struct compare {
	bool operator()(const PriorityItem l, const PriorityItem r){
		return l.cost > r.cost;
	}
};

