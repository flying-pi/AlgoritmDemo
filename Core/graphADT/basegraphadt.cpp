#include "basegraphadt.h"

int BaseGraphAdt::getVertexCount() {}

int BaseGraphAdt::getIncedentVertexCount(QObject* vertex) {}

int BaseGraphAdt::getIncedentVertexCount(int vertexPosition) {}

QObject* BaseGraphAdt::getIncedentVertex(QObject* vertex, int offset) {}

QObject* BaseGraphAdt::getIncedentVertex(int vertexPosition, int offset) {}

PointInformation* BaseGraphAdt::getVertexInfo(QObject* vertex) {}

PointInformation* BaseGraphAdt::getVertexInfo(int vertexPosition) {}
