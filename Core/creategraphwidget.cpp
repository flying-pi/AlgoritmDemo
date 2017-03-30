#include "creategraphwidget.h"
#include <QPaintEvent>

CreateGraphWidget::CreateGraphWidget(QWidget* parent) : QWidget(parent) {}

void CreateGraphWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  initPainter(painter);
  painter.drawRect(0, 0, width(), height());
}

void CreateGraphWidget::initPainter(QPainter& painter) {
  painter.setBrush(QBrush(QColor(74, 20, 140)));
}

void CreateGraphWidget::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton)
    onLeftMousePress(event);
  else
    onRightMousePress(event);
}

void CreateGraphWidget::onLeftMousePress(QMouseEvent* event) {}

void CreateGraphWidget::onRightMousePress(QMouseEvent* event) {}
