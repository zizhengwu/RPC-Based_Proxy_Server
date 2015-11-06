#include "FifoCache.h"
#include <boost/format.hpp>
#include <iostream>

void FifoCache::update_cache_history(const std::string &url, const double size) {
    fifo_queue.push(url);
}

void FifoCache::evict() {
    std::string to_be_popped = fifo_queue.front();
    fifo_queue.pop();
    std::cout << boost::format("\tPopped %1%\n") % to_be_popped;
    deduct_cache_size(cache_map.at(to_be_popped).size());
    cache_map.erase(to_be_popped);
}
