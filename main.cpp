#include <iostream>
#include <cmath>
#include <limits>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

void clearConsole() {
    system(CLEAR_COMMAND);
}

void menu() {
    clearConsole();
    cout << "Меню" << endl;
    cout << "1. Типы квадратных уравнений" << endl;
    cout << "2. Решение квадратных уравнений" << endl;
    cout << "3. Методы решения квадратных уравнений" << endl;
    cout << "4. Выход из программы" << endl;
}

void types() {
    clearConsole();
    cout << "Типы квадратных уравнений:" << endl;
    cout << "1. 0 = 0" << endl;
    cout << "2. С = 0" << endl;
    cout << "3. ax^2 + bx + c = 0" << endl;
    cout << "4. ax^2 + bx = 0" << endl;
    cout << "5. ax^2 + c = 0" << endl;
    cout << "6. ax^2 = 0" << endl;
    cout << "7. bx + c = 0" << endl;
    cout << "8. bx = 0" << endl;
    cout << "Для продолжения нажмите enter 3 раза..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void solve() {
    clearConsole();
    float a, b, c;
    cout << "Введите коэффициенты a, b и c: ";
    cin >> a >> b >> c;

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float x1 = (-b + sqrt(discriminant)) / (2 * a);
        float x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Уравнение имеет два корня:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (discriminant == 0) {
        float x = -b / (2 * a);
        cout << "Уравнение имеет один корень:" << endl;
        cout << "x = " << x << endl;
    }
    else {
        cout << "Уравнение не имеет действительных корней." << endl;
    }

    cout << "Для продолжения нажмите enter 3 раза..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void methods() {
    clearConsole();
    cout << "Методы решения квадратных уравнений:" << endl;
    cout << "1. Дискриминант" << endl;
    cout << "   Если D > 0, то уравнение имеет два различных действительных корня." << endl;
    cout << "   Если D = 0, то уравнение имеет один действительный корень." << endl;
    cout << "   Если D < 0, то уравнение не имеет действительных корней." << endl;
    cout << "2. Метод полного квадрата" << endl;
    cout << "   Переместите постоянный член в правую часть уравнения: ax^2 + bx = -c" << endl;
    cout << "   Разделите обе части уравнения на a: x^2 + (b/a)x = -c/a" << endl;
    cout << "   Добавьте (b/2a)^2 к обеим частям уравнения: x^2 + (b/a)x + (b/2a)^2 = (b/2a)^2 - c/a" << endl;
    cout << "   Упростите левую часть уравнения: (x + b/2a)^2 = (b^2 - 4ac)/4a^2" << endl;
    cout << "   Извлеките квадратный корень из обеих частей уравнения: x + b/2a = ±sqrt((b^2 - 4ac)/4a^2)" << endl;
    cout << "   Решите для x: x = (-b ± sqrt(b^2 - 4ac))/(2a)" << endl;
    cout << "3. Теорема Виета" << endl;
    cout << "   Пусть x1 и x2 - корни квадратного уравнения ax^2 + bx + c = 0" << endl;
    cout << "   Тогда x1 + x2 = -b/a и x1 * x2 = c/a." << endl;

    cout << "Для продолжения нажмите enter 3 раза..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    int choice;
    setlocale(LC_ALL, "Russian");

    do {
        menu();
        cout << "Введите номер выбранного пункта: ";

        // Проверка на ввод числа
        while (!(cin >> choice)) {
            cout << "Неверный выбор. Попробуйте еще раз: ";

            // Очистка буфера ввода
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            types();
            break;
        case 2:
            solve();
            break;
        case 3:
            methods();
            break;
        case 4:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
cout << "Для продолжения нажмите enter 3 раза" << endl;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cin.get();

    } while (choice != 4);

    return 0;
}