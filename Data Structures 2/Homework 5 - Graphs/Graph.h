#ifndef GRAPH_H
#define GRAPH_H

#include "GraphComponents.h"
#include <unordered_map>
#include <list>

class Graph
{
private:
    //Graph* graph;
    std::unordered_map<std::string, Vertex*> vertexMap;
    int time;
    std::list<Vertex*> DFSOrder;

public:
    Graph();
    ~Graph();

    bool addv(std::string newTask);
    bool adde(std::string earlyTask, std::string laterTask);
    void printAll();
    void topologicalSort();

private:
    void DFS();
    void DFSVisit(std::unordered_map<std::string, Vertex*>::iterator currentV);
};

#endif // !GRAPH_H


/*The graph will be implemented using adjacency list representation (Every vertex
contains a list of edges to its neighbors).
• Constructor (initializing an empty graph) and destructor
• Add a node
• Add an edge (verify the edge does not already exist)
• Given a vertex, return a linked list of outgoing edges
• Print the whole graph: for every node, print its edges
• DFS: return a linked list of vertices, sorted in descending order of completion
times.
(As mentioned earlier, every task is represented by a vertex and the order between
them is represented by edges). */
