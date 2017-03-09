#include "matrixbasegraph.h"

MatrixBaseGraph::MatrixBaseGraph(int count) {
  this->size = count;
  matrix = new int*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
  }
  for (int i = 0; i < size; i++) {
    PointInformation* info = new PointInformation();
    info->pointPosition = i;
    info->pointAlias = info;
    vertexInfo.append(info);
  }
}

MatrixBaseGraph::~MatrixBaseGraph() {
  for (int i = 0; i < size; i++)
    delete[] matrix[i];
  delete[] matrix;
}

int MatrixBaseGraph::getVertexCount() {
  return size;
}

int MatrixBaseGraph::getIncedentVertexCount(QObject* vertex) {
  for (int i = 0; i < size; i++)
    if (vertexInfo.at(i) == vertex)
      return getIncedentVertexCount(i);
  return 0;
}

int MatrixBaseGraph::getIncedentVertexCount(int vertexPosition) {
  if (vertexPosition < 0 || vertexPosition >= size)
    return 0;
  int result = 0;
  for (int j = 0; j < size; j++) {
    if (matrix[vertexPosition][j] > 0)
      result++;
  }
  return result;
}

QObject* MatrixBaseGraph::getIncedentVertex(QObject* vertex, int offset) {
  for (int i = 0; i < size; i++)
    if (vertexInfo.at(i) == vertex)
      return getIncedentVertex(i, offset);
}

QObject* MatrixBaseGraph::getIncedentVertex(int vertexPosition, int offset) {
  if (vertexPosition < 0 || vertexPosition >= size)
    return nullptr;
  if (offset < 0)
    return nullptr;
  for (int i = 0; i < size; i++) {
    if (matrix[vertexPosition][i] > 0) {
      if (offset == 0)
        return vertexInfo.at(i);
      offset--;
    }
  }
  return nullptr;
}

PointInformation* MatrixBaseGraph::getVertexInfo(QObject* vertex) {
  return vertex;
}

PointInformation* MatrixBaseGraph::getVertexInfo(int vertexPosition) {
  return vertexInfo.at(vertexPosition);
}
