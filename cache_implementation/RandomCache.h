#ifndef RANDOMCACHE_H
#define RANDOMCACHE_H
#include "BaseCache.h"

class RandomCache : public BaseCache{
public:
    virtual ~RandomCache() { }
    RandomCache() { }

    void evict();
    void insert_into_cache(const std::string &url, const std::string &content);
    std::string retrieve_content_of_url(const std::string &url) const;
    bool check_if_exist_content_of_url(const std::string &url);

private:
    std::map<std::string, std::string> cache_map;
};


#endif //RANDOMCACHE_H
