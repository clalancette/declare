#include <rclcpp/rclcpp.hpp>

class Declare final : public rclcpp::Node
{
 public:
  Declare() : rclcpp::Node("declare")
  {
    param1_ = this->declare_parameter("param1", 9.0);
    RCLCPP_INFO(this->get_logger(), "param1: %f", param1_);
  }

  ~Declare()
  {
  }

 private:
  double param1_;
};

int main(int argc, char const* argv[])
{
  rclcpp::init(argc, argv);

  setvbuf(stdout, NULL, _IONBF, BUFSIZ);

  auto declare = std::make_shared<Declare>();

  rclcpp::spin(declare);

  rclcpp::shutdown();

  return 0;
}
