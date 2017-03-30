#include <QString>
#include <QtTest>
#include "igraph.h"
#include "listbasegraph.h"
#include "utils.h"

class BaseGraphTest : public QObject {
  Q_OBJECT

 public:
  BaseGraphTest();

 private Q_SLOTS:
  void testCreation();
  void checkVertexAdding();
  void checkAge();

 protected:
  virtual IGraph* getGraph(bool isOriented = false) = 0;
};

BaseGraphTest::BaseGraphTest() {}

void BaseGraphTest::testCreation() {
  IGraph* graph = getGraph();
  qInfo() << "check vertex count........";
  QCOMPARE(graph->getVertexCount(), 0);
  qInfo() << "check connection count for vertex........";
  QCOMPARE(graph->getConnection(1), -1);
  qInfo() << "check getting incendent vertex........";
  QCOMPARE(graph->getIncendentVertex(1, 2), -1);
  qInfo() << "check is age........";
  QCOMPARE(graph->isAge(1, 2), false);
  qInfo() << "check is vertex........";
  QCOMPARE(graph->isVertex(1), false);
}

void BaseGraphTest::checkVertexAdding() {
  IGraph* graph = getGraph();
  QCOMPARE(graph->getVertexCount(), 0);
  i("check adding new vertex");
  QCOMPARE(graph->addVertex(), 0);
  i("check adding one more new vertex");
  QCOMPARE(graph->addVertex(), 1);
  i("adding 100 new vetex");
  for (int i = 0; i < 10; i++)
    graph->addVertex();
  i("checking size of graph");
  QCOMPARE(graph->getVertexCount(), 12);
  QCOMPARE(graph->isVertex(10), true);
  QCOMPARE(graph->isVertex(100), false);
  graph->removeVertex(10);
  QCOMPARE(graph->getVertexCount(), 11);
  QCOMPARE(graph->isVertex(10), false);
  QCOMPARE(graph->addVertex(), 12);
}

void BaseGraphTest::checkAge() {
  IGraph* graph = getGraph(false);
  i(adding 100 vertex);
  for (int i = 0; i < 100; i++) {
    graph->addVertex();
  }
  i(adding connection form 1 vertex to other);
  for (int i = 1; i < 100; i++)
    graph->addAge(0, i);

  QCOMPARE(graph->isAge(0, 1), true);
  QCOMPARE(graph->isAge(1, 0), true);
  QCOMPARE(graph->isAge(4, 1), false);

  QCOMPARE(graph->getConnection(0), 99);
  QCOMPARE(graph->getConnection(1), 1);

  graph->removeVertex(10);
  QCOMPARE(graph->getConnection(0), 98);

  int vetex = graph->addVertex();
}

class ListBaseGraphTest : public BaseGraphTest {
  Q_OBJECT
 public:
  ListBaseGraphTest() {}

  // BaseGraphTest interface
 protected:
  IGraph* getGraph(bool isOriented);
};

IGraph* ListBaseGraphTest::getGraph(bool isOriented) {
  return new ListBaseGraph(isOriented);
}

QTEST_APPLESS_MAIN(ListBaseGraphTest)

#include "basegraphtest.moc"
