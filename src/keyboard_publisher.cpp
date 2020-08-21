#include <iostream>
#include <ros/ros.h>
#include <termios.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Char.h>

using namespace std;

int getch()
{
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON);                 // disable buffering
  newt.c_cc[VMIN] = 0;
  newt.c_cc[VTIME] = 0;
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

  int c = getchar();  // read character (non-blocking)

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
  return c;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "keyboard_publisher");
  ros::NodeHandle nh;
  ros::Publisher Record_pub = nh.advertise<std_msgs::Bool>("RequestRecord",1);
  ros::Publisher keyboard_pub = nh.advertise<std_msgs::Char>("Request",1);
  std_msgs::Bool RequestRecord;
  std_msgs::Char Request;
  bool bRequestRecord = false;
  cout << "Press 'r' or 'R' to trigger record. Press 'p' or 'P' to process photo." << endl;
  cout << "-------------------------------" << endl;

  while (ros::ok())
  {
    int c = getch();   // call your non-blocking input function
    if (c == 'r' || c == 'R')
    {
      // if(bRequestRecord == false)
      // {
      //   RequestRecord.data = true;
      //   bRequestRecord = true;
      // }
      // else
      // {
      //   RequestRecord.data = false;
      //   bRequestRecord = false;
      // }
      // Record_pub.publish(RequestRecord);
      Request.data = 'r';
      keyboard_pub.publish(Request);
    }
    else if(c == 's' || c == 'S')
    {
      Request.data = 's';
      keyboard_pub.publish(Request);
    }
    else if(c == 'p' || c == 'P')
    {
      Request.data = 'p';
      keyboard_pub.publish(Request);
    }
    else if(c == 'b' || c == 'B')
    {
      Request.data = 'b';
      keyboard_pub.publish(Request);
    }
    else if(c == 'x' || c == 'X')
    {
      Request.data = 'x';
      keyboard_pub.publish(Request);
    }
    usleep(3000);
  }
  cout << endl;
  return 0;
}
