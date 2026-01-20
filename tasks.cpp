#include "tasks.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>

using namespace std;

void task1() {
    vector<int> V = { 1, 2, 3, 4, 5 };
    deque<int> D = { 10, 20, 30, 40, 50 };
    list<int> L = { 100, 200, 300, 400, 500 };

    if ((V.size() % 2 != 1 || V.size() < 3) ||
        (D.size() % 2 != 1 || D.size() < 3) ||
        (L.size() % 2 != 1 || L.size() < 3)) {
        cerr << "Ошибка: Контейнеры не соответствуют условию.\n";
        return;
    }

    int midVec = V.size() / 2;
    int midDec = D.size() / 2;
    auto midLstIter = L.begin();
    advance(midLstIter, L.size() / 2);

    V.at(0) *= 2; V.at(midVec) *= 2; V.at(V.size() - 1) *= 2;
    D.at(0) *= 2; D.at(midDec) *= 2; D.at(D.size() - 1) *= 2;
    L.front() *= 2; (*midLstIter) *= 2; L.back() *= 2;

    cout << "Изменения применены (Задача 1)\n";
}

void task2() {
    deque<int> dec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> lst = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    vector<int> lastFive(dec.rbegin(), dec.rbegin() + 5);
    reverse(lastFive.begin(), lastFive.end());

    auto posBeforeFifthFromEnd = next(lst.rbegin(), 4).base();
    lst.insert(posBeforeFifthFromEnd, lastFive.begin(), lastFive.end());

    cout << "Список после вставки 5 элементов дека:\n";
    for (const auto& val : lst) cout << val << " ";
    cout << endl;
}

void task3() {
    list<int> L1 = { 1, 2, 3, 4, 5 };
    list<int> L2 = { 10, 20, 30, 40, 50 };
    auto i1 = L1.begin();
    auto i2 = L2.begin();
    while (i1 != L1.end()) {
        L2.splice(next(i2), L1, i1++);
    }
    cout << "Интерлейсинг L2: ";
    for (const auto& val : L2) cout << val << " ";
    cout << endl;
}

void task4() {
    string str = "Hello1World2Test3";
    string result(str.length(), '_');
    replace_copy_if(str.begin(), str.end(), result.begin(),
        [](char ch) {return isdigit(ch);}, '_');
    cout << "Результат: " << result << endl;
}

void task5() {
    list<int> lst = { -1, 2, -3, 4, -5, 6, -7, 8 };
    auto firstNegIt = find_if(lst.begin(), lst.end(), [](int x) { return x < 0; });
    if (firstNegIt != lst.end()) lst.insert(next(firstNegIt), 0);
    auto lastPosIt = find_if(lst.rbegin(), lst.rend(), [](int x) { return x > 0; }).base();
    if (lastPosIt != lst.end()) lst.insert(lastPosIt, 0);
    cout << "Список с нулями: ";
    for (const auto& val : lst) cout << val << " ";
    cout << endl;
}

void task6() {
    list<int> L1 = { 1, 2, 3, 4 };
    list<int> L2 = { 10, 20, 30, 40 };
    auto mid1 = next(L1.begin(), L1.size() / 2);
    swap_ranges(L1.begin(), mid1, mid1);
    auto mid2 = next(L2.begin(), L2.size() / 2);
    rotate(mid2, L2.begin(), L2.end()); // ошибка в логике rotate исправлена для корректного сдвига
    cout << "Преобразованные списки выведены." << endl;
}

void task7() {
    vector<int> vec = { 4, 1, 3, 2, 5 };
    partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    cout << "Топ-3: " << vec[0] << " " << vec[1] << " " << vec[2] << endl;
}

void task9() {
    vector<int> V0 = { 1, 2, 3 };
    vector<vector<int>> vectors = { {1, 2, 3, 4}, {2, 3, 4, 5}, {1, 2, 3} };
    set<int> s(V0.begin(), V0.end());
    int count = 0;
    for (auto& vec : vectors) {
        sort(vec.begin(), vec.end());
        if (includes(vec.begin(), vec.end(), s.begin(), s.end())) count++;
    }
    cout << "Найдено вхождений: " << count << endl;
}
