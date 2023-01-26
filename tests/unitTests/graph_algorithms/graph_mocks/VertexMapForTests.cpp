#include "VertexMapForTests.h"

VertexMapForTests::VertexMapForTests(vertex_id matrixSize,
									 size_t **adjecencyMatrix) {
  VertexMapBuilder vertexMapBuilder;
  vertexMap = vertexMapBuilder.buildVertexesMap(adjecencyMatrix, matrixSize);

  for (vertex_id i = 0; i < matrixSize; i++) {
    for (vertex_id j = 0; j < matrixSize; j++) {
      if (adjecencyMatrix[i][j] != 0) {
        Adjacency adjacency(vertexMap.at(j + 1), adjecencyMatrix[i][j]);
        vertexMap.at(i + 1).addAdjacency(adjacency);
      }
    }
  }
}

Vertex const &VertexMapForTests::getVertexById(vertex_id vertexId) {
  return vertexMap.at(vertexId);
}