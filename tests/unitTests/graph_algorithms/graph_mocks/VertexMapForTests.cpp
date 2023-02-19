#include "VertexMapForTests.h"

VertexMapForTests::VertexMapForTests(int matrixSize, weight **adjecencyMatrix) {
  VertexMapBuilder vertexMapBuilder;
  vertexMap = vertexMapBuilder.buildVerticesMap(adjecencyMatrix, matrixSize);

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      if (adjecencyMatrix[i][j] != 0) {
        Adjacency adjacency(*(vertexMap.at(j + 1)), adjecencyMatrix[i][j]);
        vertexMap.at(i + 1)->addAdjacency(adjacency);
      }
    }
  }
}

Vertex const &VertexMapForTests::getVertexById(vertex_id vertexId) {
  return *(vertexMap.at(vertexId));
}

VertexMapForTests::~VertexMapForTests() {
  for (auto &&pair : vertexMap) {
    delete pair.second;
  }
}
