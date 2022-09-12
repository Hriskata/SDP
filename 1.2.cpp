#include <iostream>
#include <cmath>
#include <string>

void CodeName(std::string name)
{
    int j = 0;
    long long code = 0;
    int size = name.size();
    for (int i = size-1; i >= 0; i--)
    {
        if (name[i] < 'd')
        {
            code = code + name[i] * pow(10, j);
            j += 2;
        }
        else {
            code = code + name[i] * pow(10, j);
            j += 3;
        }
    }
    std::cout << code;
}

int main()
{
    std::string name;
    std::cout << "Enter your name:" << std::endl;
    std::cin >> name;
    CodeName(name);
}


