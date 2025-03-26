#include "normalizationdialog.h"
#include "ui_normalizationdialog.h"

NormalizationDialog::NormalizationDialog(NormalizationDialog::Result* result, QWidget *parent)
    : QDialog(parent) , ui(new Ui::NormalizationDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &NormalizationDialog::confirm);

    if (result)
    {
        ui->min->setValue(result->min);
        ui->max->setValue(result->max);
        ui->use->setChecked(result->use);
    }
}

NormalizationDialog::~NormalizationDialog()
{
    delete ui;
}

NormalizationDialog::Result NormalizationDialog::result()
{
    return _result;
}

void NormalizationDialog::confirm()
{
    _result = {
        .min = ui->min->value(),
        .max = ui->max->value(),
        .use = ui->use->isChecked()
    };
    accept();
}
