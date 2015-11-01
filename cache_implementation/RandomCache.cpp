#include "RandomCache.h"
#include <boost/format.hpp>

void RandomCache::evict() {
    auto item = cache_map.begin();
    std::advance(item, rand() % cache_map.size());
    deduct_cache_size(item->second.size());
    std::cout <<  boost::format("swapped out %1% size %2%\n") % item->first % item->second.size();
    cache_map.erase(item);
}

void RandomCache::insert_into_cache(const std::string &url, const std::string &content) {
    cache_map[url] = content;
    cache_size += content.size();
    while(get_cache_size() > cache_size_maximum)
    {
        evict();
    }
    std::cout << boost::format("current cache size: %1% bytes\n") % cache_size;
};

std::string RandomCache::retrieve_content_of_url(const std::string& url) const {
    std::cout << boost::format("url: %1% hit\n") % url;
    return (cache_map.at(url));
};

bool RandomCache::check_if_exist_content_of_url(const std::string &url) {
    return !(cache_map.find(url) == cache_map.end());
};