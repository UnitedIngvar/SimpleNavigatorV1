#include "../includes/s21_graph_algorithms.h"
#include <queue>

std::vector<int> GraphAlgorithms::depthFirstSearch(Graph &graph, int startVertex) {
	std::vector<int> traversedVertices;


	return traversedVertices;
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) {

	int sizeGraph = 5; // need getterSizeGraph (sizeGraph = graph.getSize())
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

int GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
	int sizeGraph = 5; // need getterSizeGraph (sizeGraph = graph.getSize())
	std::vector<std::vector<int>> weight(sizeGraph, std::vector<int>(sizeGraph)); // need getterWeightMatrix (weight = graph.getAdjecencyMatrix())
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
		for (int i = 0; i < sizeGraph; i++) {
			if (!visited[i] && distance[i] < minWeight) {
				minInd = i;
				minWeight = distance[i];
			}
		}
		if (minInd != INT_MAX) {
			for (int i = 0; i < sizeGraph; i++) {
				if (weight[minInd][i] != 0 && minWeight + weight[minInd][i] < distance[i]) {
					distance[i] = minWeight + weight[minInd][i];
				}
			}
			visited[minInd] = true;
		}
	}
	return distance[vertex2] - distance[vertex1];
}
