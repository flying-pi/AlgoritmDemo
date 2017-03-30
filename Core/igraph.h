#ifndef IGRAPH_H
#define IGRAPH_H

#include <QObject>

enum EChangeType { eChange, eRemove, eAdd };

class IGraph : public QObject {
  Q_OBJECT

 public:
  IGraph() {}
  virtual ~IGraph() {}
  virtual int getVertexCount() = 0;
  virtual int getVertexByIndex(int index) = 0;
  virtual int getConnection(int vetex) = 0;
  virtual int getIncendentVertex(int vertex, int offset) = 0;
  virtual bool isAge(int vertex1, int vertex2) = 0;
  virtual bool isOriented() { return false; }
  virtual QString toString() { return ""; }
  virtual void loadFromString(QString str) {}
  virtual int addVertex() = 0;
  virtual void removeVertex(int v) = 0;
  virtual void addAge(int vertex1, int vertex2) = 0;
  virtual void removeAge(int vertex1, int vertex2) = 0;
  virtual bool isVertex(int v) = 0;
  virtual void setIsOriented(bool oriented) = 0;

 signals:
  void onvertexChanged(int vertex, EChangeType type = eChange);
  void onAgeChanged(int vertex1, int vertex2, EChangeType type = eChange);
};

#endif  // IGRAPH_H
