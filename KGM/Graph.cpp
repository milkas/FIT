/* 
 * File:   Graph.cpp
 * Author: mira
 * 
 * Created on October 9, 2012, 10:19 PM
 */

#include "Graph.h"
#include <stdlib.h>


Graph::Graph(ifstream& ifs)     {
        string line;

        getline(ifs, line);
        NodesCount = atoi(line.c_str());


        int lineLength;
        int i;

        int lineIndex = 0;
                
        while( getline( ifs, line ) )
        {
                lineLength = line.length();
                if(lineLength == NodesCount)
                {
                        AdjacencyList.push_back(vector<int>());
                        for (i=0; i < lineLength; i++)
                        {
                                char item = line[i];
                                int number = atoi(&item);
                                if(number == 1) {
                                        AdjacencyList[lineIndex].push_back(i);
                                }
                        }
                        lineIndex++;
                }
        }       
}

Graph::~Graph() {
        
}

