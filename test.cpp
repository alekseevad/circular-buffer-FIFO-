#include <iostream>
#include "fifo1.hpp"


bool isEven(float value) {
    int n;
    value /= 2;
    n = (int)value;
    value -= n;
    if(value == 0)
        return true;
    else return false;
}

int main()
{
    std::string type_of_data;
    std::cout << "Enter size of boofer: " << std::endl;
    std::size_t size;
    std::cin >> size;
    std::cout << "Enter type of element(s): " << std::endl;
    std::cin >> type_of_data;
    switch (type_of_data) {
        case 'int':
            Queue<int> newqueue(size);
            break;
        case 'char':
            Queue<char> newqueue(size);
            break;
        case "float":
            Queue<float> newqueue(size);
            break;
        default:
            std::cerr << "Not supported" << std::endl;
            break;
    }        
    std::cout << "Enter value of element(s): " << std::endl;
    std::cin >> newqueue;
    std::cout << newqueue; 
    return 0;
}