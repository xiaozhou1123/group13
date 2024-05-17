#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pythonProcess = new QProcess(this);
    connect(pythonProcess, &QProcess::readyReadStandardOutput, this, &MainWindow::on_pythonOutput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    QString program = "python3";
    QStringList arguments;
    arguments << "/Home/Desktop/Cal/MainWindow/trig_calculator_python_angle_degrees.py" << ui->angleInput->text(); // 

    pythonProcess->start(program, arguments);
}

void MainWindow::on_pythonOutput()
{
    QString output = pythonProcess->readAllStandardOutput();
    QStringList values = output.split("\n");
    if (values.size() > 5) {
        ui->sinLabel->setText(values[0].split(": ").last());
        ui->cosLabel->setText(values[1].split(": ").last());
        ui->tanLabel->setText(values[2].split(": ").last());
        ui->arcsinLabel->setText(values[3].split(": ").last());
        ui->arccosLabel->setText(values[4].split(": ").last());
        ui->arctanLabel->setText(values[5].split(": ").last());
    }
}
