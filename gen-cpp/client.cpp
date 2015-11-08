#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <iostream>
#include <boost/format.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <fstream>
#include "proxy_server.h"


using namespace std;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main(int argc, char *argv[]) {
    boost::posix_time::ptime time_before, time_after;
    int url_number = 0;
    boost::shared_ptr<TSocket> socket(new TSocket("128.61.104.148", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    proxy_serverClient client(protocol);
    transport->open();
    std::vector<std::string> urls_to_be_retrieved;
    std::ifstream input("urls.txt");
    for( std::string line; getline( input, line ); )
    {
        urls_to_be_retrieved.push_back(line);
    }
    time_before = boost::posix_time::microsec_clock::universal_time();
    std::string return_string;
    for (auto url : urls_to_be_retrieved) {
        client.get_page(return_string, url);
        cout << boost::format("get %1%\tsize: %2% kb\n") % url % (return_string.size() / 1024);
    }
    time_after = boost::posix_time::microsec_clock::universal_time();
    cout << "time elapse: " << time_after - time_before << endl;

    transport->close();

    return 0;
}
