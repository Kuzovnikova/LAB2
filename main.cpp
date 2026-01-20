#include <iostream>
#include "tasks.h"

using namespace std;

void showMenu() {
    cout << "\n--- Выберите задачу (1-9) ---\n";
    cout << "1. Удвоить значения элементов\n";
    cout << "2. Вставка 5 элементов дека в список\n";
    cout << "3. Интерлейсинг списков\n";
    cout << "4. Замена цифр на '_'\n";
    cout << "5. Вставка нулей\n";
    cout << "6. Инверсия/Сдвиг половинок\n";
    cout << "7. Частичная сортировка вектора\n";
    cout << "9. Проверка подмножества\n";
    cout << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        showMenu();
        if (!(cin >> choice)) break;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 9: task9(); break;
        case 0: break;
        default: cout << "Ошибка выбора." << endl;
        }
    } while (choice != 0);

    return 0;
}
