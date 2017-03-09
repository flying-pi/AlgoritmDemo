#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include "../graphADT/igraph.h"

class GraphWidget : public QWidget {
  Q_OBJECT
 public:
  explicit GraphWidget(QWidget* parent = 0);

 signals:

 public slots:
};

#endif  // GRAPHWIDGET_H
