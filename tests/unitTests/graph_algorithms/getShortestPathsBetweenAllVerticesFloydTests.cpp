#include "gmock.h"
#include "graph_mocks/GraphMock.h"
#include "graph_mocks/VertexMapForTests.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;

struct getShortestPathsBetweenAllVerticesFloydTests : public testing::Test {
  weight **weightMatrix{};
  distance **ansMatrix{};
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;

  void SetUp() {}

  void TearDown() {
    delete[] weightMatrix;
    delete[] ansMatrix;
  }
};

bool matrixComparer(int size, distance **matrix1, distance **matrix2) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix1[i][j] != matrix2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

TEST_F(getShortestPathsBetweenAllVerticesFloydTests, Graph4_1) {
  // Arrange
  weight matrix[4][4] = {
      {0, -2, 7, 5}, {0, 0, 8, 6}, {0, 3, 0, -4}, {-1, 0, 0, 0}};
  distance matrix2[4][4] = {
      {0, -2, 6, 2}, {3, 0, 8, 4}, {-5, -7, 0, -4}, {-1, -3, 5, 0}};
  weightMatrix = new weight *[4];
  ansMatrix = new distance *[4];

  for (weight i = 0; i < 4; i++) {
    weightMatrix[i] = new weight[4];
    ansMatrix[i] = new distance[4];
    weightMatrix[i] = matrix[i];
    ansMatrix[i] = matrix2[i];
  }

  VertexMapForTests vertexMapForTests(4, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(4));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(4, shortestPathBetweenAllVertices, ansMatrix));
}

TEST_F(getShortestPathsBetweenAllVerticesFloydTests, Graph4) {
  // Arrange
  weight matrix[4][4] = {
      {0, 0, -2, 0}, {4, 0, 3, 0}, {0, 0, 0, 2}, {0, -1, 0, 0}};
  distance matrix2[4][4] = {
      {0, -1, -2, 0}, {4, 0, 2, 4}, {5, 1, 0, 2}, {3, -1, 1, 0}};
  weightMatrix = new weight *[4];
  ansMatrix = new distance *[4];

  for (weight i = 0; i < 4; i++) {
    weightMatrix[i] = new weight[4];
    ansMatrix[i] = new distance[4];
    weightMatrix[i] = matrix[i];
    ansMatrix[i] = matrix2[i];
  }

  VertexMapForTests vertexMapForTests(4, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(4));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(4, shortestPathBetweenAllVertices, ansMatrix));
}

TEST_F(getShortestPathsBetweenAllVerticesFloydTests, Graph5) {
  // Arrange
  weight matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  distance matrix2[5][5] = {{0, 7, 8, 5, 7},
                            {7, 0, 1, 2, 4},
                            {8, 1, 0, 3, 5},
                            {5, 2, 3, 0, 2},
                            {7, 4, 5, 2, 0}};
  weightMatrix = new weight *[5];
  ansMatrix = new distance *[5];

  for (weight i = 0; i < 5; i++) {
    weightMatrix[i] = new weight[5];
    ansMatrix[i] = new distance[5];
    weightMatrix[i] = matrix[i];
    ansMatrix[i] = matrix2[i];
  }

  VertexMapForTests vertexMapForTests(5, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(5));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(5, shortestPathBetweenAllVertices, ansMatrix));
}

TEST_F(getShortestPathsBetweenAllVerticesFloydTests, Graph6) {
  // Arrange
  weight matrix[6][6] = {{0, 1, 0, 2, 0, 8}, {1, 0, 3, 10, 0, 0},
                         {0, 3, 0, 0, 2, 0}, {2, 10, 0, 0, 4, 1},
                         {0, 0, 2, 4, 0, 0}, {8, 0, 0, 1, 0, 0}};
  distance matrix2[6][6] = {{0, 1, 4, 2, 6, 3}, {1, 0, 3, 3, 5, 4},
                            {4, 3, 0, 6, 2, 7}, {2, 3, 6, 0, 4, 1},
                            {6, 5, 2, 4, 0, 5}, {3, 4, 7, 1, 5, 0}};
  weightMatrix = new weight *[6];
  ansMatrix = new distance *[6];

  for (weight i = 0; i < 6; i++) {
    weightMatrix[i] = new weight[6];
    ansMatrix[i] = new distance[6];
    weightMatrix[i] = matrix[i];
    ansMatrix[i] = matrix2[i];
  }

  VertexMapForTests vertexMapForTests(6, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(6));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(6, shortestPathBetweenAllVertices, ansMatrix));
}

TEST_F(getShortestPathsBetweenAllVerticesFloydTests, Graph7) {
  // Arrange
  weight matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  distance matrix2[7][7] = {{0, 3, 8, 10, 13, 10, 6}, {3, 0, 5, 7, 10, 13, 9},
                            {8, 5, 0, 2, 5, 8, 5},    {10, 7, 2, 0, 3, 10, 7},
                            {13, 10, 5, 3, 0, 7, 10}, {10, 13, 8, 10, 7, 0, 4},
                            {6, 9, 5, 7, 10, 4, 0}};
  weightMatrix = new weight *[7];
  ansMatrix = new distance *[7];

  for (weight i = 0; i < 7; i++) {
    weightMatrix[i] = new weight[7];
    ansMatrix[i] = new distance[7];
    weightMatrix[i] = matrix[i];
    ansMatrix[i] = matrix2[i];
  }

  VertexMapForTests vertexMapForTests(7, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(7));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(7, shortestPathBetweenAllVertices, ansMatrix));
}

TEST_F(getShortestPathsBetweenAllVerticesFloydTests, Graph10) {
  // Arrange
  weight matrix[10][10] = {
      {0, 10, 1, 5, 0, 0, 0, 0, 0, 3}, {10, 0, 0, 0, 2, 0, 0, 0, 15, 0},
      {1, 0, 0, 0, 8, 3, 0, 0, 0, 0},  {5, 0, 0, 0, 0, 0, 11, 4, 0, 0},
      {0, 2, 8, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 3, 0, 0, 0, 7, 3, 0, 0},
      {0, 0, 0, 11, 0, 7, 0, 0, 0, 0}, {0, 0, 0, 4, 0, 3, 0, 0, 0, 8},
      {0, 15, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 0, 0, 0, 0, 0, 0, 8, 0, 0}};
  distance matrix2[10][10] = {{0, 10, 1, 5, 9, 4, 11, 7, 25, 3},
                              {10, 0, 10, 15, 2, 13, 20, 16, 15, 13},
                              {1, 10, 0, 6, 8, 3, 10, 6, 25, 4},
                              {5, 15, 6, 0, 14, 7, 11, 4, 30, 8},
                              {9, 2, 8, 14, 0, 11, 18, 14, 17, 12},
                              {4, 13, 3, 7, 11, 0, 7, 3, 28, 7},
                              {11, 20, 10, 11, 18, 7, 0, 10, 35, 14},
                              {7, 16, 6, 4, 14, 3, 10, 0, 31, 8},
                              {25, 15, 25, 30, 17, 28, 35, 31, 0, 28},
                              {3, 13, 4, 8, 12, 7, 14, 8, 28, 0}};
  weightMatrix = new weight *[10];
  ansMatrix = new distance *[10];

  for (weight i = 0; i < 10; i++) {
    weightMatrix[i] = new weight[10];
    ansMatrix[i] = new distance[10];
    weightMatrix[i] = matrix[i];
    ansMatrix[i] = matrix2[i];
  }

  VertexMapForTests vertexMapForTests(10, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(10));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(10, shortestPathBetweenAllVertices, ansMatrix));
}
