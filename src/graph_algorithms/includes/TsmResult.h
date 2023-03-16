#pragma once

#ifndef TSMRESULT_H
#define TSMRESULT_H

struct TsmResult {
  // массив с искомым маршрутом (с порядком обхода вершин)
  std::vector<int> vertices;
  double distance;  // длина маршрута
};

#endif
