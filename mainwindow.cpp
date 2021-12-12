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

    ui->tableWidget->setCellWidget(0,4,ui->btn1);
    ui->tableWidget->setCellWidget(1,4,ui->btn2);
    ui->tableWidget->setCellWidget(2,4,ui->btn3);
    ui->tableWidget->setCellWidget(3,4,ui->btn4);
    ui->tableWidget->setCellWidget(4,4,ui->btn5);
    ui->tableWidget->setCellWidget(5,4,ui->btn6);
    ui->tableWidget->setCellWidget(6,4,ui->btn7);
    ui->tableWidget->setCellWidget(7,4,ui->btn8);
    ui->tableWidget->setCellWidget(8,4,ui->btn9);

    points_sub_ = nh_.subscribe("checker_detector/detect_points", 10, &MainWindow::pointsCallback, this);
    pose_sub_ = nh_.subscribe("/robot_motion_server/pose", 10, &MainWindow::poseCallback, this);

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
    float x = msg.points[i].x;
    float y = msg.points[i].y;

    std::cout << "point " << i << " x: ";
    std::cout << x << " y: ";
    std::cout << y << std::endl;

    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(x));
    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(y));

    ui->tableWidget->setItem(i,0,newItemX);
    ui->tableWidget->setItem(i,1,newItemY);

  }


  //float f = msg.points[8].x;
  //QString s = QString::number(f, 'f', 8);
  //QString text = QString::fromStdString(msg.points);
  //ui->label->setText(s);
}

void MainWindow::poseCallback(const vision_ros_msgs::RobotPose& msg){
    ROS_INFO("robot pose callback !\n");
    robot_pose_ = msg;
}

void MainWindow::on_pushButton_released()
{
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(0,3,newItem);
}

void MainWindow::on_btn1_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(0,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(0,3,newItemY);
}

void MainWindow::on_btn2_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(1,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(1,3,newItemY);
}

void MainWindow::on_btn3_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(2,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(2,3,newItemY);
}

void MainWindow::on_btn4_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(3,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(3,3,newItemY);
}

void MainWindow::on_btn5_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(4,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(4,3,newItemY);
}

void MainWindow::on_btn6_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(5,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(5,3,newItemY);
}

void MainWindow::on_btn7_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(6,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(6,3,newItemY);
}

void MainWindow::on_btn8_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(7,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(7,3,newItemY);
}

void MainWindow::on_btn9_released()
{
    QTableWidgetItem *newItemX = new QTableWidgetItem(tr("%1").arg(robot_pose_.x));
    ui->tableWidget->setItem(8,2,newItemX);

    QTableWidgetItem *newItemY = new QTableWidgetItem(tr("%1").arg(robot_pose_.y));
    ui->tableWidget->setItem(8,3,newItemY);
}
