//导入ROS库文件
#include "ros/ros.h"
//导入ROS std_msgs标准消息包中的String消息
#include "std_msgs/String.h"
#include <sstream>

int main(int argc,char **argv)
{   
    //初始化ROS节点，节点名为talker
    ros::init(argc,argv,"talker");
    //声明ROS句柄
    ros::NodeHandle n;
    //创建一个发布器，向/chatter话题上发送std::msgs::String类型消息
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);
    //创建一个ros::Rate对象，定时间隔为10hz
    ros::Rate loop_rate(10);

    int count = 0;
    while(ros::ok())
    {
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        ROS_INFO("%s",msg.data.c_str());
        //使用发布器发布消息
        chatter_pub.publish(msg);
        //ros::spinOnce处理一次回调
        ros::spinOnce();
        //频率控制，控制循环频率为10hz
        loop_rate.sleep();
        ++count;
    }
    return 0;
}