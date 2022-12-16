#include "Vertex.h"

Vertex::Vertex()
{
	//TODO: get rid of this;
}

Vertex::Vertex(Vertex const &vertex)
{
	//TODO: think about how to create adjacencies;
	//TODO: check if we have to add adjacencies at runtime;
}

vertex_id						Vertex::getId() const
{
	return _id;
}

std::vector<Adjacency> const	Vertex::getAdjacencies() const
{
	return _adjacentVertexes;
}
