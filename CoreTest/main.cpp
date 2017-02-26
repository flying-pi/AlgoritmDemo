#include <QCoreApplication>
#include "simplealgoritm.h"
#include "basealgoritm.h"
#include <QDebug>

class Listener : public AlgStepListener<AlgoritmStep> {
 public:
  void onNextStep(AlgoritmStep* data) {
    qDebug() << "step info ::\tresult : " << data->resutl
             << "\tincriment :" << data->increment;
  }
};

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);
  SimpleAlgoritm alg;
  //  alg.setTimerInterval(300);
  Listener* listener = new Listener();
  alg.setStepListener((AlgStepListener<QObject>*)listener);
  qDebug() << alg.mull(50, 5);
  return a.exec();
}
