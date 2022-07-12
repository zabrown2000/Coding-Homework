#include "GraphComponents.h"

/**
 * constructor.
 * 
 * \param task new task for vertex
 */
Vertex::Vertex(std::string task)
{
    this->key = task;
}

/**
 * Function to add edge to a vertex.
 * 
 * \param destination vertex to go on other end of edge
 * \return true if edge added correctly
 */
bool Vertex::adde(Vertex* destination)
{
    //need to check if edge exists
    Edge* tempEdge = new Edge(destination, this);
    bool exists = this->destinationExists(tempEdge);
    if (!exists)
    {
        //need to add edge to vertex's list of adjacent edges
        this->edgeList.push_back(tempEdge);
        return true;
    }
    return false; //edge not added
}

/**
 * function to check if egde exists for a vertex.  
 * 
 * \param newEdge
 * \return true if it does exist
 */
bool Vertex::destinationExists(Edge* newEdge)
{
    //search for edge in vertex's edge list
    if (!this->edgeList.empty())
    {
        for (auto it = edgeList.begin(); it != edgeList.end(); ++it)
        {
            if (((*it)->destination->key == newEdge->destination->key) && ((*it)->source->key == newEdge->source->key)) //not working properly with the check below
            //if ((*it) == newEdge)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * Function to get get number of neighbors of a vertex.
 * 
 * \return 
 */
int Vertex::numOfNeighbors()
{
    return edgeList.size();
}

/**
 * Function to check if 2 vertices are equal based on key.
 * 
 * \param v
 * \return 
 */
bool Vertex::operator==(Vertex v)
{
    return (v.key == this->key);
}


