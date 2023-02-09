#ifndef ADJACENCY_H
# define ADJACENCY_H

# include "types.h"
# include <iostream>
# include <Vertex.h>

class Vertex;

class Adjacency
{
private:
	Vertex const		&_vertex;
	weight const		_weight;

public:
	Adjacency(Vertex const &vertex, weight weight);

	Vertex const	&getVertex() const;
	weight			getWeight() const;

	bool			operator==(Adjacency const &other) const;
};

#endif