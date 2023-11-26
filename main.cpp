#include <iostream>
#include <future>
#include <chrono>
#include <numeric>

// Функція для обчислення gcd з мемоізацією
int calculate_gcd(int a, int b) {
    return std::gcd(a, b);
}

// Функція для обчислення f
int calculate_f(int x) {
    return x * x;
}

// Функція для обчислення g
int calculate_g(int x) {
    return (x*255)%244;
}

int main() {
    std::setlocale(LC_ALL,"ukr");
    while (true) {
        int x;
        std::cout << "Enter x (or 0 to exit): ";
        std::cin >> x;

        if (x == 0) {
            break; // Виход при введенні 0
        }

        // Запускаємо асинхронно обчислення f та g
        auto result_f = std::async(std::launch::async, calculate_f, x);
        auto result_g = std::async(std::launch::async, calculate_g, x);

        // Очікуємо на результати обчислень
        int value_f = result_f.get();
        int value_g = result_g.get();

        // Розрахунок результату бінарної операції gcd
        int result_gcd = calculate_gcd(value_f, value_g);

        // Вивід результату
        std::cout << "f(x), g(x): " << calculate_f(x) << " , " << calculate_g(x) << std::endl;
        std::cout << "Result gcd(f(x), g(x)): " << result_gcd << std::endl;
    }

    return 0;
}
