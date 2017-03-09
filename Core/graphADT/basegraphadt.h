#ifndef BASEGRAPHADT_H
#define BASEGRAPHADT_H

#include "igraph.h"

class BaseGraphAdt : public IGraph {
 public:
  // IGraph interface
 public:
  virtual int getVertexCount();

  virtual int getIncedentVertexCount(QObject* vertex);
  virtual int getIncedentVertexCount(int vertexPosition);

  virtual QObject* getIncedentVertex(QObject* vertex, int offset);
  virtual QObject* getIncedentVertex(int vertexPosition, int offset);

  virtual PointInformation* getVertexInfo(QObject* vertex);
  virtual PointInformation* getVertexInfo(int vertexPosition);
};

#endif  // BASEGRAPHADT_H
