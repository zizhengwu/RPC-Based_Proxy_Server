#ifndef BASECACHE_H
#define BASECACHE_H

#include <string>
#include <boost/unordered_map.hpp>

class BaseCache {

public:
    virtual ~BaseCache();
    explicit BaseCache(double cache_size_maximum);

    double get_cache_size() const {
        return cache_size;
    };

    virtual void deduct_cache_size(const double& bytes_to_be_deducted) final;
    virtual void insert_into_cache(const std::string& url, const std::string& content) final;
    virtual std::string retrieve_content_of_url(const std::string& url) const final;
    virtual bool check_if_exist_content_of_url(const std::string& url) final;
    virtual void update_cache_history(const std::string &url, const double size) = 0;
    virtual void evict() = 0;

protected:
    double cache_size;
    double cache_size_maximum;
    boost::unordered_map<std::string, std::string> cache_map;
};


#endif //BASECACHE_H
