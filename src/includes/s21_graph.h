#ifndef S21_GRAPH_H
# define S21_GRAPH_H

#include <string>
#include <fstream>
#include <map>
#include "Vertex.h"

class Graph
{
private:
	size_t						_matrixSize;
	size_t						**_adjecencyMatrix;
	std::map<vertex_id, Vertex>	_vertexMap;
	bool						_matrixInitialized;

public:
	Graph();

	void			loadGraphFromFile(std::string const &filename);
	void			exportGraphToDot(std::string const &filename);

	Vertex const	&getVertexById(vertex_id vertexId) const;
	size_t			getMatrixSize() const;
	size_t			**getAdjacencyMatrix() const;

	~Graph();
};

#endif
