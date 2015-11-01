#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <iostream>

#include "proxy_server.h"

using namespace std;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main(int argc, char *argv[]) {
    boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    proxy_serverClient client(protocol);
    transport->open();

    std::string return_string;
    client.get_page(return_string, "https://www.google.com");
    cout << return_string << endl;
    transport->close();

    return 0;
}
