#include <iostream>
#include "includes/s21_graph.h"
#include "includes/s21_graph_algorithms.h"

int main() {
	Graph g;
	std::string filename = "/Users/elen/21school/A2_SimpleNavigator_v1.0-0/src/graph_algorithms/ExampleMap.txt";
	g.loadGraphFromFile(filename);
	size_t **aa = g.getAdjacencyMatrix();
	size_t sizeM = g.getMatrixSize();
	for (size_t i = 0; i < sizeM; i++) {
		for (size_t j = 0; j < sizeM; j++) {
			std::cout << aa[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << aa[5][5] << std::endl;

	GraphAlgorithms ga;
	int a = ga.getShortestPathBetweenVertices(g, 2, 5);
	printf("%d", a);
//	RUN_ALL_TESTS();
}