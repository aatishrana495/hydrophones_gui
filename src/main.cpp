#include "hydrophones/hydrophones.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Hydrophones w;
  w.show();
  double arr[1000];
  int time_arr[1000];
  for (int i = 0; i < 1000; i++) {
    arr[i] = i;
    time_arr[i] = i;
  }
  w.plotTdata(arr, time_arr, 1000);
  w.plotFdata(arr, time_arr, 1000);
  w.plotSegment(arr, time_arr, 1000);
  w.plotCorrelation(arr, time_arr, 1000);
  return a.exec();
}
