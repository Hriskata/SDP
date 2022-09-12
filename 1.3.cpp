#include <iostream>

void ageToDays(int age)
{
    unsigned int days = age * 365;
    unsigned int hours = age * 365 * 24;
    unsigned long int minutes = age * 365 * 24 * 60;
    unsigned long long int seconds = age * 365 * 24 * 60 * 60;

    std::cout << "Days: " << days << std::endl;
    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Minutes: " << minutes << std::endl;
    std::cout << "Seconds: " << seconds << std::endl;
}

int main()
{
    int age;
    std::cout << "Enter your age : ";
    std::cin >> age;
    ageToDays(age);
}


