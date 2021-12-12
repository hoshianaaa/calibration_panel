#include "mainwindow.h"
#include <QPushButton>
#include "./ui_mainwindow.h"

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Polygon.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    btn1 = new QPushButton("Get pos", this);
    btn2 = new QPushButton("Get pos", this);
    btn3 = new QPushButton("Get pos", this);
    btn4 = new QPushButton("Get pos", this);
    btn5 = new QPushButton("Get pos", this);
    btn6 = new QPushButton("Get pos", this);
    btn7 = new QPushButton("Get pos", this);
    btn8 = new QPushButton("Get pos", this);
    btn9 = new QPushButton("Get pos", this);

    ui->tableWidget->setCellWidget(0,4,btn1);
    ui->tableWidget->setCellWidget(1,4,btn2);
    ui->tableWidget->setCellWidget(2,4,btn3);
    ui->tableWidget->setCellWidget(3,4,btn4);
    ui->tableWidget->setCellWidget(4,4,btn5);
    ui->tableWidget->setCellWidget(5,4,btn6);
    ui->tableWidget->setCellWidget(6,4,btn7);
    ui->tableWidget->setCellWidget(7,4,btn8);
    ui->tableWidget->setCellWidget(8,4,btn9);

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
