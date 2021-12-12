#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <ros/ros.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/Point32.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ros::NodeHandle nh_;
    ros::Subscriber points_sub_;
    void pointsCallback(const geometry_msgs::Polygon& msg);
    geometry_msgs::Polygon detect_points_;
    QPushButton *btn1,*btn2,*btn3,*btn4,*btn5,*btn6,*btn7,*btn8,*btn9;

};
#endif // MAINWINDOW_H
