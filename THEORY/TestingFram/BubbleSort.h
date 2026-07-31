#pragma once

#include "SortArray.h"
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
class BubbleSort : public SortArray<T> {
public:
    void Process(std::vector<T>& a) override {
        int n = static_cast<int>(a.size());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (a[j + 1] < a[j]) {
                    std::swap(a[j], a[j + 1]);
                }
            }
        }
    }

    std::string getName() const override {
        return "Bubble Sort";
    }
};
