#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QPainter>

class GraphPainter;

class GraphWidget : public QWidget {
  Q_OBJECT
 public:
  explicit GraphWidget(QWidget* parent = 0);
  ~GraphWidget();

 signals:

 public slots:

 public:
  QPaintEngine* paintEngine() const;
};

#endif  // GRAPHWIDGET_H
