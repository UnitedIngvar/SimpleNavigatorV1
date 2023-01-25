#include "vertexMapForTests.h"

vertexMapForTests::vertexMapForTests(size_t matrixSize,
                                     size_t **adjecencyMatrix) {
  VertexMapBuilder vertexMapBuilder;
  vertexMap = vertexMapBuilder.buildVertexesMap(adjecencyMatrix, matrixSize);
  for (size_t i = 0; i < matrixSize; i++) {
    for (size_t j = 0; j < matrixSize; j++) {
      if (adjecencyMatrix[i][j] != 0) {
        Adjacency adjacency(vertexMap.at(j + 1), adjecencyMatrix[i][j]);
        vertexMap.at(i + 1).addAdjacency(adjacency);
      }
    }
  }
}

Vertex const &vertexMapForTests::getVertexById(size_t vertexId) {
  return vertexMap.at(vertexId);
}