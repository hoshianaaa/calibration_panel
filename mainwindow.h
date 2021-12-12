#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <ros/ros.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/Point32.h>
#include <vision_ros_msgs/RobotPose.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_released();
    void on_btn1_released();
    void on_btn2_released();
    void on_btn3_released();
    void on_btn4_released();
    void on_btn5_released();
    void on_btn6_released();
    void on_btn7_released();
    void on_btn8_released();
    void on_btn9_released();

private:
    Ui::MainWindow *ui;
    ros::NodeHandle nh_;
    ros::Subscriber points_sub_,pose_sub_;
    void pointsCallback(const geometry_msgs::Polygon& msg);
    void poseCallback(const vision_ros_msgs::RobotPose& msg);
    geometry_msgs::Polygon detect_points_;
    vision_ros_msgs::RobotPose robot_pose_;

};
#endif // MAINWINDOW_H
