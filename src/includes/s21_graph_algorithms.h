#ifndef S21_GRAPH_ALGORITHMS_H
#define S21_GRAPH_ALGORITHMS_H

//#include "s21_graph.h"
#include "../includes/s21_graph.h"

class GraphAlgorithms {

public:
	GraphAlgorithms() {}

	std::vector<int> depthFirstSearch(Graph &graph, int startVertex);

	std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);

	int getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);

	~GraphAlgorithms() {}
};

#endif
