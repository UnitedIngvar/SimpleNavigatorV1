#include "../includes/s21_graph_algorithms.h"
#include <queue>

std::vector<int> GraphAlgorithms::depthFirstSearch(Graph &graph, int startVertex) {
	std::vector<int> traversedVertices;


	return traversedVertices;
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) {

	int sizeGraph = 5; // need getterSizeGraph (sizeGraph = graph.getSize)
	std::vector<int> parent(sizeGraph, -1);
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
}

int GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
	int sizeGraph = 5; // need getterSizeGraph (sizeGraph = graph.getSize)
	std::vector<int> distance(sizeGraph, INT_MAX);
	distance[vertex1] = 0;
	std::vector<bool> visited(sizeGraph);
	int minIndex = INT_MAX;
	for (int i = 0; i < sizeGraph; i++) {
		int minWeight = INT_MAX;
		for (int j = 0; j < sizeGraph; j++) {
			if (!visited[j] && distance[j] < minWeight) {

			}

		}
	}
}
