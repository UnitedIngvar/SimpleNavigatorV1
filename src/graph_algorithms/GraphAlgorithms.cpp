#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>

#include "s21_graph_algorithms.h"

// поиск в глубину (без рекурсии) DFS (обход всего графа от стартовой вершины)
std::vector<vertex_id> GraphAlgorithms::depthFirstSearch(IGraph &graph,
                                                         int startVertex) {
  std::vector<vertex_id> traversedVertices;

  std::stack<vertex_id> unvisitedVerticesStack;
  unvisitedVerticesStack.push(startVertex);

  std::unordered_set<vertex_id> visitedVerticesSet;

  while (!unvisitedVerticesStack.empty()) {
    vertex_id from =
        unvisitedVerticesStack.top();
    unvisitedVerticesStack.pop();
    if (visitedVerticesSet.count(from) == 1) {
      continue;
    }

    traversedVertices.push_back(from);
    visitedVerticesSet.insert(from);

    std::vector<Adjacency> adjacencies =
        graph.getVertexById(from).getAdjacencies();
    for (int i = int(adjacencies.size()) - 1; i >= 0; i--) {
      const Adjacency &adjacency = adjacencies[i];
      vertex_id to = adjacency.getVertex().getId();
      if (visitedVerticesSet.count(to) == 0) {
        unvisitedVerticesStack.push(to);
      }
    }
  }

  return traversedVertices;
}

// поиск в ширину BFS (обход всего графа от стартовой вершины)
std::vector<vertex_id> GraphAlgorithms::breadthFirstSearch(IGraph &graph,
                                                           int startVertex) {
  std::unordered_set<vertex_id> visitedVerticesSet;
  std::queue<vertex_id> unvisitedVerticesQueue;
  unvisitedVerticesQueue.push(startVertex);
  std::vector<vertex_id> traversedVertices;

  visitedVerticesSet.insert(startVertex);

  while (!unvisitedVerticesQueue.empty()) {
    vertex_id from = unvisitedVerticesQueue.front();
    unvisitedVerticesQueue.pop();
    traversedVertices.push_back(from);

    std::vector<Adjacency> adjacencies =
        graph.getVertexById(from).getAdjacencies();
    for (Adjacency adjacency : adjacencies) {
      vertex_id to = adjacency.getVertex().getId();
      if (visitedVerticesSet.count(to) == 0) {
        visitedVerticesSet.insert(to);
        unvisitedVerticesQueue.push(to);
      }
    }
  }

  return traversedVertices;
}

// алгоритм Дейкстры (поиск кратчайшего пути от вершины1 к вершине2)
distance GraphAlgorithms::getShortestPathBetweenVertices(IGraph &graph,
                                                         int vertex1,
                                                         int vertex2) {
  size_t sizeGraphOneIndexing = graph.getMatrixSize() + 1;

  std::vector<distance> distances(sizeGraphOneIndexing, INT_MAX);
  distances[vertex1] = 0;

  std::unordered_set<vertex_id> visitedVerticesSet;
  vertex_id minVertexId = 0;
  weight minWeight;

  while (minVertexId < INT_MAX) {
    minVertexId = INT_MAX;
    minWeight = INT_MAX;

    for (vertex_id vertexId = 1; vertexId < sizeGraphOneIndexing; vertexId++) {
      if (visitedVerticesSet.count(vertexId) == 0 &&
          distances[vertexId] < (int)minWeight) {
        minVertexId = vertexId;
        minWeight = distances[vertexId];
      }
    }

    if (minVertexId != INT_MAX) {
      std::vector<Adjacency> adjacencies =
          graph.getVertexById(minVertexId).getAdjacencies();
      for (Adjacency adjacency : adjacencies) {
        vertex_id to = adjacency.getVertex().getId();
        if ((int)(minWeight + adjacency.getWeight()) < distances[to]) {
          distances[to] = (int)(minWeight + adjacency.getWeight());
        }
      }
      visitedVerticesSet.insert(minVertexId);
    }
  }

  return distances[vertex2] - distances[vertex1];
}
