#include "MaxsCache.h"
#include <iostream>
#include <string>
#include <boost/format.hpp>

void MaxsCache::update_cache_history(const std::string &url, const double size) {
    maxs_queue.push(Tuple(url, size));
}

void MaxsCache::evict() {
    std::string to_be_popped = maxs_queue.top().get_url();
    maxs_queue.pop();
    std::cout << boost::format("\tPopped %1%\n") % to_be_popped;
    deduct_cache_size(cache_map.at(to_be_popped).size());
    cache_map.erase(to_be_popped);
}
