#pragma once
#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
    // Дійсна частина (real)
    double re; // зберігає число без "i"

    // Уявна частина (imaginary)
    double im; // зберігає число біля "i"

    // Допоміжний метод для обчислення модуля комплексного числа
    double abs() const; // використовується для порівнянь >, <, >=, <=

public:
    // ================= КОНСТРУКТОРИ =================

    // Конструктор за умовчанням (без параметрів)
    Complex();                                  // ініціалізує нулями (0 + 0i)

    // Конструктор ініціалізації (з параметрами)
    Complex(double realPart, double imagPart);  // встановлює задані значення

    // Конструктор копіювання
    Complex(const Complex& other);              // створює копію іншого об'єкта

    // ================= ДЕСТРУКТОР =================

    // Стандартний деструктор
    ~Complex();                                 // порожній, бо не використовуємо new

    // ================= МЕТОДИ ДОСТУПУ =================

    // Отримати дійсну частину
    double getRe() const;
    // Змінити дійсну частину
    void setRe(double realPart);

    // Отримати уявну частину
    double getIm() const;
    // Змінити уявну частину
    void setIm(double imagPart);

    // ================= ПЕРЕВАНТАЖЕННЯ ОПЕРАЦІЙ (Методи класу) =================

    // Перевантаження операції присвоєння (c1 = c2)
    Complex& operator=(const Complex& other);   // обов'язково метод класу за методичкою

    // Перетворення об'єкта в текст (для зручного виводу)
    operator string() const;                    // приведення типу до літерного рядка

    // ================= ДРУЖНІ ФУНКЦІЇ (Бінарні операції) =================

    // Порівняння: чи рівні два числа
    friend bool operator==(const Complex& a, const Complex& b); // перевіряє re та im окремо

    // Порівняння: чи не рівні два числа
    friend bool operator!=(const Complex& a, const Complex& b);

    // Порівняння: чи перше число більше за друге
    friend bool operator>(const Complex& a, const Complex& b);  // порівнює за модулем

    // Порівняння: чи перше число менше за друге
    friend bool operator<(const Complex& a, const Complex& b);  // порівнює за модулем

    // Порівняння: чи перше число більше або дорівнює другому
    friend bool operator>=(const Complex& a, const Complex& b); // порівнює за модулем

    // Порівняння: чи перше число менше або дорівнює другому
    friend bool operator<=(const Complex& a, const Complex& b); // порівнює за модулем

    // ================= ПОТОКОВИЙ ВВІД/ВИВІД =================

    // Перевантаження оператора виводу (<<) для роботи з cout
    friend ostream& operator<<(ostream& out, const Complex& c);

    // Перевантаження оператора вводу (>>) для роботи з cin
    friend istream& operator>>(istream& in, Complex& c);
};