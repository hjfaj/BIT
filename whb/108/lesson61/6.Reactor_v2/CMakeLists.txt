cmake_minimum_required(VERSION 3.10)
project(Reactor)

add_executable(reactor_server Main.cc)
target_link_libraries(reactor_server jsoncpp)

add_executable(client ClientCal.cc)
target_link_libraries(client jsoncpp)