#ifndef FIFOCACHE_H
#define FIFOCACHE_H

#include "BaseCache.h"
#include <queue>

class FifoCache : public BaseCache {
public:
    
    FifoCache(double cache_size_maximum) : BaseCache(cache_size_maximum) { }
    virtual ~FifoCache() { }

    void update_cache_history(const std::string &url, const double size) override;
    void evict() override;

private:
    std::queue<std::string> fifo_queue;
};


#endif //FIFOCACHE_H
