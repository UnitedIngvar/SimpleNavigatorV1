#include "gtest.h"
#include "MatrixReader.h"
#include <fstream>
#include <filesystem>
#include <functional>

// TODO: решить, что мы делаем с отрицательными числами, и добавить тест на это.

TEST(MatrixReaderTests, ReadMatrixSize_WithExmapleMap)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/ExampleMap.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act
	auto actualMatrixSize = matrixReader.readMatrixSize(file);

	// Assert
	size_t expectedMatrixSize = 11;
	ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithMultipleEmptyRowsBeforeMatrixSize)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/MatrixWithMultipleEmptyLinesBeforeSize.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act
	auto actualMatrixSize = matrixReader.readMatrixSize(file);

	// Assert
	size_t expectedMatrixSize = 11;
	ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithMultipleEmptyRowsAfterMatrixSize_ReturnsValidValue)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/MatrixWithMultipleEmptyLinesAfterSize.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act
	auto actualMatrixSize = matrixReader.readMatrixSize(file);

	// Assert
	size_t expectedMatrixSize = 11;
	ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithWhiteSpacesBeforeMatrixSize_ReturnsValidValue)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/MatrixWithWhiteSpacesBeforeSize.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act
	auto actualMatrixSize = matrixReader.readMatrixSize(file);

	// Assert
	size_t expectedMatrixSize = 11;
	ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests, ReadMatrixSize_InvalidMatrixWithSymbolsBeforeSize_ThrowsException)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/InvalidMatrixWithSymbolsBeforeSize.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act

	// Assert
	ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadMatrixSize_InvalidMatrixWithSymbolsAfterSize_ThrowsException)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/InvalidMatrixWithSymbolsAfterSize.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act

	// Assert
	ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithSizeMoreThanMaxSize_ThrowsException)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/InvalidMatrixWithSizeMoreThanMaxSize.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act

	// Assert
	ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithMultipleNumbersOnTheSizeRow_ThrowsException)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/InvalidMatrixWithMultipleNumbersOnTheSizeRow.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act

	// Assert
	ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithEmptyMatrix_ThrowsException)
{
	// Arrange
	const std::string pathToFile = "./unitTests/graph/testData/InvalidEmptyMatrix.txt";
	std::ifstream file;
	file.open(pathToFile);
	ASSERT_TRUE(file);
	MatrixReader matrixReader;

	// Act

	// Assert
	ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}
