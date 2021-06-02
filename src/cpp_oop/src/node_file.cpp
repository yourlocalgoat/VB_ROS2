#include "rclcpp/rclcpp.hpp"

//class MyNode inherets from public rclpp:Node
class MyNode : public rclcpp::Node
{
    public:
        MyNode() : Node("cpp_oop_test"), counter_(0)
        {
            RCLCPP_INFO(this->get_logger(), "Hello Cpp OOP Node");

            timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                            std::bind(&MyNode::timerCallback, this));
        }

        
    private:

        //making a timer calback
        void timerCallback()
        {
            counter_++;
            RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);
        }

        //declaring timer object
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}