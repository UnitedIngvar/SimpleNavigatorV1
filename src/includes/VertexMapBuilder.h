#ifndef VERTEX_MAP_BUILDER_H
# define VERTEX_MAP_BUILDER_H

#include <map>
#include "Vertex.h"

class VertexMapBuilder
{
public:
	std::map<vertex_id, Vertex*>	buildVertexesMap(
		weight **adjacencyMatrix,
		int matrixSize);
};

#endif
