#ifndef GRAPHMOCK_H
# define GRAPHMOCK_H

#include "gmock.h"
#include "IGraph.h"

class GraphMock : public IGraph {
public:
	~GraphMock() override = default;

	MOCK_METHOD(void, loadGraphFromFile, (std::string const &filename), (override));
	MOCK_METHOD(void, exportGraphToDot, (std::string const &filename), (override));
	MOCK_METHOD(Vertex const &, getVertexById, (size_t vertexId), (const, override));
	MOCK_METHOD(size_t, getMatrixSize, (), (const, override));
	MOCK_METHOD(size_t **, getAdjacencyMatrix, (), (const, override));
};

#endif
