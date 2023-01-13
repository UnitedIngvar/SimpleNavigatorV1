#include "Vertex.h"

Vertex::Vertex(Vertex const &other)
	: _id(other._id), _adjacentVertexes(other._adjacentVertexes)
{
}

Vertex::Vertex(vertex_id vertexId)
	: _id(vertexId)
{
}

vertex_id						Vertex::getId() const
{
	return _id;
}

std::vector<Adjacency> const	Vertex::getAdjacencies() const
{
	return _adjacentVertexes;
}

void							Vertex::addAdjacency(Adjacency const &adjacency)
{
	_adjacentVertexes.push_back(adjacency);
}

bool							Vertex::operator==(Vertex const &other) const
{
	// We're only interested in vertex id here,
	// as we fill the adjacency list only once
	// in the beginning of the program
	return other.getId() == this->getId();
}
