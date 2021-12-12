#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <ros/ros.h>
#include <geometry_msgs/Polygon.h>

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
};
#endif // MAINWINDOW_H
