#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->zeroButton, &QPushButton::clicked, this, [this]() {push('0');});
    connect(ui->oneButton, &QPushButton::clicked, this, [this]() {push('1');});
    connect(ui->twoButton, &QPushButton::clicked, this, [this]() {push('2');});
    connect(ui->threeButton, &QPushButton::clicked, this, [this]() {push('3');});
    connect(ui->fourButton, &QPushButton::clicked, this, [this]() {push('4');});
    connect(ui->fiveButton, &QPushButton::clicked, this, [this]() {push('5');});
    connect(ui->sixButton, &QPushButton::clicked, this, [this]() {push('6');});
    connect(ui->sevenButton, &QPushButton::clicked, this, [this]() {push('7');});
    connect(ui->eightButton, &QPushButton::clicked, this, [this]() {push('8');});
    connect(ui->nineButton, &QPushButton::clicked, this, [this]() {push('9');});
    connect(ui->pointButton, &QPushButton::clicked, this, [this]() {push('.');});
    connect(ui->addButton, &QPushButton::clicked, this, [this]() {push('+');});
    connect(ui->minusButton, &QPushButton::clicked, this, [this]() {push('-');});
    connect(ui->divideButton, &QPushButton::clicked, this, [this]() {push('/');});
    connect(ui->multiplyButton, &QPushButton::clicked, this, [this]() {push('*');});
    connect(ui->openBracket, &QPushButton::clicked, this, [this]() {push('(');});
    connect(ui->closeBracket, &QPushButton::clicked, this, [this]() {push(')');});
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::del);
    connect(ui->equalityButton, &QPushButton::clicked, this, &MainWindow::calculate);

    updateUI();
}

void showError(std::exception* exception)
{
    QMessageBox message;
    message.setText(exception->what());
    message.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push(char character)
{
    facade.setExpression((ui->resultWindow->text() + character).toStdString());
    updateUI();
}

void MainWindow::clear()
{
    facade.setExpression("");
    updateUI();
}

void MainWindow::del()
{
    facade.setExpression(ui->resultWindow->text().mid(0, ui->resultWindow->text().size() - 1).toStdString());
    updateUI();
}

void MainWindow::updateUI()
{
    ui->zeroButton->setEnabled(!facade.isCommands());
    ui->oneButton->setEnabled(!facade.isCommands());
    ui->twoButton->setEnabled(!facade.isCommands());
    ui->threeButton->setEnabled(!facade.isCommands());
    ui->fourButton->setEnabled(!facade.isCommands());
    ui->fiveButton->setEnabled(!facade.isCommands());
    ui->sixButton->setEnabled(!facade.isCommands());
    ui->sevenButton->setEnabled(!facade.isCommands());
    ui->eightButton->setEnabled(!facade.isCommands());
    ui->nineButton->setEnabled(!facade.isCommands());
    ui->pointButton->setEnabled(!facade.isCommands());
    ui->addButton->setEnabled(!facade.isCommands());
    ui->minusButton->setEnabled(!facade.isCommands());
    ui->divideButton->setEnabled(!facade.isCommands());
    ui->multiplyButton->setEnabled(!facade.isCommands());
    ui->openBracket->setEnabled(!facade.isCommands());
    ui->closeBracket->setEnabled(!facade.isCommands());
    ui->clearButton->setEnabled(!facade.isCommands());
    ui->deleteButton->setEnabled(!facade.isCommands());
    ui->equalityButton->setEnabled(!facade.isCommands());
    ui->resultWindow->setText(QString::fromStdString(facade.getExpression()));
}

void MainWindow::calculate()
{
    try
    {
        facade.calculate();
    }
    catch (InvalidExpressionException& err)
    {
        showError(&err);
    }
    updateUI();
}
