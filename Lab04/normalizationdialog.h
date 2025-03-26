#ifndef NORMALIZATIONDIALOG_H
#define NORMALIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
class NormalizationDialog;
}

class NormalizationDialog : public QDialog
{
    Q_OBJECT

public:
    struct Result {
        double min;
        double max;
        bool use;
    };
    explicit NormalizationDialog(Result* values = nullptr, QWidget *parent = nullptr);
    ~NormalizationDialog();

    Result result();
private:
    Ui::NormalizationDialog *ui;
    Result _result;

    void confirm();
};

#endif // NORMALIZATIONDIALOG_H
