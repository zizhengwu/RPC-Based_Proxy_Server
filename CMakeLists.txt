cmake_minimum_required(VERSION 3.2)
project(thrift_hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_SERVER
        gen-cpp/proxy_server.cpp
        gen-cpp/proxy_server.h
        gen-cpp/proxy_server_server.skeleton.cpp
        gen-cpp/proxy_server_constants.cpp
        gen-cpp/proxy_server_constants.h
        gen-cpp/proxy_server_types.cpp
        gen-cpp/proxy_server_types.h)

set(SOURCE_CLIENT
        gen-cpp/client.cpp
        gen-cpp/proxy_server.cpp
        gen-cpp/proxy_server.h)

add_executable(server ${SOURCE_SERVER})
target_link_libraries(server thrift curl)

add_executable(client ${SOURCE_CLIENT})
target_link_libraries(client thrift)