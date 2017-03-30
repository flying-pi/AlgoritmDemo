#ifndef CREATEGRAPHWIDGET_H
#define CREATEGRAPHWIDGET_H

#include <QWidget>
#include <QPainter>

class CreateGraphWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CreateGraphWidget(QWidget* parent = 0);

 signals:

 public slots:

 protected:
  void paintEvent(QPaintEvent* event) override;
  void mousePressEvent(QMouseEvent* event);

  void onLeftMousePress(QMouseEvent* event);
  void onRightMousePress(QMouseEvent* event);

 private:
  void initPainter(QPainter& painter);
};

#endif  // CREATEGRAPHWIDGET_H
