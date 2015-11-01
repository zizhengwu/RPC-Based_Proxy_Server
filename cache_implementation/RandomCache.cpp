#include "RandomCache.h"
#include <boost/format.hpp>

void RandomCache::evict() {
    auto item = cache_map.begin();
    std::advance(item, rand() % cache_map.size());
    deduct_cache_size(item->second.size());
    std::cout <<  boost::format("swapped out %1% size %2%\n") % item->first % item->second.size();
    cache_map.erase(item);
}
