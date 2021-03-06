cmake_minimum_required(VERSION 2.8)
project(RPC-Based_Proxy_Server)

FIND_PACKAGE(CURL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w")

set(SOURCE_SERVER
        gen-cpp/proxy_server.cpp
        gen-cpp/proxy_server.h
        gen-cpp/proxy_server_server.skeleton.cpp
        gen-cpp/proxy_server_constants.cpp
        gen-cpp/proxy_server_constants.h
        gen-cpp/proxy_server_types.cpp
        gen-cpp/proxy_server_types.h
        cache_implementation/BaseCache.h
        cache_implementation/RandomCache.cpp
        cache_implementation/RandomCache.h
        cache_implementation/BaseCache.cpp
        cache_implementation/FifoCache.cpp
        cache_implementation/FifoCache.h
        cache_implementation/MaxsCache.cpp
        cache_implementation/MaxsCache.h cache_implementation/Tuple.h)

set(SOURCE_CLIENT
        gen-cpp/client.cpp
        gen-cpp/proxy_server.cpp
        gen-cpp/proxy_server.h)

add_executable(server ${SOURCE_SERVER})
target_link_libraries(server thrift curl)

add_executable(client ${SOURCE_CLIENT})
target_link_libraries(client thrift)

file(COPY test_cases DESTINATION .)
file(COPY run_client.sh DESTINATION .)
