#!/usr/bin/env python
#导入rospy库
import rospy
#导入ROS std_msgs标准消息中的String消息
from std_msgs.msg import String

#声明订阅器回调函数
def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s",data.data)

def listener():
    #初始化ROS节点，命名节点为listener
    rospy.init_node('listener',anonymous=True)
    #创建订阅器，收听/chatter话题，绑定callback回调函数
    rospy.Subscriber('chatter',String,callback)
    #进入spin阻塞式回调循环，等待话题消息
    rospy.spin()

if __name__ == '__main__':
    listener()