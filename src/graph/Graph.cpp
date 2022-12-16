#include "s21_graph.h"

Vertex	const &Graph::getVertexById(vertex_id vertexId)
{
	return *(new Vertex()); // TODO: mock
}

size_t	Graph::getMatrixSize(std::ifstream &file)
{
	std::string line;
	size_t	matrixSize;
	bool	matrixSizeFound;

	while (getline(file, line))
	{
		char whiteSpaces[] = {' ', '\n', '\t', '\v', '\b', '\r', '\f', '\a'};
		size_t firstNumberPosition = line.find_first_not_of(whiteSpaces);
		if (firstNumberPosition == std::string::npos)
			continue;

		size_t numberLength = line.find_first_of(whiteSpaces, firstNumberPosition) - firstNumberPosition;

		std::string matrixSizeStr = line.substr(firstNumberPosition, numberLength);
		if (!std::all_of(matrixSizeStr.begin(), matrixSizeStr.end(), ::isdigit))
			throw std::invalid_argument("Adjecency matrix should contain only numbers");

		matrixSize = std::stol(matrixSizeStr);
		if (matrixSize <= 0)
			throw std::invalid_argument("Numbers in adjecency matrix should have only positive values");

		if (line.find_first_not_of(whiteSpaces, firstNumberPosition + numberLength) != std::string::npos)
			throw std::invalid_argument("Invalid format of adjecency matrix");

		matrixSizeFound = true;
		break;
	}

	if (!matrixSizeFound)
		throw std::invalid_argument("Invalid format of adjecency matrix");

	return matrixSize;
}

void	Graph::loadGraphFromFile(std::string const &filename)
{
	// std::ifstream file(filename);
	// if (!file.good())
	// {
	// 	file.clear();
	// 	throw std::invalid_argument("file could not be opened");
	// }

	// // 1. Cчитываем строки, пока не появится текст. Постоянно убеждаемся, что перед нами именно число.
	// int32_t matrixSize = getMatrixSize(file);

	// std::cout << matrixSize << std::endl;
	// return;
	// // 2. Первое число считываем - это размерность матрицы (n). Доходим до конца.
	// // Если есть еще число - бросаем исключение - invalid format
	// // 3. Начинаем считывать мартицу смежности. Задаем двумерный массив [n][n].
	// // Числа должны быть >= 0
	// // На каждой строке должно быть не меньше n чисел. Если больше - пофигу.
	// // В матрице не должно быть меньше n строк. Если их больше - пофигу, не дочитываем до конца.
}
void	Graph::exportGraphToDot(std::string const &filename)
{
}

Graph::~Graph()
{
	if (_matrixInitialized)
	{
		// TODO: free the matrix;
	}
}
