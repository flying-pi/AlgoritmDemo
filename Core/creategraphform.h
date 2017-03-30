#ifndef CREATEGRAPHFORM_H
#define CREATEGRAPHFORM_H

#include <QWidget>

namespace Ui {
class CreateGraphForm;
}

class CreateGraphForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGraphForm(QWidget *parent = 0);
    ~CreateGraphForm();

private:
    Ui::CreateGraphForm *ui;
};

#endif // CREATEGRAPHFORM_H
