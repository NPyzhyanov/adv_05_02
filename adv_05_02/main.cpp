#include <iostream>

#include "table.h"

int main()
{
    int height = 4;
    int length = 3;
    auto test = Table<double>(height, length);
    test[0][0] = 4.7;
    test[1][1] = -9.1;
    test[0][2] = 12.0;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << test[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    auto row_ptr = test[1];
    std::cout << row_ptr[1] << std::endl;
    std::cout << std::endl;
    
    std::cout << test.Size() << std::endl;
    std::cout << test.Size("height") << std::endl;
    std::cout << test.Size("length") << std::endl;
    std::cout << test.Size("ength") << std::endl;
    
    return 0;
}
