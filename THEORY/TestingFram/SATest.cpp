#include "SATest.h"
#include "Fraction.h"

template <typename T>
SATest<T>::SATest(SortArray<T>* sorter) : pSorter(sorter) {}

template <typename T>
void SATest<T>::setSorter(SortArray<T>* sorter) {
    pSorter = sorter;
}

template <typename T>
void SATest<T>::startMessage() {
    ProgramFrame::startMessage();
    if (pSorter) {
        std::cout << "Algorithm: " << pSorter->getName() << "\n";
    }
}

template <typename T>
void SATest<T>::Input() {
    Data.clear();
    int count = 0;
    std::cout << "Enter number of elements: ";
    if (std::cin >> count && count > 0) {
        std::cout << "Enter " << count << " element(s):\n";
        Data.resize(count);
        for (int i = 0; i < count; ++i) {
            std::cin >> Data[i];
        }
    }
}

template <typename T>
bool SATest<T>::Check() {
    return (pSorter != nullptr) && (!Data.empty());
}

template <typename T>
void SATest<T>::Process() {
    if (pSorter) {
        pSorter->Process(Data);
    }
}

template <typename T>
void SATest<T>::Output() {
    std::cout << "\nSorted Result:\n[ ";
    for (size_t i = 0; i < Data.size(); ++i) {
        std::cout << Data[i] << (i + 1 < Data.size() ? ", " : "");
    }
    std::cout << " ]\n";
}

// Explicit template instantiations
template class SATest<short>;
template class SATest<int>;
template class SATest<std::string>;
template class SATest<Fraction>;
