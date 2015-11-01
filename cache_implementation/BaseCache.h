#ifndef BASECACHE_H
#define BASECACHE_H

#include <string>
#include <map>
#include <time.h>
#include <boost/format.hpp>
#include <iostream>

class BaseCache {

public:
    virtual ~BaseCache();

    BaseCache();

    double get_cache_size() const {
        return cache_size;
    };
    void deduct_cache_size(const double& bytes_to_be_deducted);
    void insert_into_cache_map(const std::string& url, const std::string& content);
    std::string retrieve_content_of_url(const std::string& url) const;
    bool check_exist_in_map_content_of_url(const std::string& url);
    virtual void evict() {};

protected:
    std::map<std::string, std::string> cache_map;
    double cache_size;
    double cache_size_maximum;
};


#endif //BASECACHE_H
