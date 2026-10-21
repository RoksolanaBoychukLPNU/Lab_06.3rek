#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// 1)

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// рекурсивно знаходить найбільший з парних елементів масиву;
// i       - поточний індекс,
// maxEven - (вихідний параметр) найбільший парний серед переглянутих,
// found   - чи знайдено вже хоча б один парний елемент;
// повертає true, якщо парні елементи є
bool MaxEven(int* a, const int size, int i, int& maxEven, bool found)
{
    if (i == size)
        return found;
    if (a[i] % 2 == 0 && (!found || a[i] > maxEven))
    {
        maxEven = a[i];
        found = true;
    }
    return MaxEven(a, size, i + 1, maxEven, found);
}

// 2)

template <typename T>
void Create(T* a, const int size, const int Low, const int High, int i)
{
    a[i] = (T)(Low + rand() % (High - Low + 1));
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
bool MaxEven(T* a, const int size, int i, T& maxEven, bool found)
{
    if (i == size)
        return found;
    if (a[i] % 2 == 0 && (!found || a[i] > maxEven))
    {
        maxEven = a[i];
        found = true;
    }
    return MaxEven<T>(a, size, i + 1, maxEven, found);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;       
    int Low = -50;          
    int High = 50;          

    // 1) звичайні функції, масив типу int
    int a[n];
    Create(a, n, Low, High, 0);
    Print(a, n, 0);
    int maxA;
    if (MaxEven(a, n, 0, maxA, false))
        cout << "MaxEven(a, n)            = " << maxA << endl;
    
    cout << endl;

    // 2) шаблони функцій, масив типу int
    int b[n];
    Create<int>(b, n, Low, High, 0);
    Print<int>(b, n, 0);
    int maxB;
    if (MaxEven<int>(b, n, 0, maxB, false))
        cout << "MaxEven<int>(b, n)       = " << maxB << endl;
    cout << endl;

    // 3) шаблони функцій, масив типу long long
    long long c[n];
    Create<long long>(c, n, Low, High, 0);
    Print<long long>(c, n, 0);
    long long maxC;
    if (MaxEven<long long>(c, n, 0, maxC, false))
        cout << "MaxEven<long long>(c, n) = " << maxC << endl;

    return 0;
}
