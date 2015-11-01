#ifndef RANDOMCACHE_H
#define RANDOMCACHE_H
#include "BaseCache.h"

class RandomCache : public BaseCache{
public:
    virtual ~RandomCache() { }
    RandomCache() { }

    void evict();
};


#endif //RANDOMCACHE_H
