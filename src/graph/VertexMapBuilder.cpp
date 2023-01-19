#include "VertexMapBuilder.hpp"

std::map<vertex_id, Vertex> VertexMapBuilder::buildVertexesMap(size_t **adjacencyMatrix, size_t matrixSize)
{
	std::vector<Vertex> vertexes;

	for (vertex_id vertexId = 1;
		vertexId < matrixSize + 1;
		vertexId++)
	{
		vertexes.push_back(Vertex(vertexId));
	}

	for (size_t i = 0; i < matrixSize; i++)
	{
		Vertex currentVertex = vertexes[i];

		for (size_t j = 0; j < matrixSize; j++)
		{
			if (j == i || adjacencyMatrix[i][j] == 0)
				continue;

			Adjacency adjacency(vertexes[j], adjacencyMatrix[i][j]);
			currentVertex.addAdjacency(adjacency);
		}
	}

	std::map<vertex_id, Vertex> vertexMap;

	for (Vertex vertex : vertexes)
	{
		vertexMap.insert({vertex.getId(), vertex});
	}

	return vertexMap;
}
