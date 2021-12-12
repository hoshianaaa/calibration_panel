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

  detect_points_ = msg;
  ROS_INFO("detect_points callback !\n");
  std::cout << "size:" << msg.points.size() << std::endl;
  for (int i=0;i<msg.points.size();i++)
  {
    std::cout << "point " << i << " x: ";
    std::cout << msg.points[i].x << " y: ";
    std::cout << msg.points[i].y << std::endl;
  }

  //float f = msg.points[8].x;
  //QString s = QString::number(f, 'f', 8);
  //QString text = QString::fromStdString(msg.points);
  //ui->label->setText(s);
}
