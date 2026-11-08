#include "Complex.h"
#include <sstream> 
#include <cmath>   

// Конструктор за умовчанням (без параметрів)
Complex::Complex() {
    setRe(0.0); // ініціалізація дійсної частини нулем
    setIm(0.0); // ініціалізація уявної частини нулем
}

// Конструктор ініціалізації (з параметрами)
Complex::Complex(double realPart, double imagPart) {
    setRe(realPart); // ініціалізація заданою дійсною частиною
    setIm(imagPart); // ініціалізація заданою уявною частиною
}

// Конструктор копіювання (створює копію іншого об'єкта)
Complex::Complex(const Complex& other) {
    re = other.re; // копіювання дійсної частини
    im = other.im; // копіювання уявної частини
}

// Стандартний деструктор (нічого не робить, бо немає динамічної пам'яті)
Complex::~Complex() {}

// Отримати дійсну частину
double Complex::getRe() const { return re; }

// Змінити дійсну частину
void Complex::setRe(double realPart) { re = realPart; }

// Отримати уявну частину
double Complex::getIm() const { return im; }

// Змінити уявну частину
void Complex::setIm(double imagPart) { im = imagPart; }

// Обчислення модуля (довжини) комплексного числа
double Complex::abs() const {
    return sqrt(re * re + im * im); // корінь з суми квадратів
}

// Перевантаження операції присвоєння (c1 = c2)
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) { // захист від самоприсвоєння
        re = other.re;    // копіювання дійсної частини
        im = other.im;    // копіювання уявної частини
    }
    return *this;         // повернення поточного об'єкта
}

// Перетворення об'єкта в текст (для зручного виводу)
Complex::operator string() const {
    stringstream ss;
    ss << re << (im >= 0 ? " + " : " - ") << std::abs(im) << "i"; // форматування "3 + 4i"
    return ss.str();
}

// Порівняння: чи рівні два числа (окремо дійсна і уявна частини)
bool operator==(const Complex& a, const Complex& b) {
    return (a.re == b.re) && (a.im == b.im); // порівняння на рівність
}

// Порівняння: чи не рівні два числа
bool operator!=(const Complex& a, const Complex& b) {
    return !(a == b);                        // порівняння на нерівність
}

// Порівняння: чи перше число більше за друге
bool operator>(const Complex& a, const Complex& b) {
    return a.abs() > b.abs();                // більше (за модулем)
}

// Порівняння: чи перше число менше за друге
bool operator<(const Complex& a, const Complex& b) {
    return a.abs() < b.abs();                // менше (за модулем)
}

// Порівняння: чи перше число більше або дорівнює другому
bool operator>=(const Complex& a, const Complex& b) {
    return a.abs() >= b.abs();               // більше або рівне (за модулем)
}

// Порівняння: чи перше число менше або дорівнює другому
bool operator<=(const Complex& a, const Complex& b) {
    return a.abs() <= b.abs();               // менше або рівне (за модулем)
}

// Перевантаження оператора виводу (<<) для роботи з cout
ostream& operator<<(ostream& out, const Complex& c) {
    out << string(c);                        // виведення на екран
    return out;
}

// Перевантаження оператора вводу (>>) для роботи з cin
istream& operator>>(istream& in, Complex& c) {
    double r, i;
    cout << " Введіть дійсну частину (Re): ";
    in >> r; // зчитування дійсної частини
    cout << " Введіть уявну частину (Im): ";
    in >> i; // зчитування уявної частини

    c.setRe(r); // безпечний запис дійсної частини
    c.setIm(i); // безпечний запис уявної частини
    return in;
}