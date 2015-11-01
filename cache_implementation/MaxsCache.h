#ifndef MAXSCACHE_H
#define MAXSCACHE_H

#include "BaseCache.h"
#include "Tuple.h"

#include <queue>

class MaxsCache : public BaseCache{

public:
    virtual void update_cache_history(const std::string &url, const double size) override;
    virtual void evict() override;

    MaxsCache() { }
    virtual ~MaxsCache() { }

private:
    std::priority_queue<Tuple> maxs_queue;
};


#endif //MAXSCACHE_H
