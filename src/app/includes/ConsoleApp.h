#ifndef CONSOLE_APP_H
# define CONSOLE_APP_H

#include <string>
#include "s21_graph.h"

enum command {
	loadGraph = 1,
	breadthFirstSearch = 2,
	depthFirstSearch = 3,
	shortestBetweenTwo = 4,
	shortestBetweenAll = 5,
	leastSpanningTree = 6,
	salesmanProblem = 7,
	quit = 8
};

#define MAX_COMMAND quit
#define MIN_COMMAND loadGraph

class ConsoleApp {
private:
	bool		tryParseIntFromInput(int *numPthr);
	command getCommand();
	void executeCommand(command command, Graph &graph);

public:
	void start();
};

#endif
