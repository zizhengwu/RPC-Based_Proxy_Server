#ifndef SERVER_TUPLE_H
#define SERVER_TUPLE_H

#include <string>

class Tuple {
public:
    Tuple(const std::string& url, double size) : url(url), size(size) { }

    virtual ~Tuple() { }

    bool operator<(const class Tuple& other) const {
        return size < other.size;
    }

    const std::string &get_url() const {
        return url;
    }

private:
    std::string url;
    double size;
};

#endif //SERVER_TUPLE_H
