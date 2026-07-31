#pragma once

#include <vector>
#include <string>

template <typename T>
class SortArray {
public:
    virtual ~SortArray() = default;
    virtual void Process(std::vector<T>& a) = 0;
    virtual std::string getName() const = 0;
};
