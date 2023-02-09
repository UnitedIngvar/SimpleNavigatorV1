#include "Adjacency.h"
#include "Vertex.h"

Adjacency::Adjacency(Vertex const &vertex, int weight) :
		_vertex(vertex),
		_weight(weight)
{

}

Vertex const	&Adjacency::getVertex() const
{
	return _vertex;
}

weight				Adjacency::getWeight() const
{
	return _weight;
}

bool	Adjacency::operator==(Adjacency const &other) const
{
	return
			other.getVertex().getId() == this->getVertex().getId() &&
			other.getWeight() == this->getWeight();
}