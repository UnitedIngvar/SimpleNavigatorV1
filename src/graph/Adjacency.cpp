#include "Adjacency.h"

Adjacency::Adjacency(Vertex const &vertex, size_t weight):
	_vertex(vertex),
	_weight(weight)
{

}

Vertex const	&Adjacency::getVertex() const
{
	return _vertex;
}

size_t			Adjacency::getWeight() const
{
	return _weight;
}
