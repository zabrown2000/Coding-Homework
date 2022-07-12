#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
    this->time = 0;
}

Graph::~Graph()
{
    for (auto it = vertexMap.begin(); it != vertexMap.end(); ++it)
    {
        delete it->second;
    }
}

/**
 * function to add a vertex to the graph.
 * 
 * \param newTask task for vertex
 * \return if added correctly
 */
bool Graph::addv(std::string newTask)
{
    auto existsCheck = vertexMap.find(newTask);

    if (existsCheck != vertexMap.end()) //vertex already exists, otherwise pointer would have been to end of map
    {
        return false;
    }

    //send map to vertex function to update it;
    Vertex* newV = new Vertex(newTask);
    this->vertexMap.emplace(newTask, newV); //if inserted correctly returns true, otherwise false;
    return true;
}

/**
 * function to add an edge to a graph.
 * 
 * \param earlyTask source vertex
 * \param laterTask destination vertex
 * \return if edge added correctly
 */
bool Graph::adde(std::string earlyTask, std::string laterTask)
{
    //will only add edge if vertices exist
    unordered_map<string, Vertex*>::iterator firstCheck = this->vertexMap.find(earlyTask);
    if (firstCheck == this->vertexMap.end()) return false;
    unordered_map<string, Vertex*>::iterator secondCheck = this->vertexMap.find(laterTask);
    if (secondCheck == this->vertexMap.end()) return false;


    return firstCheck->second->adde(secondCheck->second); //now creating edge, automatically updates list for source vertex
}

/**
 * printing contents of graph.
 * 
 */
void Graph::printAll()
{
    if (!this->vertexMap.empty())
    {
        //looping through all vertices in graph
        for (auto vertexIt = vertexMap.begin(); vertexIt != vertexMap.end(); ++vertexIt)
        {
            cout << vertexIt->first << ": ";
            Vertex* currentV = vertexIt->second;
            //looping through all vertices connected to this vertex by edges
            for (auto neighborIt = currentV->edgeList.begin(); neighborIt != currentV->edgeList.end(); ++neighborIt)
            {
                cout << (*neighborIt)->destination->key << " ";
            }
            cout << endl;
        }
    }
}

/**
 * Function to get a print the topological order of a set of vertices in a DAG.
 * 
 */
void Graph::topologicalSort() //should print the key of the vertices
{   
    this->DFSOrder.clear(); //in case ran dfs another time need to reset it for this time
    this->DFS(); //now list is updated again

    cout << "order: ";

    //things added to list in ascending order, we need descending order so going in reverse
    for (auto it = this->DFSOrder.rbegin(); it != this->DFSOrder.rend(); ++it)
    {
        cout << (*it)->key << " ";
    }
}

/**
 * DFS algorithm for a graph.
 * 
 */
void Graph::DFS()
{
    //resetting color, pi, and time in case this has been run before
    this->time = 0;
    for (auto it = vertexMap.begin(); it != vertexMap.end(); ++it)
    {
        it->second->pi = nullptr;
        it->second->c = WHITE;
    }

    for (auto it = vertexMap.begin(); it != vertexMap.end(); ++it)
    {
        if (it->second->c == WHITE)
        {
            this->DFSVisit(it);
        }
    }
}

/**
 * DFS helper function for a graph.
 * Updates list for finishing times directly, no need to return it.
 * 
 * \param currentV pointer to current vertex up to in the graph's vertex list
 */
void Graph::DFSVisit(unordered_map<std::string, Vertex*>::iterator currentV)
{
    currentV->second->c = GREY;
    currentV->second->d = ++this->time;

    //looping thought all neighbors of current vertex by seeing where all its out edges go to
    for (auto neighborEdge = currentV->second->edgeList.begin(); neighborEdge != currentV->second->edgeList.end(); ++neighborEdge)
    {
        if ((*neighborEdge)->destination->c == WHITE)
        {
            (*neighborEdge)->destination->pi = currentV->second; //vertex sent to this function was the finder of this vertex
            this->DFSVisit(vertexMap.find((*neighborEdge)->destination->key)); //getting iterator to new vertex in map and sending it to function again recursively
        }
    }

    currentV->second->c = BLACK;
    currentV->second->f = ++this->time;

    this->DFSOrder.push_back(currentV->second);
}

