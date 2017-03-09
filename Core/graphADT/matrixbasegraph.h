#ifndef MATRIXBASEGRAPH_H
#define MATRIXBASEGRAPH_H
#include "basegraphadt.h"

class MatrixBaseGraph : public BaseGraphAdt {
 public:
  MatrixBaseGraph(int count);
  ~MatrixBaseGraph();

 private:
  int** matrix;
  int size;
  QList<PointInformation*> vertexInfo;

  // IGraph interface
 public:
  int getVertexCount();

  int getIncedentVertexCount(QObject* vertex);
  int getIncedentVertexCount(int vertexPosition);

  QObject* getIncedentVertex(QObject* vertex, int offset);
  QObject* getIncedentVertex(int vertexPosition, int offset);

  virtual PointInformation* getVertexInfo(QObject* vertex);
  virtual PointInformation* getVertexInfo(int vertexPosition);
};

#endif  // MATRIXBASEGRAPH_H
