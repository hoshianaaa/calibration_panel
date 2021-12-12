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

    ui->tableWidget->setCellWidget(0,4,ui->pushButton_1);
    ui->tableWidget->setCellWidget(1,4,ui->pushButton_2);
    ui->tableWidget->setCellWidget(2,4,ui->pushButton_3);
    ui->tableWidget->setCellWidget(3,4,ui->pushButton_4);
    ui->tableWidget->setCellWidget(4,4,ui->pushButton_5);
    ui->tableWidget->setCellWidget(5,4,ui->pushButton_6);
    ui->tableWidget->setCellWidget(6,4,ui->pushButton_7);
    ui->tableWidget->setCellWidget(7,4,ui->pushButton_8);
    ui->tableWidget->setCellWidget(8,4,ui->pushButton_9);

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
