#include "listbasegraph.h"

ListBaseGraph::ListBaseGraph(bool oriented) : oriented(oriented) {
  connectionList = new QList<QList<int>*>();
}

int ListBaseGraph::getVertexCount() {
  return vertexList.size();
}

int ListBaseGraph::getVertexByIndex(int index) {
  if (index >= vertexList.size())
    return -1;
  return vertexList.at(index);
}

int ListBaseGraph::getConnection(int vetex) {
  return connectionList->size() <= vetex ? -1
                                         : connectionList->at(vetex)->size();
}

int ListBaseGraph::getIncendentVertex(int vertex, int offset) {
  if (vertex < 0)
    return -1;
  if (connectionList->size() <= vertex)
    return -1;
  if (connectionList->at(vertex)->size() <= offset)
    return -1;
  return connectionList->at(vertex)->at(offset);
}

bool ListBaseGraph::isAge(int vertex1, int vertex2) {
  if (connectionList->size() > vertex1) {
    for (int i = 0; i < connectionList->at(vertex1)->size(); i++) {
      if (connectionList->at(vertex1)->at(i) == vertex2)
        return true;
    }
    return false;
  }
  return false;
}

bool ListBaseGraph::isOriented() {
  return oriented;
}

QString ListBaseGraph::toString() {
  return "";
}

void ListBaseGraph::loadFromString(QString str) {}

int ListBaseGraph::addVertex() {
  connectionList->append(new QList<int>);
  vertexList.append(lastAddedVertex++);
  return lastAddedVertex - 1;
}

void ListBaseGraph::removeVertex(int v) {
  if (vertexList.indexOf(v) < 0)
    return;
  if (!isOriented()) {
    auto connection = connectionList->at(vertexList.indexOf(v));
    for (int i = 0; i < connection->size(); i++) {
      connectionList->at(vertexList.indexOf(connection->at(i)))->removeAll(v);
    }
  }
  delete connectionList->at(vertexList.indexOf(v));
  connectionList->removeAt(vertexList.indexOf(v));
  vertexList.removeAt(vertexList.indexOf(v));
}

void ListBaseGraph::addAge(int vertex1, int vertex2) {
  if (isVertex(vertex1) && isVertex(vertex2)) {
    connectionList->at(vertex1)->append(vertex2);
    if (!isOriented()) {
      connectionList->at(vertex2)->append(vertex1);
    }
  }
}

void ListBaseGraph::removeAge(int vertex1, int vertex2) {
  if (!(isVertex(vertex1) && isVertex(vertex2)))
    return;
  connectionList->at(vertex1)->removeOne(vertex2);
  if (!isOriented())
    connectionList->at(vertex2)->removeOne(vertex1);
}

bool ListBaseGraph::isVertex(int v) {
  if (v < vertexList.size())
    return vertexList.indexOf(v) > -1;
  return false;
}

void ListBaseGraph::setIsOriented(bool oriented) {
  this->oriented = oriented;
}
