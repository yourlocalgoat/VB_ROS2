#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
 
from example_interfaces.msg import String


class SmartPhoneNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("Smartphone") # MODIFY NAME
        self.get_logger().info("Smartphone has been started")

        self.subscriber = self.create_subscription(String,"robot_news",self.callback_robot_news,10)
    
    def callback_robot_news(self,msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = SmartPhoneNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
