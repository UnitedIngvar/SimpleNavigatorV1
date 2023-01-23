#include "gtest.h"
#include "gmock.h"

#include "s21_graph_algorithms.h"
#include "graph_mocks/GraphMock.h"

TEST(GraphAlgorithmsTests, depthFirstSearchReturnTest) {
// Arrange
	using ::testing::NiceMock;
	using ::testing::Return;
	NiceMock<GraphMock> g;
	GraphAlgorithms ga;
	std::vector<int> ans = {1, 2, 3};
// Act
	auto depthFirstSearch = ga.depthFirstSearch(g, 3);
// Assert
	ASSERT_EQ(depthFirstSearch, ans);
}
