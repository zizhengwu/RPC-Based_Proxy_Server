#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <iostream>
#include <boost/format.hpp>

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
    std::vector<std::string> urls_to_be_retrieved {"http://www.ign.com", "http://www.amazon.com/", "https://www.google.com", "https://www.reddit.com/", "https://www.google.com", "http://www.ign.com", "https://www.youtube.com", "http://www.gametrailers.com/", "https://www.linkedin.com/", "https://www.facebook.com", "http://www.twitch.tv/", "https://www.linkedin.com", "http://www.gamespot.com/"};
    for (auto url : urls_to_be_retrieved) {
        client.get_page(return_string, url);
        cout << boost::format("get %1%\tsize: %2% kb\n") % url % (return_string.size() / 1024);
    }

    transport->close();

    return 0;
}
