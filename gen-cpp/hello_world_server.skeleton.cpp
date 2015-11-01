// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "hello_world.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class hello_worldHandler : virtual public hello_worldIf {
 public:
  hello_worldHandler() {
    // Your initialization goes here
  }

  void hello(std::string& _return) {
    // Your implementation goes here
    _return = "hello world";
    printf("hello\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<hello_worldHandler> handler(new hello_worldHandler());
  shared_ptr<TProcessor> processor(new hello_worldProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

