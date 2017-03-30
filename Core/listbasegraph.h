#ifndef LISTBASEGRAPH_H
#define LISTBASEGRAPH_H

#include "igraph.h"
#include <QList>

class ListBaseGraph : public IGraph {
 public:
  ListBaseGraph(bool oriented);

  // IGraph interface
 public:
  int getVertexCount();
  int getVertexByIndex(int index);
  int getConnection(int vetex);
  int getIncendentVertex(int vertex, int offset);
  bool isAge(int vertex1, int vertex2);
  bool isOriented();
  QString toString();
  void loadFromString(QString str);
  int addVertex();
  void removeVertex(int v);
  void addAge(int vertex1, int vertex2);
  void removeAge(int vertex1, int vertex2);
  bool isVertex(int v);

  void setIsOriented(bool oriented);

 private:
  bool oriented;

  QList<QList<int>*>* connectionList;
  QList<int> vertexList;
  int lastAddedVertex = 0;
};

#endif  // LISTBASEGRAPH_H
