#ifndef MATRIX_READER_H
# define MATRIX_READER_H

#include <cstddef>
#include <fstream>

class MatrixReader
{
private:
	size_t	readNextNumberOrThrow(
		std::string const &line,
		size_t *offset,
		std::string const &notFoundErrorMessage);

public:
	size_t	readMatrixSize(
		std::ifstream &file);

	size_t	**readAdjacencyMatrix(
		std::ifstream &file,
		size_t const matrixSize);
};

#endif
