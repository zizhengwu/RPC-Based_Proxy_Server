#include "BaseCache.h"

BaseCache::BaseCache() {
    cache_size = 0;
    srand(time(NULL));
    cache_size_maximum = 200000;
}

BaseCache::~BaseCache() {

}

void BaseCache::deduct_cache_size(const double& bytes_to_be_deducted) {
    cache_size -= bytes_to_be_deducted;
};
