#include "mainwindow.h"
#include <QApplication>
//#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
//#include <GL/glut.h>
#include <ros/ros.h>
#include <QProcess>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "file_player");
  ros::NodeHandle nh("~");

  QApplication a(argc, argv);
  MainWindow w;
  w.RosInit(nh);
  bool auto_start;
  std::string dataset_path;
  nh.getParam("auto_start", auto_start);
  nh.getParam("dataset_path", dataset_path);
  std::cout << "Path: " << dataset_path << std::endl;
  if(auto_start)
  {
    w.PublicFilePathSet(dataset_path);
    w.PublicPlay();
  }
  w.show();

   return a.exec();
}
