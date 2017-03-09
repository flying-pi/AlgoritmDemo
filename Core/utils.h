#ifndef UTILS_H
#define UTILS_H

#define deleteIt(x) \
  if (x) {          \
    delete x;       \
    x = nullptr;    \
  }

#endif  // UTILS_H
