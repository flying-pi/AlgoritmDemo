#include "graphdrawe.h"

GraphDrawe::GraphDrawe(IGraph* _graph)
    : graph(_graph), canvasProvider(nullptr) {}

void GraphDrawe::bindWidget(QWidget* canvasProvider) {
  this->canvasProvider = canvasProvider;
}

void GraphDrawe::draw() {
  if (canvasProvider == nullptr)
    return;
  for (int i = 0; i < graph->getVertexCount(); i++) {
    drawVertex(i);
    for (int a = 0; a < graph->getConnection(i); a++) {
      drawAge(i, graph->getIncendentVertex(i, a), graph->isOriented());
    }
  }
}

void GraphDrawe::drawVertex(int position) {}

void GraphDrawe::drawAge(int start, int end, bool isOriented) {}

void GraphDrawe::onvertexChanged(int vertex, EChangeType type) {}

void GraphDrawe::onAgeChanged(int vertex1, int vertex2, EChangeType type) {}
