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

<<<<<<< HEAD
//	Vertex	const &getVertexById(vertex_id vertexId);
=======
public:
	Graph();

	void			loadGraphFromFile(std::string const &filename);
	void			exportGraphToDot(std::string const &filename);
>>>>>>> 3607ebee7d339581a572301388d2bbf7ff0b221d

	Vertex const	&getVertexById(vertex_id vertexId) const;
	size_t			getMatrixSize() const;
	size_t			**getAdjacencyMatrix() const;

<<<<<<< HEAD
public:
	void	loadGraphFromFile(std::string const &filename);
	void	exportGraphToDot(std::string const &filename);
	Vertex	const &getVertexById(vertex_id vertexId);
=======
>>>>>>> 3607ebee7d339581a572301388d2bbf7ff0b221d
	~Graph();
};

#endif
