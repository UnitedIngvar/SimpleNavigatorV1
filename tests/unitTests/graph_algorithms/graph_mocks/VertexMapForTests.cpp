#include "VertexMapForTests.h"

VertexMapForTests::VertexMapForTests(int matrixSize,
									 weight **adjecencyMatrix) {
  VertexMapBuilder vertexMapBuilder;
  vertexMap = vertexMapBuilder.buildVertexesMap(adjecencyMatrix, matrixSize);
}

Vertex const &VertexMapForTests::getVertexById(vertex_id vertexId) {
  return *(vertexMap.at(vertexId));
}

VertexMapForTests::~VertexMapForTests()
{
  for (auto &&pair : vertexMap)
  {
    delete pair.second;
  }
}
