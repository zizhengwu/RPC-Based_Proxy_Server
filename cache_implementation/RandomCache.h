#ifndef RANDOMCACHE_H
#define RANDOMCACHE_H
#include "BaseCache.h"

class RandomCache : public BaseCache{
public:
    virtual ~RandomCache() { }
    RandomCache(double cache_size_maximum) : BaseCache(cache_size_maximum) { }

    void evict() override ;
    void update_cache_history(const std::string &url, const double size) override;

private:

};

#endif //RANDOMCACHE_H
