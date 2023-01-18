#include <exception>
#include <algorithm>
#include <vector>
#include "s21_graph.h"
#include "Constants.h"
#include "MatrixReader.h"
#include "VertexMapBuilder.hpp"

void	Graph::loadGraphFromFile(std::string const &filename)
{
	std::ifstream file(filename);
	if (!file.good())
	{
		file.clear();
		throw std::invalid_argument("file could not be opened");
	}

	MatrixReader matrixReader;
	_matrixSize = matrixReader.readMatrixSize(file);
	if (_matrixSize == 0)
	{
		throw std::invalid_argument("matrix size can't be zero");
	}

	_adjecencyMatrix = matrixReader.readAdjacencyMatrix(file, _matrixSize);

	VertexMapBuilder vertexMapBuilder;
	_vertexMap = vertexMapBuilder.buildVertexesMap(_adjecencyMatrix, _matrixSize);
}

void	Graph::exportGraphToDot(std::string const &filename)
{
	(void) filename;
}

Vertex	const &Graph::getVertexById(vertex_id vertexId) const
{
	if (!_matrixInitialized)
	{
		throw std::invalid_argument("matrix is not initialized");
	}
	if (_vertexMap.find(vertexId) == _vertexMap.end())
	{
		throw std::out_of_range("vertex index " + std::to_string(vertexId) +
		" is not present in the adjecency matrix");
	}

	return _vertexMap.at(vertexId);
}

size_t			Graph::getMatrixSize() const
{
	return _matrixSize;
}

size_t			**Graph::getAdjacencyMatrix() const
{
	return _adjecencyMatrix;
}


Graph::~Graph()
{
	if (_matrixInitialized)
	{
		for (size_t i = 0; i < _matrixSize; i++)
		{
			delete[] _adjecencyMatrix[i];
		}

		delete[] _adjecencyMatrix;
	}
}
