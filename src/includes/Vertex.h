#include "Adjacency.h"
#include "vector"

typedef size_t vertex_id;

class Adjacency;

class Vertex
{
private:
	vertex_id				_id;
	std::vector<Adjacency>	_adjacentVertexes;

public:
	Vertex();
	Vertex(Vertex const &vertex);

	vertex_id						getId() const;
	std::vector<Adjacency> const	getAdjacencies() const;
};
