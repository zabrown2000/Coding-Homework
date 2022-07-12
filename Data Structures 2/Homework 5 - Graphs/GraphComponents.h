#ifndef GRAPHCOMPONENTS_H
#define GRAPHCOMPONENTS_H

#include <string>
#include <list>

enum Color { BLACK = 1, GREY, WHITE };

class Vertex;

class Edge
{
public:
    Vertex* destination;
    Vertex* source;

    Edge(Vertex* d, Vertex* s);
    bool operator==(Edge e);

    friend class Vertex;
};


class Vertex
{
public: //made fields public because need to access them in graph class
    std::string key;
    std::list<Edge*> edgeList; //edges to adjacent nodes

    //factors for dfs
    Color c = WHITE;
    double d = 0;
    double f = 0;
    Vertex* pi = nullptr;


    Vertex(std::string task);
    bool adde(Vertex* destination);
    bool destinationExists(Edge* newEdge); 
    int numOfNeighbors(); 
    bool operator==(Vertex v);

};


#endif // !GRAPHCOMPONENTS_H

