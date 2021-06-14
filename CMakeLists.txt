cmake_minimum_required(VERSION 2.8.3)
project(drive_gear)

find_package(catkin REQUIRED COMPONENTS roscpp rospy dbw_mkz_msgs std_msgs geometry_msgs genmsg)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(drive_gear src/drive_gear.cpp)
target_link_libraries(drive_gear ${catkin_LIBRARIES})
add_dependencies(drive_gear drive_gear_generate_messages_cpp)
