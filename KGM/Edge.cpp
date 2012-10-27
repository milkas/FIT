/* 
 * File:   Edge.cpp
 * Author: mira
 * 
 * Created on October 9, 2012, 10:18 PM
 */

#include "Edge.h"

Edge::Edge(int fromNode, int toNode, bool isVisited) {
        this->FromNode = fromNode;
        this->ToNode = toNode;
        this->IsVisited = isVisited;
}

int Edge::operator==(Edge e) {
        return FromNode==e.FromNode && ToNode==e.ToNode;
}

