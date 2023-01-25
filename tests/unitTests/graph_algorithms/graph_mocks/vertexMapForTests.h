#include <map>

#include "Vertex.h"
#include "VertexMapBuilder.hpp"

class vertexMapForTests {
 private:
  std::map<size_t, Vertex> vertexMap;

 public:
  vertexMapForTests(size_t matrixSize, size_t **adjecencyMatrix);
  Vertex const &getVertexById(size_t vertexId);
};