#include "func.h"
#include <iostream>

namespace spacespace {
    void func(int a){
        static int z = 0;
        std::cout << "Сумма: " << a + z << std::endl;
        z = a;
    }
}