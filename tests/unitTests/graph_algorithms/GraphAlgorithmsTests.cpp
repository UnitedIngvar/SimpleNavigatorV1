#include "gtest.h"
#include "gmock.h"
#include "s21_graph_algorithms.h"

class VertexInterface {
public:

};

class GraphInterface {
public:
	virtual ~GraphInterface() = default;
	virtual void loadGraphFromFile(std::string const &filename) = 0;
	virtual void exportGraphToDot(std::string const &filename) = 0;
	[[nodiscard]] virtual Vertex const &getVertexById(vertex_id vertexId) const = 0;
	[[nodiscard]] virtual size_t getMatrixSize() const = 0;
	[[nodiscard]] virtual size_t **getAdjacencyMatrix() const = 0;
};

class Graph : public GraphInterface {
	~GraphInterface() override = default;
	MOCK_METHOD1(loadGraphFromFile, void(std::string const &));
	MOCK_METHOD1(getVertexById, void(std::string const &));
	MOCK_METHOD1(exportGraphToDot, void(std::string const &));


};

TEST(GraphAlgorithmsTests,
		GettersReturnValidValues
)
{
// Arrange


// Act


// Assert

}