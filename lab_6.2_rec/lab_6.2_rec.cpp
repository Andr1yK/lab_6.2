#include <iostream>
#include <iomanip>

using namespace std;

void Print(int* list, const int size, int i);
void Sort(int* list, const int size, int i);
void SortInner(int* list, const int size, int i, int j);
void Create(int* list, const int size, const int Min, const int Max, int i);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    const int n = 25;
    int a[n];

    int Min = 0;
    int Max = 90;

    cout << "Рекурсивний спосiб" << endl;
    cout << endl;

    Create(a, n, Min, Max, 0);
    cout << "Before: "; Print(a, n, 0);
    Sort(a, n, 0);
    cout << "Sorted: "; Print(a, n, 0);
}

// Заповнення масиву випадковими значеннями
void Create(int* list, const int size, const int Min, const int Max, int i) {
    if (i < size)
    {
        list[i] = rand() % (Max - Min + 1) + Min;
        return Create(list, size, Min, Max, ++i);
    }
}

// Сортування масиву (зовнішній цикл)
void Sort(int* list, const int size, int i) {
    if (i < size - 1) {
        SortInner(list, size, i, 0);
        Sort(list, size, ++i);
    }
}

// Сортування масиву (внутрішний цикл)
void SortInner(int* list, const int size, int i, int j) {
    if (j < size - i -1) {
        if (list[j] < list[j + 1]) {
            swap(list[j], list[j + 1]);
        }
        SortInner(list, size, i, ++j);
    }
}

// Вивід масиву
void Print(int* list, const int size, int i)
{
    if (i < size) {
        cout << setw(3) << list[i];
        return Print(list, size, ++i);
    }
    cout << endl;
}