#ifndef COLORALGORITHM_GLOBAL_H
#define COLORALGORITHM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COLORALGORITHM_LIBRARY)
#  define COLORALGORITHMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COLORALGORITHMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // COLORALGORITHM_GLOBAL_H
