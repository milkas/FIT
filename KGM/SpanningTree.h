/* 
 * File:   SpanningTree.h
 * Author: mira
 *
 * Created on October 9, 2012, 10:21 PM
 */

#pragma once

#include <vector>
#include <map>
#include <set>
#include "Edge.h"

using namespace std;

class SpanningTree {
        int startNode;
        int maxNodesCount;
        int degree;
        int nodesWithDegree;
        map<int, int> nodesDegree;

public:
        set<int> Nodes;
        vector<Edge*> Edges;
        
        SpanningTree(int nodesCount, int startNode);
        void AddEdge(Edge* edge);
        void RemoveEdge(Edge* edge);
        bool IsSpanningTree();
        int GetDegree();
        void Reset();
};

