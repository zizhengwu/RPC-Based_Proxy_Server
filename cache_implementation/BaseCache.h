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

    virtual void deduct_cache_size(const double& bytes_to_be_deducted);
    virtual void insert_into_cache(const std::string& url, const std::string& content);
    virtual std::string retrieve_content_of_url(const std::string& url) const;
    virtual bool check_if_exist_content_of_url(const std::string& url);
    virtual void update_cache_history(const std::string& url)=0;
    virtual void evict()=0;

protected:
    double cache_size;
    double cache_size_maximum;
    std::map<std::string, std::string> cache_map;
};


#endif //BASECACHE_H
