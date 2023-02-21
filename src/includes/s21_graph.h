#ifndef S21_GRAPH_H
# define S21_GRAPH_H

#include <string>
#include <fstream>
#include <map>
#include "Vertex.h"
#include "IGraph.h"

class Graph : public IGraph
{
private:
	int								_matrixSize;
	weight							**_adjecencyMatrix;
	std::map<vertex_id, Vertex*>	_vertexMap;
	bool							_matrixInitialized;

public:
	Graph() {}

	void			loadGraphFromFile(std::string const &filename);
	void			exportGraphToDot(std::string const &filename);

	Vertex const	&getVertexById(vertex_id vertexId) const;
	int				getMatrixSize() const;
	weight			**getAdjacencyMatrix() const;

	~Graph();
};

#endif
