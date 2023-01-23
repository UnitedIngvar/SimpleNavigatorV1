#include "s21_graph_algorithms.h"
#include <queue>

std::vector<int> GraphAlgorithms::depthFirstSearch(IGraph &graph, int startVertex) {
	std::vector<int> traversedVertices = {1, 2, 3};
	int a = graph.getMatrixSize();
	(void)a;
	(void)startVertex;
	return traversedVertices;
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(IGraph &graph, int startVertex) {
	size_t sizeGraph = graph.getMatrixSize();
	std::vector<int> parent(sizeGraph, -1);
	startVertex--;
	parent[startVertex] = startVertex;
	std::queue<int> q;
	q.push(startVertex);
	std::vector<int> traversedVertices;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		traversedVertices.push_back(from);
		std::vector<Adjacency> Adjacencies = graph.getVertexById(from).getAdjacencies();
		for (Adjacency v: Adjacencies) {
			int to = v.getVertex().getId();
			if (parent[to] == -1) {
				parent[to] = from;
				q.push(to);
			}
		}
	}
	return traversedVertices;
}

int GraphAlgorithms::getShortestPathBetweenVertices(IGraph &graph, int vertex1, int vertex2) {
	size_t sizeGraph = (int)graph.getMatrixSize();
	size_t **w = graph.getAdjacencyMatrix();
	vertex1--;
	vertex2--;
	std::vector<int> distance(sizeGraph, INT_MAX);
	distance[vertex1] = 0;
	std::vector<bool> visited(sizeGraph);
	int minInd = 0;
	int minWeight;
	while (minInd < INT_MAX) {
		minInd = INT_MAX;
		minWeight = INT_MAX;
		for (size_t i = 0; i < sizeGraph; i++) {
			if (!visited[i] && distance[i] < minWeight) {
				minInd = (int)i;
				minWeight = distance[i];
			}
		}
		if (minInd != INT_MAX) {
			for (size_t i = 0; i < sizeGraph; i++) {
				if ((int)w[minInd][i] != 0 && minWeight + (int)w[minInd][i] < distance[i]) {
					distance[i] = minWeight + (int)w[minInd][i];
				}
			}
			visited[minInd] = true;
		}
	}
	return distance[vertex2] - distance[vertex1];
}
