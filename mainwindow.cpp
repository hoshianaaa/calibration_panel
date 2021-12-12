#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Polygon.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->label->setText("Hello World!");
    points_sub_ = nh_.subscribe("checker_detector/detect_points", 10, &MainWindow::pointsCallback, this);
    printf("register\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pointsCallback(const geometry_msgs::Polygon& msg){
  float f = msg.points[0].x;
  QString s = QString::number(f, 'f', 8);
  //QString text = QString::fromStdString(msg.points);
  ui->label->setText(s);
  //ROS_INFO("sub: %s", string_msg.data.c_str());
}
