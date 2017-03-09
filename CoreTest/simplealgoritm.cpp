#include "simplealgoritm.h"

SimpleAlgoritm::SimpleAlgoritm() {}

#define forI(init, check, inc, body)                                         \
  forC(init, check, inc, { states.push_back(new AlgoritmStep(result, a)); }, \
       body);

int SimpleAlgoritm::mull(int a, int b) {
  int result = 0;
  forI(b, b > 0, b--, {
    //    if (result > 100)
    //      break;
    result += a;
  });
  return result;
}
