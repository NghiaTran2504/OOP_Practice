#pragma once

#include "SortArray.h"
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
class SelectionSort : public SortArray<T> {
public:
    void Process(std::vector<T>& a) override {
        int n = static_cast<int>(a.size());
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                std::swap(a[i], a[minIdx]);
            }
        }
    }

    std::string getName() const override {
        return "Selection Sort";
    }
};
