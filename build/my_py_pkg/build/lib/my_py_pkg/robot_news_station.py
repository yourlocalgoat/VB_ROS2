#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
 
from example_interfaces.msg import String

class RobotNewsStationNode(Node):
    def __init__(self):
        super().__init__("robot_news_station")

        self.robot_name_ = "C3PO"
        self.publisher_ = self.create_publisher(String, "robot_news", 10)   #create publisher method, exporting msg String type to "robot_news" topic, with a buffer of 10
        self.timer_ = self.create_timer(0.5, self.publish_news)     #at 2Hz, call self.publish_news
        self.get_logger().info("Robot New Station has been started")

    #function to publish to publisher
    def publish_news(self):
        msg = String()                  #type
        msg.data = "Hello this is " +str(self.robot_name_) + "on robot news"             
        self.publisher_.publish(msg)

 
def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
