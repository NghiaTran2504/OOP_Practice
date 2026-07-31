#pragma once

#include "SortArray.h"
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
class HeapSort : public SortArray<T> {
private:
    void heapify(std::vector<T>& a, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[largest] < a[left]) largest = left;
        if (right < n && a[largest] < a[right]) largest = right;

        if (largest != i) {
            std::swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

public:
    void Process(std::vector<T>& a) override {
        int n = static_cast<int>(a.size());
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(a, n, i);
        }
        for (int i = n - 1; i > 0; --i) {
            std::swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }

    std::string getName() const override {
        return "Heap Sort";
    }
};
