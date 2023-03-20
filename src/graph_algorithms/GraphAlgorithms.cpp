#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>

#include "s21_graph_algorithms.h"

// поиск в глубину (без рекурсии) DFS (обход всего графа от стартовой вершины)
// ориентированный или неориентированный граф
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
// невзвешенный (ориентированный или неориентированный) граф
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
// только для графов без рёбер отрицательного веса
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
        if (minWeight < 0) {  // проверка на наличие отрицательных весов
          throw std::invalid_argument(
              "Dijkstra's algorithm only works for graphs with non-negative "
              "weights.");
        }
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
// взвешенном ориентированном или неориентированном графе с положительным или
// отрицательным весом ребер (но без отрицательных циклов))
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
      // проверка на наличие отрицательного цикла
      if (adjacencyMatrix[i][j] < 0 &&
          adjacencyMatrix[i][j] == adjacencyMatrix[j][i]) {
        // очищаем память
        for (int d = 0; d < sizeGraph; d++) {
          delete[] distances[d];
        }
        delete[] distances;
        throw std::invalid_argument(
            "Floyd-Warshall algorithm only works for graphs without negative "
            "cycles.");
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

  // приоритетная очередь, содержащая ребро в виде пары:
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

// решение задачи коммивояжера с помощью муравьиного алгоритма
// нахождение самого выгодного (короткого) маршрута,
// проходящего через все вершины графа хотя бы по одному разу с возвратом в
// исходную вершину


#define ALPHA   1           // вес фермента
#define BETTA   3           // коэффициент эвристики

#define T_MAX   100         // время жизни колонии
#define CNT_ANTS 20         // количество муравьев в колонии
#define Q       100         // количество
#define RHO     0.5         // коэффициент испарения феромона

struct AntsWay {
	int itabu; //количество вершин
	int distance;
	int *tabu; //массив вершин
};

// вероятность перехода муравья ant в вершину to
double probability(vertex_id to, AntsWay ant, double **pheromone, double **distances, int sizeGraph) {
	// если вершина уже посещена, возвращаем 0
	for (int i = 0; i < ant.itabu; i++) {
		if (to == ant.tabu[i]) {
			return 0;
		}
	}

	double sum = 0.0;
	vertex_id from = ant.tabu[ant.itabu - 1];
	// считаем сумму в знаменателе
	for (vertex_id i = 0; i < sizeGraph; i++) {
		bool visited = false;
		// проверяем, посещал ли муравей i вершину
		for (int j = 0; j < ant.itabu; j++) {
			if (i == ant.tabu[j]) {
				visited = true;
			}
		}
		// если нет, тогда прибавляем к общей сумме
		if (!visited) {
			sum += pow(pheromone[from][i], ALPHA) * pow(distances[from][i], BETTA);
		}
	}
	// возвращаем значение вероятности
	return pow(pheromone[from][to], ALPHA) * pow(distances[from][to], BETTA) / sum;
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(IGraph &graph) {
	distance sizeGraph = graph.getMatrixSize();

	// инициализация данных о лучшем маршруте
	TsmResult result;
	result.vertices = std::vector<int>(sizeGraph + 1);
	result.distance = -1;

	// инициализация данных о расстоянии и количестве феромона
	weight **adjacencyMatrix = graph.getAdjacencyMatrix();

//	int **distances = new int *[sizeGraph];
	double **distances = new double *[sizeGraph];
	double **pheromone = new double *[sizeGraph];

	for (vertex_id i = 0; i < sizeGraph; i++) {
		distances[i] = new double[sizeGraph];
		pheromone[i] = new double[sizeGraph];
		for (vertex_id j = 0; j < sizeGraph; j++) {
			if (i != j) {
//				distances[i][j] = 1.0 / adjacencyMatrix[i][j];
				distances[i][j] = adjacencyMatrix[i][j];
			}
			pheromone[i][j] = 1.0 / sizeGraph; // ?
		}
	}

	// инициализация муравьев
	AntsWay ants[CNT_ANTS];
	for (int i = 0; i < CNT_ANTS; i++) {
		ants[i].itabu = 0;
		ants[i].distance = 0.0;
		ants[i].tabu = new int[sizeGraph];
		ants[i].tabu[ants[i].itabu++] = 0; // начинаем с первой вершины
	}

	int itabu = 0;
	// основной цикл
	for (int t = 0; t < T_MAX; t++) {
		// цикл по муравьям
		for (int a = 0; a < CNT_ANTS; a++) {
			// поиск маршрута для a-го муравья
			while (ants[a].tabu[ants[a].itabu - 1] != 10) { // пока не вернемся в начальную вершину???
				vertex_id idVertexWithMaxProbability = -1;
				double maxProbability = 0.0;
				for (vertex_id j = 0; j < sizeGraph; j++) {
					// Проверка вероятности перехода в вершину j
					if (ants[a].tabu[ants[a].itabu - 1] != j) {
						double currProbability = probability(j, ants[a], pheromone, distances, sizeGraph);
						if (currProbability && currProbability >= maxProbability) {
							maxProbability = currProbability;
							idVertexWithMaxProbability = j;
						}
					}
				}
				ants[a].distance += adjacencyMatrix[ants[a].tabu[ants[a].itabu - 1]][idVertexWithMaxProbability];
				ants[a].tabu[ants[a].itabu++] = idVertexWithMaxProbability;
			}
			// оставляем феромон на пути муравья
			for (int i = 0; i < ants[a].itabu - 1; i++) {
				vertex_id from = ants[a].tabu[i % ants[a].itabu];
				vertex_id to = ants[a].tabu[(i + 1) % ants[a].itabu];
				pheromone[from][to] += Q / ants[a].distance;
				pheromone[to][from] = pheromone[from][to];
			}

			// проверка на лучшее решение
			if (ants[a].distance < result.distance || result.distance < 0) {
				result.distance = ants[a].distance;
				itabu = ants[a].itabu;
				for (int i = 0; i < itabu; i++) {
					result.vertices[i] = ants[a].tabu[i] + 1;
				}
			}

			// обновление муравьев
			ants[a].itabu = 1;
			ants[a].distance = 0.0;
		}

		// цикл по ребрам
		for (vertex_id i = 0; i < sizeGraph; i++) {
			for (vertex_id j = 0; j < sizeGraph; j++) {
				// обновление феромона для ребра (i, j)
				if (i != j) {
					pheromone[i][j] *= (1 - RHO);
				}
			}
		}
	}

	// возвращаем кратчайший маршрут
	return result;
}
