/* 
 * File:   Edge.h
 * Author: mira
 *
 * Created on October 9, 2012, 10:18 PM
 */
#pragma once

class Edge {
public:
        int FromNode;
        int ToNode;
        bool IsVisited;

        Edge(int fromNode, int toNode, bool isVisited);
        int operator==(Edge e);
};

