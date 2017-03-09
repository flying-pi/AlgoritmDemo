#ifndef IGRAPH_H
#define IGRAPH_H

#include <QPointF>
#include <QObject>
#include <QColor>
#include "../utils.h"

class IGraph;
class PointInformation;

class IGraph {
 public:
  virtual int getVertexCount() = 0;

  virtual int getIncedentVertexCount(QObject* vertex) = 0;
  virtual int getIncedentVertexCount(int vertexPosition) = 0;

  virtual QObject* getIncedentVertex(QObject* vertex, int offset) = 0;
  virtual QObject* getIncedentVertex(int vertexPosition, int offset) = 0;

  virtual PointInformation* getVertexInfo(QObject* vertex);
  virtual PointInformation* getVertexInfo(int vertexPosition);
};

class PointInformation : public QObject {
 public:
  PointInformation() {
    pointAlias = nullptr;
    pointPosition = 0;
    positionOnSurface = nullptr;
    color = nullptr;
  }

  ~PointInformation() {
    if (pointAlias != this)
      deleteIt(pointAlias);
    deleteIt(positionOnSurface);
    deleteIt(color);
    pointPosition = -1;
  }

  QObject* pointAlias;
  int pointPosition;
  QPointF* positionOnSurface;
  QColor* color;
  QString name = "";
};

#endif  // IGRAPH_H
