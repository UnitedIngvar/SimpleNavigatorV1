#include "gmock.h"
#include "graph_mocks/GraphMock.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;

struct getShortestPathBetweenVerticesDijkstraTests : public testing::Test {
  size_t **m;
  NiceMock<GraphMock> g;
  GraphAlgorithms ga;

  void SetUp() {}

  void TearDown() { delete[] m; }
};

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph5between1and5) {
  // Arrange
  size_t matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  m = new size_t *[5];
  for (int i = 0; i < 5; i++) {
    m[i] = new size_t[5];
    m[i] = matrix[i];
  }

  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 5);
  // Assert
  ASSERT_EQ(shortestPath, 7);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph5between1and3) {
  // Arrange
  size_t matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 2, 0},
                         {0, 1, 0, 0, 0},
                         {5, 2, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  m = new size_t *[5];
  for (int i = 0; i < 5; i++) {
    m[i] = new size_t[5];
    m[i] = matrix[i];
  }

  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 3);
  // Assert
  ASSERT_EQ(shortestPath, 8);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph5between3and5) {
  // Arrange
  size_t matrix[5][5] = {{0, 10, 0, 5, 0},
                         {10, 0, 1, 22, 0},
                         {0, 1, 0, 0, 0},
                         {5, 22, 0, 0, 2},
                         {0, 0, 0, 2, 0}};
  m = new size_t *[5];
  for (int i = 0; i < 5; i++) {
    m[i] = new size_t[5];
    m[i] = matrix[i];
  }

  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 3, 5);
  // Assert
  ASSERT_EQ(shortestPath, 18);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and2) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }

  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 2);
  // Assert
  ASSERT_EQ(shortestPath, 3);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and3) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 3);
  // Assert
  ASSERT_EQ(shortestPath, 8);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and5) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 5);
  // Assert
  ASSERT_EQ(shortestPath, 13);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between1and6) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 6);
  // Assert
  ASSERT_EQ(shortestPath, 10);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph7between5and5) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 5, 5);
  // Assert
  ASSERT_EQ(shortestPath, 0);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph11between1and7) {
  // Arrange
  size_t matrix[11][11] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
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
  m = new size_t *[11];
  for (int i = 0; i < 11; i++) {
    m[i] = new size_t[11];
    m[i] = matrix[i];
  }
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(11));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 7);
  // Assert
  ASSERT_EQ(shortestPath, 100);
}

TEST_F(getShortestPathBetweenVerticesDijkstraTests, Graph11between1and7New) {
  // Arrange
  size_t matrix[11][11] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
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
  m = new size_t *[11];
  for (int i = 0; i < 11; i++) {
    m[i] = new size_t[11];
    m[i] = matrix[i];
  }
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(11));
  EXPECT_CALL(g, getAdjacencyMatrix()).WillOnce(Return(m));
  // Act
  auto shortestPath = ga.getShortestPathBetweenVertices(g, 1, 7);
  // Assert
  ASSERT_EQ(shortestPath, 23);
}
