#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

#include "Adjacency.h"
#include "types.h"
#include "vector"

class Adjacency;

class Vertex {
 private:
  vertex_id _id;
  std::vector<Adjacency> _adjacentVertices;

 public:
  Vertex(vertex_id vertexId);
  Vertex(Vertex const &other);

  vertex_id getId() const;
  std::vector<Adjacency> const getAdjacencies() const;
  void addAdjacency(Adjacency const &adjacency);

  bool operator==(Vertex const &other) const;

  ~Vertex();
};

#endif