#include <iostream>
#include <Windows.h>
#include "Complex.h"

using namespace std;

// Структура для демонстрації #pragma pack(1)
#pragma pack(push, 1)
class ComplexPacked {
    double re;
    double im;
};
#pragma pack(pop)

int main() {
    // Встановлюємо правильне кодування для консолі
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Розмір класу Complex без #pragma pack(1): " << sizeof(Complex) << " байт" << endl;
    cout << "Розмір класу з #pragma pack(1): " << sizeof(ComplexPacked) << " байт" << endl;
    cout << "-------------------------------------------------" << endl;

    // Створення об'єктів різними конструкторами
    Complex c1;               // За умовчанням (0 + 0i)
    Complex c2(3.0, 4.0);     // Ініціалізації (модуль = 5)
    Complex c3(1.0, -1.0);    // Ініціалізації
    Complex c4 = c2;          // Копіювання

    cout << "c1 (за умовчанням) : " << c1 << endl;
    cout << "c2 (ініціалізації) : " << c2 << endl;
    cout << "c3 (ініціалізації) : " << c3 << endl;
    cout << "c4 (копіювання c2) : " << c4 << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація операторів порівняння
    cout << "Порівняння c2 (" << c2 << ") та c3 (" << c3 << "):" << endl;

    if (c2 == c4) cout << "c2 == c4 : Істина (вони однакові)" << endl;
    if (c2 != c3) cout << "c2 != c3 : Істина (вони різні)" << endl;

    if (c2 > c3)  cout << "c2 > c3  : Істина (модуль c2 більший за модуль c3)" << endl;
    if (c3 < c2)  cout << "c3 < c2  : Істина" << endl;
    if (c2 >= c4) cout << "c2 >= c4 : Істина" << endl;
    if (c1 <= c3) cout << "c1 <= c3 : Істина" << endl;

    cout << "-------------------------------------------------" << endl;

    // Демонстрація введення з клавіатури
    Complex c5;
    cout << "Введення власного комплексного числа:" << endl;
    cin >> c5;
    cout << "Ви ввели число: " << c5 << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація масиву об'єктів
    cout << "Масив комплексних чисел:" << endl;
    Complex arr[3] = { Complex(1, 2), Complex(3, -4), Complex() };
    for (int i = 0; i < 3; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}