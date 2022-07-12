#include "GraphComponents.h"


Edge::Edge(Vertex* d, Vertex *s)
{
    this->destination = d;
    this->source = s;
}


/**
 * function to compare 2 edges to seem if same.
 * 
 * \param e
 * \return 
 */
bool Edge::operator==(Edge e)
{
    //return (e.destination == this->destination);
    return (e.destination->key == this->destination->key) && (e.source->key == this->source->key);
}
