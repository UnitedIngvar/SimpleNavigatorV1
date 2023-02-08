#ifndef MATRIX_READER_H
# define MATRIX_READER_H

# include <cstddef>
# include <fstream>
# include "types.h"

class MatrixReader
{
private:
	int		readNextNumberOrThrow(
		std::string const &line,
		size_t *offset,
		std::string const &notFoundErrorMessage);

public:
	int		readMatrixSize(
		std::ifstream &file);

	weight	**readAdjacencyMatrix(
		std::ifstream &file,
		int const matrixSize);
};

#endif
