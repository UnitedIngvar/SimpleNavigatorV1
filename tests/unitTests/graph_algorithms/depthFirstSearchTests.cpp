#include "gmock.h"
#include "graph_mocks/GraphMock.h"
#include "graph_mocks/VertexMapForTests.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;

struct depthFirstSearchTests : public testing::Test {
  weight **weightMatrix{};
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;

  void SetUp() override {}

  void TearDown() override { delete[] weightMatrix; }
};

TEST_F(depthFirstSearchTests, Graph5startFrom1) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  weightMatrix = new weight *[5];
  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 1);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{1, 2, 3, 4, 5}));
}

TEST_F(depthFirstSearchTests, Graph5startFrom2) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  weightMatrix = new weight *[5];
  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 2);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{2, 1, 4, 5, 3}));
}

TEST_F(depthFirstSearchTests, Graph5startFrom3) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  weightMatrix = new weight *[5];
  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 3);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{3, 2, 1, 4, 5}));
}

TEST_F(depthFirstSearchTests, Graph5startFrom4) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  weightMatrix = new weight *[5];
  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 4);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{4, 1, 2, 3, 5}));
}

TEST_F(depthFirstSearchTests, Graph5startFrom5) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  weightMatrix = new weight *[5];
  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 5);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{5, 4, 1, 2, 3}));
}

TEST_F(depthFirstSearchTests, Graph7startFrom1) {
  // Arrange
  weight matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  weightMatrix = new weight *[7];
  for (weight i = 0; i < 7; i++) {
    weightMatrix[i] = new weight[7];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(7, weightMatrix);
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 1);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{1, 2, 3, 4, 5, 6, 7}));
}

TEST_F(depthFirstSearchTests, Graph7startFrom2) {
  // Arrange
  weight matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  weightMatrix = new weight *[7];
  for (weight i = 0; i < 7; i++) {
    weightMatrix[i] = new weight[7];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(7, weightMatrix);
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 2);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{2, 1, 3, 4, 5, 6, 7}));
}

TEST_F(depthFirstSearchTests, Graph7startFrom3) {
  // Arrange
  weight matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  weightMatrix = new weight *[7];
  for (weight i = 0; i < 7; i++) {
    weightMatrix[i] = new weight[7];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(7, weightMatrix);
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 3);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{3, 1, 2, 4, 5, 6, 7}));
}

TEST_F(depthFirstSearchTests, Graph7startFrom4) {
  // Arrange
  weight matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  weightMatrix = new weight *[7];
  for (weight i = 0; i < 7; i++) {
    weightMatrix[i] = new weight[7];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(7, weightMatrix);
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 4);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{4, 2, 1, 3, 5, 6, 7}));
}

TEST_F(depthFirstSearchTests, Graph7startFrom7) {
  // Arrange
  weight matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  weightMatrix = new weight *[7];
  for (weight i = 0; i < 7; i++) {
    weightMatrix[i] = new weight[7];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(7, weightMatrix);
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 7);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{7, 1, 2, 3, 4, 5, 6}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom1) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 1);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{1, 2, 5, 9, 3, 6, 4, 7, 8, 10}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom2) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 2);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{2, 1, 3, 6, 4, 7, 8, 10, 5, 9}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom3) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 3);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{3, 1, 2, 5, 9, 4, 7, 8, 10, 6}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom4) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 4);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{4, 1, 2, 5, 9, 3, 6, 7, 8, 10}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom5) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 5);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{5, 2, 1, 3, 6, 4, 7, 8, 10, 9}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom6) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 6);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{6, 3, 1, 2, 5, 9, 4, 7, 8, 10}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom7) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 7);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{7, 4, 1, 2, 5, 9, 3, 6, 8, 10}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom8) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 8);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{8, 4, 1, 2, 5, 9, 3, 6, 7, 10}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom9) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 9);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{9, 2, 1, 3, 6, 4, 7, 8, 10, 5}));
}

TEST_F(depthFirstSearchTests, Graph10startFrom10) {
  // Arrange
  weight matrix[10][10] = {
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
  weightMatrix = new weight *[10];
  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  for (vertex_id i = 1; i <= 10; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 10);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{10, 8, 4, 1, 2, 5, 9, 3, 6, 7}));
}

TEST_F(depthFirstSearchTests, Graph11startFrom1) {
  // Arrange
  weight matrix[11][11] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
                           {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
                           {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
                           {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
                           {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
                           {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
                           {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
                           {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
                           {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
                           {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
                           {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};
  weightMatrix = new weight *[11];
  for (weight i = 0; i < 11; i++) {
    weightMatrix[i] = new weight[11];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(11, weightMatrix);
  for (vertex_id i = 1; i <= 11; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 1);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));
}

TEST_F(depthFirstSearchTests, Graph11startFrom8) {
  // Arrange
  weight matrix[11][11] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
                           {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
                           {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
                           {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
                           {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
                           {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
                           {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
                           {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
                           {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
                           {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
                           {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};
  weightMatrix = new weight *[11];
  for (weight i = 0; i < 11; i++) {
    weightMatrix[i] = new weight[11];
    weightMatrix[i] = matrix[i];
  }
  VertexMapForTests vertexMapForTests(11, weightMatrix);
  for (vertex_id i = 1; i <= 11; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto dfs = graphAlgorithms.depthFirstSearch(graphMock, 8);

  // Assert
  ASSERT_EQ(dfs, (std::vector<vertex_id>{8, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11}));
}
