# ros_keyboard_publisher

## 1. Build ros_keyboard_publisher on ROS

Clone the repository and catkin_make:

    cd ~/catkin_ws/src
    git clone https://github.com/Boscuit/ros_keyboard_publisher.git
    cd ../
    catkin_make
    source ~/catkin_ws/devel/setup.bash
## 2.  Listen to the key

Open a new terminal and run the node.

    rosrun ros_keyboard_publisher keyboard_publisher
When user press key 'r' or 'R', the node publish a topic "/RequestRecord" with massage std_msgs/Bool and "/RequestRecord.data" is triggered as true and false alternatively.   