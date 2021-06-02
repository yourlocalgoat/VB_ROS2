cmake_minimum_required(VERSION 3.5)
project(cpp_oop)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

#adding Executable Node
add_executable(cpp_oop_test src/node_file.cpp)
ament_target_dependencies(cpp_oop_test rclcpp)

install(TARGETS
  cpp_oop_test
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
