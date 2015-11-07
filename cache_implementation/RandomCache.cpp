#include "RandomCache.h"
#include <boost/format.hpp>
#include <iostream>

void RandomCache::evict() {
    auto item = cache_map.begin();
    std::advance(item, rand() % cache_map.size());
    deduct_cache_size(item->second.size());
    std::cout <<  boost::format("\tSwapped out %1% size %2% kb\n") % item->first % (item->second.size() / 1024);
    cache_map.erase(item);
}

void RandomCache::update_cache_history(const std::string &url, const double size) {

}