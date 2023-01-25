#include <map>

#include "VertexMapBuilder.hpp"
#include "gmock.h"
#include "graph_mocks/GraphMock.h"
#include "graph_mocks/vertexMapForTests.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;

struct breadthFirstSearchTests : public testing::Test {
  size_t **m{};
  NiceMock<GraphMock> g;
  GraphAlgorithms ga;

  void SetUp() override {}

  void TearDown() override { delete[] m; }
};

TEST_F(breadthFirstSearchTests, Graph5startFrom1) {
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
  vertexMapForTests vertexMapForTests(5, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  for (size_t i = 1; i <= 5; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }
  // Act
  auto bfs = ga.breadthFirstSearch(g, 1);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{1, 2, 4, 3, 5}));
}

TEST_F(breadthFirstSearchTests, Graph5startFrom2) {
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

  vertexMapForTests vertexMapForTests(5, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  for (size_t i = 1; i <= 5; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 2);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{2, 1, 3, 4, 5}));
}

TEST_F(breadthFirstSearchTests, Graph5startFrom3) {
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

  vertexMapForTests vertexMapForTests(5, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  for (size_t i = 1; i <= 5; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 3);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{3, 2, 1, 4, 5}));
}

TEST_F(breadthFirstSearchTests, Graph5startFrom4) {
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

  vertexMapForTests vertexMapForTests(5, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  for (size_t i = 1; i <= 5; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 4);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{4, 1, 2, 5, 3}));
}

TEST_F(breadthFirstSearchTests, Graph5startFrom5) {
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

  vertexMapForTests vertexMapForTests(5, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(5));
  for (size_t i = 1; i <= 5; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 5);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{5, 4, 1, 2, 3}));
}

TEST_F(breadthFirstSearchTests, Graph7startFrom1) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6},
						 {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5},
						 {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},
						 {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }

  vertexMapForTests vertexMapForTests(7, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  for (size_t i = 1; i <= 7; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 1);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{1, 2, 3, 7, 4, 5, 6}));
}

TEST_F(breadthFirstSearchTests, Graph7startFrom2) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6},
						 {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5},
						 {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},
						 {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }

  vertexMapForTests vertexMapForTests(7, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  for (size_t i = 1; i <= 7; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 2);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{2, 1, 3, 4, 7, 5, 6}));
}

TEST_F(breadthFirstSearchTests, Graph7startFrom3) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6},
						 {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5},
						 {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},
						 {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }

  vertexMapForTests vertexMapForTests(7, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  for (size_t i = 1; i <= 7; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 3);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{3, 1, 2, 4, 5, 6, 7}));
}

TEST_F(breadthFirstSearchTests, Graph7startFrom4) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6},
						 {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5},
						 {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},
						 {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }

  vertexMapForTests vertexMapForTests(7, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  for (size_t i = 1; i <= 7; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 4);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{4, 2, 3, 5, 1, 6, 7}));
}

TEST_F(breadthFirstSearchTests, Graph7startFrom7) {
  // Arrange
  size_t matrix[7][7] = {{0, 3, 10, 0, 0, 0, 6},
						 {3, 0, 5, 8, 0, 0, 0},
                         {10, 5, 0, 2, 6, 8, 5},
						 {0, 8, 2, 0, 3, 0, 0},
                         {0, 0, 6, 3, 0, 7, 0},
						 {0, 0, 8, 0, 7, 0, 4},
                         {6, 0, 5, 0, 0, 4, 0}};
  m = new size_t *[7];
  for (int i = 0; i < 7; i++) {
    m[i] = new size_t[7];
    m[i] = matrix[i];
  }

  vertexMapForTests vertexMapForTests(7, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(7));
  for (size_t i = 1; i <= 7; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  auto bfs = ga.breadthFirstSearch(g, 7);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{7, 1, 3, 6, 2, 4, 5}));
}

TEST_F(breadthFirstSearchTests, Graph11startFrom1) {
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

  vertexMapForTests vertexMapForTests(11, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(11));
  for (size_t i = 1; i <= 11; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }
  // Act
  auto bfs = ga.breadthFirstSearch(g, 1);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));
}

TEST_F(breadthFirstSearchTests, Graph11startFrom8) {
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
  vertexMapForTests vertexMapForTests(11, m);
  EXPECT_CALL(g, getMatrixSize()).WillOnce(Return(11));
  for (size_t i = 1; i <= 11; i++) {
    EXPECT_CALL(g, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }
  // Act
  auto bfs = ga.breadthFirstSearch(g, 8);
  // Assert
  ASSERT_EQ(bfs, (std::vector<int>{8, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11}));
}
