#ifndef VERTEX_MAP_BUILDER_H
# define VERTEX_MAP_BUILDER_H

#include <map>
#include "Vertex.h"

class VertexMapBuilder
{
public:
	std::map<vertex_id, Vertex>	buildVertexesMap(
		size_t **adjacencyMatrix,
		size_t matrixSize);
};

#endif
