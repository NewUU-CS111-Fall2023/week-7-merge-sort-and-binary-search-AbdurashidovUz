#include <iostream>
#include <cmath>
#include <string>


int recursivePow(int x, int n) {
    if (n == 0) {
        return 1; 
    }

    int half = recursivePow(x, n / 2);
    int result = half * half;

    if (n % 2 == 1) {
        result *= x; 
    }

    return result;
}


int getNumberLength(int number) {
    std::string numberString = std::to_string(number);
    return numberString.length();
}


int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    int length = getNumberLength(number);
    int result = recursivePow(number, length);

    std::cout << "The result is: " << result << std::endl;

    return 0;
}