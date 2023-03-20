#include "gmock.h"
#include "GraphMock.h"
#include "VertexMapForTests.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;

static bool matrixComparer(int size, distance **matrix1, distance **matrix2) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix1[i][j] != matrix2[i][j]) {
				return false;
			}
		}
	}
	return true;
}

static void deleteMatrix(int size, distance **&matrix) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph11) {
	NiceMock<GraphMock> graphMock;
	GraphAlgorithms graphAlgorithms;
	const int size = 11;
	weight matrix[size][size] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
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
	weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
								  matrix[4], matrix[5], matrix[6], matrix[7],
								  matrix[8], matrix[9], matrix[10]};
//	distance matrix2[size][size] = {
//			{0, 0, 0, 0, 0, 0, 0, 12, 4, 0, 0}, {0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 12},
//			{0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 13}, {0, 0, 0, 0, 4, 12, 0, 0, 0, 0, 0},
//			{0, 0, 0, 4, 0, 0, 0, 9, 0, 0, 0},  {0, 0, 0, 12, 0, 0, 0, 0, 0, 3, 0},
//			{0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {12, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0},
//			{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
//			{0, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0}};
//	distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
//								 matrix2[4], matrix2[5], matrix2[6], matrix2[7],
//								 matrix2[8], matrix2[9], matrix2[10]};

	VertexMapForTests vertexMapForTests(size, weightMatrix);
	EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
	EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

	// Act
	TsmResult result =
			graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

	// Assert
	ASSERT_EQ(result.distance, 253);
	ASSERT_EQ(result.vertices, (std::vector<vertex_id>{1, 8, 5, 4, 10, 6, 3, 7, 2, 11, 9, 1}));
}
