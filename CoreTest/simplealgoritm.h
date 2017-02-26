#ifndef SIMPLEALGORITM_H
#define SIMPLEALGORITM_H

#include "basealgoritm.h"

class AlgoritmStep : public QObject {
 public:
  AlgoritmStep(int result, int increment) {
    this->resutl = result;
    this->increment = increment;
  }

  int resutl;
  int increment;
};

class SimpleAlgoritm : public BaseAlgoritm {
 public:
  SimpleAlgoritm();
  int mull(int a, int b);
};

#endif  // SIMPLEALGORITM_H
