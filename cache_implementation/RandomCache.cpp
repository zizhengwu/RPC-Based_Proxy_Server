#include "RandomCache.h"
#include <boost/format.hpp>

void RandomCache::evict() {
    auto item = cache_map.begin();
    std::advance(item, rand() % cache_map.size());
    deduct_cache_size(item->second.size());
    std::cout <<  boost::format("swapped out %1% size %2%\n kb") % item->first % (item->second.size() / 1024);
    cache_map.erase(item);
}

void RandomCache::update_cache_history(const std::string &) {

}