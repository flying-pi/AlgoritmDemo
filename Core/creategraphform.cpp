#include "creategraphform.h"
#include "ui_creategraphform.h"

CreateGraphForm::CreateGraphForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGraphForm)
{
    ui->setupUi(this);
}

CreateGraphForm::~CreateGraphForm()
{
    delete ui;
}
