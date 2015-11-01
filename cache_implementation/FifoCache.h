#include "BaseCache.h"
#include <queue>

#ifndef FIFOCACHE_H
#define RPC_BASED_PROXY_SERVER_FIFOCACHE_H


class FifoCache : public BaseCache {
public:


    FifoCache() { }
    virtual ~FifoCache() { }

    void update_cache_history(const std::string &url, const double size) override;
    void evict() override;

private:
    std::queue<std::string> fifo_queue;
};


#endif //FIFOCACHE_H
