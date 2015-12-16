[![Build Status](https://travis-ci.org/zizhengwu/RPC-Based_Proxy_Server.svg?branch=master)](https://travis-ci.org/zizhengwu/RPC-Based_Proxy_Server)

To run, you need to modify `gen-cpp/client.cpp' to enter the the IP of the computer which you would like to run server on. Then

    mkdir build
    cd build
    cmake ..
    make

To run server, `./server`. To run client, `./run_client.sh` would run all the test cases under the folder `test_cases`.
