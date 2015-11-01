#include "BaseCache.h"

BaseCache::BaseCache() {
    cache_size = 0;
    srand(time(NULL));
    cache_size_maximum = 200000;
}

BaseCache::~BaseCache() {

}

void BaseCache::deduct_cache_size(const double& bytes_to_be_deducted) {
    cache_size -= bytes_to_be_deducted;
};

void BaseCache::insert_into_cache_map(const std::string& url, const std::string& content) {
    cache_map[url] = content;
    cache_size += content.size();
    while(cache_size > cache_size_maximum)
    {
        evict();
    }
    std::cout << boost::format("current cache size: %1% bytes\n") % cache_size;
};

std::string BaseCache::retrieve_content_of_url(const std::string& url) const {
    std::cout << boost::format("url: %1% hit\n") % url;
    return (cache_map.at(url));
};

bool BaseCache::check_exist_in_map_content_of_url(const std::string& url) {
    return !(cache_map.find(url) == cache_map.end());
};
