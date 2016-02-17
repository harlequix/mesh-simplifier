#include "Graphicobject.h"
#include "PriorityItem.h"
/*
 * =====================================================================================
 *
 *       Filename:  PriorityItem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/08/2016 10:56:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

std::string PriorityItem::toString() {
	return "Kosten: " + std::to_string(this->cost) +"\n"+this->content->toString();
}
