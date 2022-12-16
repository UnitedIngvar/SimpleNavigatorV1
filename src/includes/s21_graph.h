#ifndef S21_GRAPH_H
# define S21_GRAPH_H

//TODO: навести порядок в зависимостях
#include <string>
#include <fstream>
#include <iostream> //TODO: убрать после дебага
#include <exception>
#include <algorithm>
#include <vector>
#include <map>
#include "Vertex.h"

class Graph
{
private:
	size_t						**_adjecencyMatrix;
	std::map<vertex_id, Vertex>	_graphVertexesMap;

	bool						_matrixInitialized;

	Vertex	const &getVertexById(vertex_id vertexId);

	size_t	getMatrixSize(std::ifstream &file);

public:
	void	loadGraphFromFile(std::string const &filename);
	void	exportGraphToDot(std::string const &filename);
	~Graph();
};

#endif
