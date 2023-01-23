#ifndef GRAPHINTERFACE_H
# define GRAPHINTERFACE_H

#include "Vertex.h"

class IGraph {
public:
	virtual ~IGraph() = default;
	virtual void loadGraphFromFile(std::string const &filename) = 0;
	virtual void exportGraphToDot(std::string const &filename) = 0;
	virtual Vertex const &getVertexById(size_t vertexId) const = 0;
	virtual size_t getMatrixSize() const = 0;
	virtual size_t **getAdjacencyMatrix() const = 0;
};

#endif
