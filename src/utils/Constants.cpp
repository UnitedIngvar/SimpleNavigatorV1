#include "Constants.h"

const char *Constants::getWhiteSpaces()
{
	static const char whiteSpaces[] = {' ', '\n', '\t', '\v', '\b', '\r', '\f', '\a'};
	return whiteSpaces;
}

const char *Constants::getDigits()
{
	static const char whiteSpaces[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};
	return whiteSpaces;
}
