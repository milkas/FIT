/* 
 * File:   main.cpp
 * Author: mira
 *
 * Created on October 9, 2012, 10:17 PM
 */
#include <iostream>
#include <fstream>
#include <limits>
#include <list>


#include "Edge.h"
#include "Graph.h"
#include "SpanningTree.h"
#include "stdlib.h"

using namespace std;

Graph* LoadData(char* fileName);
void PrintGraph(Graph* g);
void PrintSpanningTree(SpanningTree* s);

/*
 * 
 */
int main(int argc, char** argv) {
    Graph* graph = LoadData("soubor.txt");
    if (graph == NULL) {
        cout << "Nacteni dat selhalo!" << endl;
        return 2;
    }

    PrintGraph(graph);

    list<Edge*> myStack;
    Edge* currentEdge;
    int minBound = 2;
    int startNode = 0;
    int minDegree = numeric_limits<int>::max();
    vector<Edge> minSpanningTree;

    SpanningTree* spanningTree = new SpanningTree(graph->NodesCount, startNode);
    int adjacentForMe = graph->AdjacencyList[startNode][0];
    myStack.push_back(new Edge(startNode, adjacentForMe, false));//přidá do zásobníku první hranu vycházející z počátečního bodu

    while (!myStack.empty()) {//cyklus trvá dokud není zásobník prázdný
        currentEdge = myStack.back();//nastaví jako aktuální hranu vrchní hranu ze zásobníku
        //cout << "aktualni hrana " << currentEdge->FromNode << "do" << currentEdge->ToNode  << endl;
        if (!currentEdge->IsVisited) { //pokukd tato hrana není nastavena jako navštívená tak ji navštíví
            currentEdge->IsVisited = true;
            spanningTree->AddEdge(currentEdge);//a přidá tuto hranu do stromu
            //cout << "do stromu pridavam hranu " << currentEdge->FromNode << "do" << currentEdge->ToNode  << endl;
            
            
            int spanningTreeDegree = spanningTree->GetDegree();//nastaví do proměnné spanningTreeDegree aktuální stupeň grafu ve stromu
            if (spanningTreeDegree >= minDegree) {      //pokud je stupen grafu větší než stupeň grafu s doposud nejnižším nalezeným stupněm ukončí
                                                        //se stávající cyklus a pokračuje se dál, tuto vtev už nemá cenu procházet
                
                //cout << "tento strom uz nemuze byt lepsi - konec"  << endl;
            
                continue;
            }

            if (spanningTree->IsSpanningTree()) {//zkontroluje se, že se jedná o kompletní strom
                PrintSpanningTree(spanningTree);
                if (spanningTreeDegree < minDegree) {//pokud je tento strom kompletní a zároveň má menší stupeň než současné minimum jedná se
                    minDegree = spanningTreeDegree;  // o novou kostru s minimálním stupněm, minimum se tedy aktualizuje

                    minSpanningTree.clear(); //původní nejmenší strom se vymaže
                    int i;
                    for (i = 0; i < spanningTree->Edges.size(); i++) {// a přepíše se do něj stávající strom min. kostrou
                        minSpanningTree.push_back(Edge(spanningTree->Edges[i]->FromNode, spanningTree->Edges[i]->ToNode, false));
                    }
                }
                if (spanningTreeDegree == minBound) {//pokud se stupeň kostry současného grafu shoduje s minimem nic se neprovede
                     break;
                }
            }
            
            set<int>::iterator it;
            int i;
            for (it = spanningTree->Nodes.begin(); it != spanningTree->Nodes.end(); ++it) {

                int treeNode = *it;
                for (i = 0; i < graph->AdjacencyList[treeNode].size(); i++) {//projde v grafu pro daný bod všecny sousedy
                    int adjacent = graph->AdjacencyList[treeNode][i]; //aktualni soused je adjacency
                    if (spanningTree->Nodes.find(adjacent) == spanningTree->Nodes.end()) { //pokud se soused rovna uzlu na konci stromu
                        myStack.push_back(new Edge(treeNode, adjacent, false)); //přidá se na zásobník nová hrana která vede z posledniho uzlu do jeho souseda a oznaci se za neproslou
                        //cout << "pridavam na zasobnik hranu z" << treeNode << "do" << adjacent << endl;
                    }
                }
            }
            //cout << "konec cyklu" << endl;

        } else {//pokud je hrana již navštívená tak se smaže ze zásobníku i ze stromu
            myStack.pop_back();
            spanningTree->RemoveEdge(currentEdge);
            //cout << "odstranuju z grafu hranu" << currentEdge->FromNode << "do" << currentEdge->ToNode<< endl;
            delete currentEdge;
        }
    }




    cout << "minimalni stupen je:" << minDegree << endl;










    return 0;
}

void PrintGraph(Graph * g) {
    cout << "Nodes Count: " << g->NodesCount << endl;
    int i, j;
    for (i = 0; i < g->AdjacencyList.size(); i++) {
        for (j = 0; j < g->AdjacencyList[i].size(); j++) {
            cout << g->AdjacencyList[i][j];
        }
        cout << endl;
    }
}

void PrintSpanningTree(SpanningTree * s) {
    cout << "Edges in spanning tree:" << endl;
    int i;
    for (i = 0; i < s->Edges.size(); i++) {
        cout << s->Edges[i]->FromNode << "->" << s->Edges[i]->ToNode << endl;
    }
}

Graph * LoadData(char* fileName) {
    ifstream infile;
    infile.open(fileName);

    if (!infile) {
        cout << "Cannot open file.\n";
        return NULL;
    }

    Graph* g = new Graph(infile);

    infile.close();

    return g;
}

