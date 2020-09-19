//导入ROS库文件
#include "ros/ros.h"
//导入ROS std_msgs标准消息中的String类型
#include "std_msgs/String.h"


//声明订阅器的回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    //打印输出所订阅话题上发布的消息
    ROS_INFO("I heard: [%s]",msg->data.c_str());
}

int main(int argc,char **argv)
{
    //初始化ROS节点，节点名为listener
    ros::init(argc,argv,"listener");
    //声明ROS句柄
    ros::NodeHandle n;
    //创建一个订阅器，订阅/chatter话题
    ros::Subscriber sub = n.subscribe("chatter",10,chatterCallback);
    //进入spin循环等待回调
    ros::spin(); 

    return 0;
}