#include <iostream>
#include <string>
#include <memory>

#include "ProgramFrame.h"
#include "SortArray.h"
#include "HeapSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "SATest.h"
#include "Fraction.h"

template <typename T>
void runTest() {
    int choice;
    std::cout << "\nChoose Algorithm (1. HeapSort, 2. BubbleSort, 3. SelectionSort): ";
    std::cin >> choice;

    std::unique_ptr<SortArray<T>> sorter;
    if (choice == 1) sorter = std::make_unique<HeapSort<T>>();
    else if (choice == 2) sorter = std::make_unique<BubbleSort<T>>();
    else if (choice == 3) sorter = std::make_unique<SelectionSort<T>>();

    if (sorter) {
        SATest<T> test(sorter.get());
        test.run();
    } else {
        std::cout << "Invalid algorithm choice!\n";
    }
}

int main() {
    int typeChoice = -1;
    while (true) {
        std::cout << "\n=== SORTING TEST FRAMEWORK ===\n";
        std::cout << "1. Short / Int\n";
        std::cout << "2. String\n";
        std::cout << "3. Fraction\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose data type: ";
        if (!(std::cin >> typeChoice) || typeChoice == 0) break;

        if (typeChoice == 1) runTest<int>();
        else if (typeChoice == 2) runTest<std::string>();
        else if (typeChoice == 3) runTest<Fraction>();
    }
    std::cout << "Exiting program.\n";
    return 0;
}
