#include "MatrixReader.h"
#include "Constants.h"

// TODO: ВАЖНО! Может ли вес быть отрицательным?

size_t	MatrixReader::readNextNumberOrThrow(std::string const &line, size_t *offset, std::string const &notFoundErrorMessage)
{
	// Проверяем, что в строке только числа
	if (!std::all_of(line.begin(), line.end(),
		[](char const& ch){ return ::isdigit(ch) || ::isspace(ch); }))
	{
		throw std::invalid_argument("Adjecency matrix should contain only positive numbers");
	}

	// Получаем позицию следующего числа
	const char *digits = Constants::getDigits();
	size_t numberPosition = line.find_first_of(digits, *offset);
	if (numberPosition == std::string::npos)
	{
		throw std::invalid_argument(notFoundErrorMessage);
	}

	// Получаем длину числа
	size_t positionAfterNumber = line.find_first_not_of(digits, numberPosition);
	size_t numberLength = positionAfterNumber == std::string::npos
		? line.size() - numberPosition
		: positionAfterNumber - numberPosition;

	// Получаем строку, содержащую число
	std::string numberStr = line.substr(numberPosition, numberLength);

	// TODO: хорошо бы придумать что-то поэлегантнее
	size_t number;
	try
	{
		number = std::stoul(numberStr);
	}
	catch(const std::exception& e)
	{
		throw std::invalid_argument(numberStr + " is more than maximum value of size_t number");
	}

	if (number <= 0)
	{
		throw std::invalid_argument("Numbers in adjecency matrix should have only positive values");
	}

	// двигаем смещение по строке на позицию после текущего числа
	*offset = numberPosition + numberLength + 1;
	return number;
}

size_t	MatrixReader::readMatrixSize(std::ifstream &file)
{
	std::string line;
	size_t matrixSize;
	bool matrixSizeFound = false;

	while (getline(file, line))
	{
		// Cчитываем строки, пока не появится текст.
		if (std::all_of(line.begin(), line.end(), ::isspace))
		{
			continue;
		}

		// Получаем размер матрицы
		size_t offset = 0;
		matrixSize = readNextNumberOrThrow(line, &offset,
			"Adjecency matrix should contain only positive numbers");

		// Бросаем исключение, если есть какое-то число после размера матрицы.
		if (line.find_first_not_of(' ', offset) != std::string::npos)
		{
			throw std::invalid_argument("Invalid format of adjecency matrix");
		}

		matrixSizeFound = true;
		break;
	}

	if (!matrixSizeFound)
	{
		throw std::invalid_argument("Invalid format of adjecency matrix: matrix size not found");
	}

	return matrixSize;
}

size_t	**MatrixReader::readAdjacencyMatrix(std::ifstream &file, size_t const matrixSize)
{
	size_t **matrix = new size_t*[matrixSize];
	for (size_t i = 0; i < matrixSize; i++)
	{
		matrix[i] = new size_t[matrixSize];
	}

	for (size_t i = 0; i < matrixSize; i++)
	{
		if (file.peek() == EOF)
		{
			throw std::invalid_argument("invalid number of rows in the adjecency matrix");
		}

		std::string line;
		getline(file, line);
		for (size_t j = 0; j < matrixSize; j++)
		{
			size_t offset = 0;
			size_t number = readNextNumberOrThrow(line, &offset,
				"invalid number of columns in the adjecency matrix");
			matrix[i][j] = number;
		}
	}

	return matrix;
}
