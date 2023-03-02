#ifndef S21_GRAPH_H
#define S21_GRAPH_H

#include <fstream>
#include <map>
#include <string>

#include "IGraph.h"
#include "IMatrixReader.h"
#include "IVertexMapBuilder.h"
#include "Vertex.h"
#include "DotBuilder.h"
#include "GraphProperties.h"

class Graph : public IGraph {
 private:
  int _matrixSize;
  weight **_adjecencyMatrix;
  std::map<vertex_id, Vertex *> _vertexMap;
  GraphProperties _graphProperties;

  bool _matrixInitialized = false;

  // Injected
  IMatrixReader const &_matrixReader;
  IVertexMapBuilder const &_vertexMapBuilder;
  IDotBuilder const &_dotBuilder;

  GraphProperties determineGraphProperties(weight **adjacencyMatrix, int matrixSize) const;

 public:
  Graph(IMatrixReader const &matrixReader,
        IVertexMapBuilder const &vertexMapBuilder,
        IDotBuilder const &dotBuilder);

  void loadGraphFromFile(std::string const &filename);
  void exportGraphToDot(std::string const &filename);

  Vertex const &getVertexById(vertex_id vertexId) const;
  int getMatrixSize() const;
  weight **getAdjacencyMatrix() const;
  bool isWeighted() const;
  bool isDirected() const;

  ~Graph();
};

#endif
