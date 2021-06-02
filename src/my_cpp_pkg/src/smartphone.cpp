#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SmartphoneNode : public rclcpp::Node
{
public:
    SmartphoneNode() : Node("smarphone_cpp")
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("robot_news", 10,
                                                std::bind(&SmartphoneNode::callback_robot_news, this,std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(),"Smartphone_cpp has started");
    }

private:
    void callback_robot_news(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }
    //Declaring Subscriber, creating a Pointer pointing to 'msg::String' data, subscriber is named 'subscriber_'
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
