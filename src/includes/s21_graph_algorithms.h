#ifndef S21_GRAPH_ALGORITHMS_H
#define S21_GRAPH_ALGORITHMS_H

#include "s21_graph.h"

class GraphAlgorithms {
 public:
  GraphAlgorithms() {}

  std::vector<int> depthFirstSearch(IGraph &graph, int startVertex);

  std::vector<int> breadthFirstSearch(IGraph &graph, int startVertex);

  int getShortestPathBetweenVertices(IGraph &graph, int vertex1, int vertex2);

  ~GraphAlgorithms() {}
};

#endif
