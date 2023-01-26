#include "gmock.h"
#include "graph_mocks/GraphMock.h"
#include "graph_mocks/VertexMapForTests.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;

struct getShortestPathBetweenVerticesDijkstraTests : public testing::Test {
  weight **weightMatrix;
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;

  void SetUp() {}

  void TearDown() { delete[] weightMatrix; }
};

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph5between1and5) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(5));
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 5);

  // Assert
  ASSERT_EQ(shortestPath, 7);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph5between1and3) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(5));
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 3);
  // Assert

  ASSERT_EQ(shortestPath, 8);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph5between3and5) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 22, 0},
                         {0, 1, 0, 0, 0},
                         {5, 22, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  weightMatrix = new weight *[5];
  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    weightMatrix[i] = matrix[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(5));
  for (vertex_id i = 1; i <= 5; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 3, 5);

  // Assert
  ASSERT_EQ(shortestPath, 18);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and2) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(7));
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 2);

  // Assert
  ASSERT_EQ(shortestPath, 3);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and3) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(7));
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 3);

  // Assert
  ASSERT_EQ(shortestPath, 8);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and5) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(7));
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 5);

  // Assert
  ASSERT_EQ(shortestPath, 13);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and6) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(7));
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 6);

  // Assert
  ASSERT_EQ(shortestPath, 10);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between5and5) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(7));
  for (vertex_id i = 1; i <= 7; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 5, 5);

  // Assert
  ASSERT_EQ(shortestPath, 0);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph11between1and7) {
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(11));
  for (vertex_id i = 1; i <= 11; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 7);

  // Assert
  ASSERT_EQ(shortestPath, 100);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph11between1and7New) {
  // Arrange
  weight matrix[11][11] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
                           {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
                           {20, 15, 0, 15, 14, 25, 3, 9, 23, 27, 13},
                           {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
                           {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
                           {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
                           {100, 72, 3, 92, 94, 95, 0, 90, 101, 99, 84},
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
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(11));
  for (vertex_id i = 1; i <= 11; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto shortestPath =
      graphAlgorithms.getShortestPathBetweenVertices(graphMock, 1, 7);
  
  // Assert
  ASSERT_EQ(shortestPath, 23);
}
