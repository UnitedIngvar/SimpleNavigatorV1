#include <map>

#include "gmock.h"
#include "gtest.h"
#include "mocks/MatrixReaderMock.h"
#include "mocks/VertexMapBuilderMock.h"
#include "s21_graph.h"

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;

TEST(GraphTests, GetVertexById_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.getVertexById(1), std::invalid_argument);
}

TEST(GraphTests, GetMatrixSize_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.getMatrixSize(), std::invalid_argument);
}

TEST(GraphTests, GetAdjacencyMatrix_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.getAdjacencyMatrix(), std::invalid_argument);
}

TEST(GraphTests, LoadGraphFromFile_GraphHasValidValues) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  std::string filename = "./unitTests/graph/testData/ExampleMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());

  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  file.close();
  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock);

  // Act
  graph.loadGraphFromFile(filename);

  // Assert
  ASSERT_EQ(size, graph.getMatrixSize());

  auto actualMatrix = graph.getAdjacencyMatrix();
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }

  for (size_t i = 1; i <= size; i++) {
    ASSERT_EQ(*expectedVertexMap[i], graph.getVertexById(i));
  }
}

TEST(GraphTests, GetVertexById_IndexIsNotPresent_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  std::string filename = "./unitTests/graph/testData/ExampleMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());

  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  file.close();
  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock);
  graph.loadGraphFromFile(filename);

  // Act

  // Assert
  ASSERT_THROW(graph.getVertexById(size + 1), std::out_of_range);
}
