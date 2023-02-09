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
    vertex_id from = unvisitedVerticesStack.top();
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
  int graphSize = graph.getMatrixSize() + 1;

  std::vector<distance> distances(graphSize, INT_MAX);
  distances[vertex1] = 0;

  std::unordered_set<vertex_id> visitedVerticesSet;
  vertex_id minVertexId = 0;
  weight minWeight;

  while (minVertexId < INT_MAX) {
    minVertexId = INT_MAX;
    minWeight = INT_MAX;

    for (vertex_id vertexId = 1; vertexId < graphSize; vertexId++) {
      if (visitedVerticesSet.count(vertexId) == 0 &&
          distances[vertexId] < minWeight) {
        minVertexId = vertexId;
        minWeight = distances[vertexId];
      }
    }

    if (minVertexId != INT_MAX) {
      std::vector<Adjacency> adjacencies =
          graph.getVertexById(minVertexId).getAdjacencies();
      for (Adjacency adjacency : adjacencies) {
        vertex_id to = adjacency.getVertex().getId();
        if ((minWeight + adjacency.getWeight()) < distances[to]) {
          distances[to] = (minWeight + adjacency.getWeight());
        }
      }
      visitedVerticesSet.insert(minVertexId);
    }
  }

  return distances[vertex2] - distances[vertex1];
}

// алгоритм Флойда-Уоршелла (поиск кратчайших путей между всеми парами вершин во
// взвешенном графе с положительным или отрицательным весом ребер (но без
// отрицательных циклов))
distance **GraphAlgorithms::getShortestPathsBetweenAllVertices(IGraph &graph) {
  distance sizeGraph = graph.getMatrixSize();
  weight **adjacencyMatrix = graph.getAdjacencyMatrix();

  distance **distances = new distance *[sizeGraph];
  for (distance i = 0; i < sizeGraph; i++) {
    distances[i] = new distance[sizeGraph];
    distances[i] = adjacencyMatrix[i];
    for (distance j = 0; j < sizeGraph; j++) {
      if (i != j && distances[i][j] == 0) {
        distances[i][j] = INT_MAX;
      }
    }
  }

  // идем по всем вершинам и ищем более короткий путь через вершину k
  for (vertex_id k = 0; k < sizeGraph; k++) {
    for (vertex_id i = 0; i < sizeGraph; i++) {
      for (vertex_id j = 0; j < sizeGraph; j++) {
        if (distances[i][k] == INT_MAX ||
            distances[k][j] == INT_MAX) {  // защита от переполнения
          distances[i][j] = distances[i][j];
        } else {
          // Новое значение ребра равно минимальному между старым ребром и
          // суммой ребер
          distances[i][j] =
              std::min(distances[i][j], distances[i][k] + distances[k][j]);
        }
      }
    }
  }

  return distances;
}
