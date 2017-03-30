#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creategraphform.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_createGraph_clicked() {
  CreateGraphForm* form = new CreateGraphForm();
  form->show();
}
