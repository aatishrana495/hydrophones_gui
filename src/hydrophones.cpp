#include "hydrophones/hydrophones.h"
#include "ui_hydrophones.h"

Hydrophones::Hydrophones(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Hydrophones) {
  ui->setupUi(this);

  ui->tdata->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
  ui->tdata->axisRect()->setRangeZoom(Qt::Horizontal);
  ui->tdata->axisRect()->setRangeZoomFactor(1.5);
  ui->tdata->xAxis->setRange(0, Range_tdata);

  ui->fdata->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
  ui->fdata->axisRect()->setRangeZoom(Qt::Horizontal);
  ui->fdata->axisRect()->setRangeZoomFactor(1.5);
  ui->fdata->xAxis->setRange(0, Range_fdata);

  ui->segment->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
  ui->segment->axisRect()->setRangeZoom(Qt::Horizontal);
  ui->segment->axisRect()->setRangeZoomFactor(1.5);
  ui->segment->xAxis->setRange(0, Range_segment);

  ui->correlation->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
  ui->correlation->axisRect()->setRangeZoom(Qt::Horizontal);
  ui->correlation->axisRect()->setRangeZoomFactor(1.5);
  ui->correlation->xAxis->setRange(0, Range_correlation);
}

Hydrophones::~Hydrophones() { delete ui; }

void Hydrophones::plotTdata(double arr[], int time[], int length) {}
void Hydrophones::plotFdata(double arr[], int time[], int length) {}
void Hydrophones::plotSegment(double arr[], int time[], int length) {}
void Hydrophones::plotCorrelation(double arr[], int time[], int length) {}
void Hydrophones::resetGraph() {
  ui->tdata->graph()->data()->clear();
  ui->fdata->graph()->data()->clear();
  ui->segment->graph()->data()->clear();
}
