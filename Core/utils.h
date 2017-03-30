#ifndef UTILS_H
#define UTILS_H

#include <Qt>

#define deleteIt(x) \
  if (x) {          \
    delete x;       \
    x = nullptr;    \
  }

#define i(x) qInfo() << #x;

#endif  // UTILS_H
