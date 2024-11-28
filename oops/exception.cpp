#include <iostream>
#include <stdexcept>

class Division {
public:
    double divide(double numerator, double denominator) {
        if (denominator == 0) {
            throw std::runtime_error("Division by zero error");
        }
        return numerator / denominator;
    }
};

int main() {
    Division div;
    double num, denom, result;

    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> denom;

    try {
        result = div.divide(num, denom);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}