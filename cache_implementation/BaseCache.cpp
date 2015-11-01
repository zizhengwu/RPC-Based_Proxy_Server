#include "BaseCache.h"

BaseCache::BaseCache() {
    cache_size = 0;
    srand(time(NULL));
    // 1024 kb
    cache_size_maximum = 1024000;
}

BaseCache::~BaseCache() {

}

void BaseCache::deduct_cache_size(const double& bytes_to_be_deducted) {
    cache_size -= bytes_to_be_deducted;
};

void BaseCache::insert_into_cache(const std::string& url, const std::string& content) {
    update_cache_history(url, content.size());
    cache_map[url] = content;
    cache_size += content.size();
    while(get_cache_size() > cache_size_maximum)
    {
        evict();
        std::cout << boost::format("\tDeduct cache size: %1% kb\n") % (cache_size / 1024);
    }
    std::cout << boost::format("\tCurrent cache size: %1% kb\n") % (cache_size / 1024);
};

std::string BaseCache::retrieve_content_of_url(const std::string& url) const {
    std::cout << boost::format("Hit %1% \n") % url;
    return (cache_map.at(url));
};

bool BaseCache::check_if_exist_content_of_url(const std::string& url) {
    return !(cache_map.find(url) == cache_map.end());
};