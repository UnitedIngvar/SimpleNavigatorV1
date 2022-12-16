#include <cstddef>

class Vertex;

class Adjacency
{
private:
	Vertex const		&_vertex;
	std::size_t const	_weight;

public:
	Adjacency(Vertex const &vertex, size_t weight);

	Vertex const	&getVertex() const;
	size_t			getWeight() const;
};
