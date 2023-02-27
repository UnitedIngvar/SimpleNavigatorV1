#ifndef S21_GRAPH_ALGORITHMS_H
#define S21_GRAPH_ALGORITHMS_H

#include "s21_graph.h"

class GraphAlgorithms {
 public:
  GraphAlgorithms() {}

  std::vector<vertex_id> depthFirstSearch(IGraph &graph, int startVertex);

  std::vector<vertex_id> breadthFirstSearch(IGraph &graph, int startVertex);

  distance getShortestPathBetweenVertices(IGraph &graph, int vertex1,
                                          int vertex2);

  distance **getShortestPathsBetweenAllVertices(IGraph &graph);

  weight **getLeastSpanningTree(IGraph &graph);

  ~GraphAlgorithms() {}
};

#endif