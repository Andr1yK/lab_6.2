#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* list, const int size, const int Min, const int Max);
void Sort(int* list, const int size);
void Print(int* list, const int size);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    const int n = 25;

    int a[n];

    int Min = 0;
    int Max = 90;

    cout << "Iтерацiйний спосiб" << endl;
    cout << endl;

    Create(a, n, Min, Max);
    cout << "Before: "; Print(a, n);
    Sort(a, n);
    cout << "Sorted: "; Print(a, n);
}

// Заповнення масиву випадковими значеннями
void Create(int* list, const int size, const int Min, const int Max)
{
    for (int i = 0; i < size; i++)
        list[i] = rand() % (Max - Min + 1) + Min; // де Min - ліва межа, а Max - права
}


// Сортування масиву
void Sort(int* list, const int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] < list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

// Вивід масиву
void Print(int* list, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(3) << list[i];
    cout << endl;
}