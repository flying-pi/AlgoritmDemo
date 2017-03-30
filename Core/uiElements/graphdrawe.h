#ifndef GRAPHDRAWE_H
#define GRAPHDRAWE_H

#include "../igraph.h"
#include <QWidget>
#include <QPointF>

class GraphDrawe {
 public:
  GraphDrawe(IGraph* graph);
  void bindWidget(QWidget* canvasProvider);
  void draw();

  virtual QString toString() { return ""; }
  virtual void loadFromString(QString str) {}

  void updayeConnectionPath(QPointF& p1, QPointF& p2, QPointF& p3);

 protected:
  virtual void drawVertex(int position);
  virtual void drawAge(int start, int end, bool isOriented = false);

 protected slots:
  void onvertexChanged(int vertex, EChangeType type = eChange);
  void onAgeChanged(int vertex1, int vertex2, EChangeType type = eChange);

 private:
  IGraph* graph;
  QWidget* canvasProvider;
};

#endif  // GRAPHDRAWE_H
