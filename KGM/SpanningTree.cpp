/* 
 * File:   SpanningTree.cpp
 * Author: mira
 * 
 * Created on October 9, 2012, 10:21 PM
 */
#include "SpanningTree.h"

SpanningTree::SpanningTree(int nodesCount, int startNode) {
        this->maxNodesCount = nodesCount;
        this->startNode = startNode;
        Nodes.insert(startNode);
        nodesDegree[startNode] = 0;
        this->degree = 0;
    this->nodesWithDegree = 1;
}

void SpanningTree::Reset() {
        Nodes.clear();
        Nodes.insert(startNode);
        Edges.clear();
        nodesDegree.clear();
        nodesDegree[this->startNode] = 0;
        this->degree = 0;
        this->nodesWithDegree = 1;
}

void SpanningTree::AddEdge(Edge* edge) {
        //if(IsSpanningTree())
        //      return;

        //pridani noveho uzlu se stupnem 1
        Nodes.insert(edge->ToNode);
        nodesDegree[edge->ToNode] = 1;

        //zvetseni stupne uzlu ke kteremu se nova hrana pridala
        nodesDegree[edge->FromNode]++;
        int fromNodeDegree = nodesDegree[edge->FromNode];
        if(fromNodeDegree == degree)
        {
                nodesWithDegree++;
        }
        if(fromNodeDegree > degree)
        {
                degree = fromNodeDegree;
                nodesWithDegree = 1;
        }

        //pridani hrany
        Edges.push_back(edge);

}

void SpanningTree::RemoveEdge(Edge* edge) {
        
        //odebrani posledne pridaneho uzlu (edge->ToNode)
        Nodes.erase(edge->ToNode);
        nodesDegree.erase(edge->ToNode);

        //poreseni stupne edge->FromNode a stupne cele kostry
        bool isFromNodeMaxDegree = nodesDegree[edge->FromNode] == degree;
        nodesDegree[edge->FromNode]--;

        if(isFromNodeMaxDegree)
        {
                if(nodesWithDegree > 1) 
                {
                        nodesWithDegree--;
                }
                else
                {
                        int maxDegree = 0;
            int nodesWithMaxDegree = 0;
                        set<int>::iterator it;
                        for (it=Nodes.begin(); it!=Nodes.end(); ++it)
                        {
                                int node = *it;
                                int nodeDegree = nodesDegree[node];
                                if(nodeDegree == maxDegree)
                                {
                                        nodesWithMaxDegree++;
                                }
                                if(nodeDegree > maxDegree)
                                {
                                        maxDegree = nodeDegree;
                                        nodesWithMaxDegree = 1;
                                }
                        }
                        degree = maxDegree;
                        nodesWithDegree = nodesWithMaxDegree;
                }
        }
        
        //odebrani posledne pridane hrany
        Edges.pop_back();

}

bool SpanningTree::IsSpanningTree() {
        return (Nodes.size() == maxNodesCount && Edges.size() == (maxNodesCount - 1));
}

int SpanningTree::GetDegree() {
        return degree;
}

