#pragma once

#include <iostream>

class ProgramFrame {
protected:
    virtual void startMessage() {
        std::cout << "\n========================================\n";
        std::cout << "  TEMPLATE METHOD SORTING TEST \n";
        std::cout << "========================================\n";
    }

    virtual void Input() = 0;
    virtual bool Check() = 0;

    virtual void errorMessage() {
        std::cout << "\n[ERROR]: Input is empty or invalid.\n";
    }

    virtual void Process() = 0;
    virtual void Output() = 0;
    virtual bool askContinue() {
        char choice;
        std::cout << "\nDo you want to run another test? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');
        return (choice == 'y' || choice == 'Y');
    }

public:
    virtual ~ProgramFrame() = default;
    void run() {
        do {
            startMessage();
            Input();
            if (!Check()) {
                errorMessage();
            } else {
                Process();
                Output();
            }
        } while (askContinue());
    }
};
