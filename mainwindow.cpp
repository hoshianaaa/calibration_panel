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
    string_sub_ = nh_.subscribe("chatter", 10, &MainWindow::stringCallback, this);
    printf("register\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stringCallback(const geometry_msgs::Polygon& string_msg){
  //QString text = QString::fromStdString(string_msg);
  //ui->label->setText(text);
  //ROS_INFO("sub: %s", string_msg.data.c_str());
}
