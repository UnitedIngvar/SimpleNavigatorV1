#ifndef VERTEXMAPFORTESTS_H
#define VERTEXMAPFORTESTS_H

#include <map>

#include "Vertex.h"
#include "VertexMapBuilder.hpp"

class VertexMapForTests {
private:
  std::map<vertex_id, Vertex> vertexMap;

public:
  VertexMapForTests(vertex_id matrixSize, size_t **adjecencyMatrix);
  Vertex const &getVertexById(vertex_id vertexId);
};

#endif