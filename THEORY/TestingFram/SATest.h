#pragma once

#include "ProgramFrame.h"
#include "SortArray.h"
#include <vector>
#include <iostream>
#include <string>

template <typename T>
class SATest : public ProgramFrame {
private:
    SortArray<T>* pSorter;
    std::vector<T> Data;

protected:
    void startMessage() override;
    void Input() override;
    bool Check() override;
    void Process() override;
    void Output() override;

public:
    explicit SATest(SortArray<T>* sorter = nullptr);
    void setSorter(SortArray<T>* sorter);
};
