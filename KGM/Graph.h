/* 
 * File:   Graph.h
 * Author: mira
 *
 * Created on October 9, 2012, 10:19 PM
 */

#pragma once
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Graph {

public:
        int NodesCount;
        vector<vector<int> > AdjacencyList;

        Graph(ifstream& ifs);
        ~Graph();
};

