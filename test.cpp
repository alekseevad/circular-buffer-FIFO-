#include <iostream>
#include "fifo1.hpp"
#include "fifo2.hpp"
#include <iomanip>
#include <string>
#include <deque>


bool isEven(float value) {
    int n;
    value /= 2;
    n = (int)value;
    value -= n;
    if (value == 0)
        return true;
    else return false;
}

int main()
{
    /*Testing first realization of cyclical buffer*/
    std::cout << "Enter size of boofer: " << std::endl;
    std::size_t size;
    std::cin >> size;
    Queue<int> newqueue(size);
    std::cout << "Enter value of element(s): " << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cin >> newqueue;
    }
    std::cin >> newqueue;
    std::cin >> newqueue;
    std::cout << newqueue;
    /*Testing second realization of cyclical buffer*/
    int size2;
    std::cout << "Enter size of second boofer: " << std::endl;
    std::cin >> size2;
    QueueORGN<int> newque(size2);
    std::cout << "Enter value of element(s): " << std::endl;
    for (int i = 0; i < size2; ++i) std::cin >> newque;
    std::cin >> newque;
    std::cin >> newque;
    std::cout << newque;
    return 0;
}