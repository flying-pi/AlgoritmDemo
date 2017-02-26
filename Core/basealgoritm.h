#ifndef BASEALGORITM_H
#define BASEALGORITM_H

#include <QObject>
#include <QQueue>
#include <QTimer>

#define forC(init, check, inc, saver, body)                            \
  do {                                                                 \
    bool isBreak = false;                                              \
    init;                                                              \
    while (true) {                                                     \
      int macrosIterator;                                              \
      for (macrosIterator = 0; macrosIterator < 2; macrosIterator++) { \
        if (macrosIterator == 1)                                       \
          break;                                                       \
        body;                                                          \
      }                                                                \
      inc;                                                             \
      saver;                                                           \
      if (!(check))                                                    \
        break;                                                         \
      if (macrosIterator == 0)                                         \
        break;                                                         \
    }                                                                  \
  } while (0)

template <typename T>
class AlgStepListener {
 public:
  virtual void onNextStep(T* data) = 0;
};

class BaseAlgoritm : public QObject {
  Q_OBJECT

 public:
  BaseAlgoritm() {
    listener = nullptr;
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimerTick()));
    setTimerInterval(30);
  }

  void setStepListener(AlgStepListener<QObject>* listener) {
    this->listener = listener;
  }

  void setTimerInterval(int interval) {
    timer.stop();
    timer.start(interval);
  }

  void beginTrackSteps() { isTrackSteps = true; }

  void stopTrackSteps() { isTrackSteps = false; }

 protected slots:
  void onTimerTick() {
    if (listener) {
      if (states.size() > 0)
        listener->onNextStep(states.takeFirst());
    }
  }

 protected:
  QTimer timer;
  bool isTrackSteps = true;
  QQueue<QObject*> states;

  AlgStepListener<QObject>* listener;
};

#endif  // BASEALGORITM_H
