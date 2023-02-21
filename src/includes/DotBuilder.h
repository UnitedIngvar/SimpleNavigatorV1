#ifndef DOTBUILDER_H
#define DOTBUILDER_H

#include "s21_graph.h"

class DotBuilder {
public:
  std::string buildDotFromGraph(Graph const &graph) const;
};

#endif
