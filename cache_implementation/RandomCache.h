#ifndef RANDOMCACHE_H
#define RANDOMCACHE_H
#include "BaseCache.h"

class RandomCache : public BaseCache{
public:
    virtual ~RandomCache() { }
    RandomCache() { }

    void evict() override ;
    void update_cache_history(const std::string&) override;

private:

};


#endif //RANDOMCACHE_H
