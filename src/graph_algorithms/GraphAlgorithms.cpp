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
  int sizeGraph = graph.getMatrixSize() + 1;

  std::vector<distance> distances(sizeGraph, INT_MAX);
  distances[vertex1] = 0;

  std::unordered_set<vertex_id> visitedVerticesSet;
  vertex_id minVertexId = 0;
  weight minWeight;

  while (minVertexId < INT_MAX) {
    minVertexId = INT_MAX;
    minWeight = INT_MAX;

    for (vertex_id vertexId = 1; vertexId < sizeGraph; vertexId++) {
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
    for (distance j = 0; j < sizeGraph; j++) {
      distances[i][j] = (i == j ? 0 : INT_MAX);
    }
  }

  for (distance i = 0; i < sizeGraph; i++) {
    for (distance j = 0; j < sizeGraph; j++) {
      if (adjacencyMatrix[i][j] != 0) {
        distances[i][j] = std::min(distances[i][j], adjacencyMatrix[i][j]);
      }
    }
  }

  // идем по всем вершинам и ищем более короткий путь через вершину k
  for (vertex_id k = 0; k < sizeGraph; k++) {
    for (vertex_id i = 0; i < sizeGraph; i++) {
      for (vertex_id j = 0; j < sizeGraph; j++) {
        // защита от переполнения
        if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX) {
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

// Алгоритм Прима
// построение минимального остовного дерева взвешенного связного
// неориентированного графа
weight **GraphAlgorithms::getLeastSpanningTree(IGraph &graph) {
  distance sizeGraph = graph.getMatrixSize();

  weight **adjacencyMatrixLeastSpanningTree = new weight *[sizeGraph];
  for (vertex_id i = 0; i < sizeGraph; i++) {
    adjacencyMatrixLeastSpanningTree[i] = new weight[sizeGraph];
    // заполняем матрицу нулями
    memset(adjacencyMatrixLeastSpanningTree[i], 0, sizeGraph * sizeof(weight));
  }

  // приоритетная очередь, содержащая пары:
  // {вес, {id вершины куда, id вершины откуда}}
  std::priority_queue<
      std::pair<weight, std::pair<vertex_id, vertex_id>>,
      std::vector<std::pair<weight, std::pair<vertex_id, vertex_id>>>,
      std::greater<std::pair<weight, std::pair<vertex_id, vertex_id>>>>
      unvisitedVerticesQueue;
  unvisitedVerticesQueue.push(
      {0, {1, -1}});  // начинаем с вершины 1, предка нет
  std::unordered_set<vertex_id> includedVerticesInSpanningTree;

  while (!unvisitedVerticesQueue.empty()) {
    std::pair<weight, std::pair<vertex_id, vertex_id>> from =
        unvisitedVerticesQueue.top();
    unvisitedVerticesQueue.pop();

    weight weightFrom = from.first;
    vertex_id vertexId = from.second.first;
    vertex_id vertexIdFrom = from.second.second;

    // проверяем добавлена ли вершина в остовное дерево
    if (includedVerticesInSpanningTree.count(vertexId) == 1) {
      continue;
    }

    // добавляем вершину в остовное дерево
    includedVerticesInSpanningTree.insert(vertexId);
    if (vertexIdFrom != -1) {
		// заполняем матрицу смежности для минимального остовного дерева
      adjacencyMatrixLeastSpanningTree[vertexId - 1][vertexIdFrom - 1] =
          weightFrom;
      adjacencyMatrixLeastSpanningTree[vertexIdFrom - 1][vertexId - 1] =
          weightFrom;
    }

    std::vector<Adjacency> adjacencies =
        graph.getVertexById(vertexId).getAdjacencies();

    for (Adjacency adjacency : adjacencies) {
      weight weightTo = adjacency.getWeight();
      vertex_id vertexIdTo = adjacency.getVertex().getId();

      if (includedVerticesInSpanningTree.count(vertexIdTo) == 0) {
        // добавляем ребро в очередь
        unvisitedVerticesQueue.push({weightTo, {vertexIdTo, vertexId}});
      }
    }
  }

  return adjacencyMatrixLeastSpanningTree;
}
