cmake_minimum_required(VERSION 3.2)
project(thrift_hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_SERVER
        gen-cpp/hello_world.cpp
        gen-cpp/hello_world.h
        gen-cpp/hello_world_constants.cpp
        gen-cpp/hello_world_constants.h
        gen-cpp/hello_world_server.skeleton.cpp
        gen-cpp/hello_world_types.cpp
        gen-cpp/hello_world_types.h)

set(SOURCE_CLIENT
        gen-cpp/client.cpp
        gen-cpp/hello_world.cpp
        gen-cpp/hello_world.h)

add_executable(server ${SOURCE_SERVER})
target_link_libraries(server thrift)

add_executable(client ${SOURCE_CLIENT})
target_link_libraries(client thrift)