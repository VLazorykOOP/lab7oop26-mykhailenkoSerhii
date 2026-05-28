#include "Task1.h"
#include <iostream>

using namespace std;

template<typename T> void min(T* arr, int n, T& min)
{
    for (int i = 0; i < n; ++i)
    {
        T val = arr[i];
        if (val < min)
            min = val;
    }
}

template<> void min(char* arr, int n, char& min)
{
    for (int i = 0; i < n; ++i)
    {
        char val = arr[i];
        if (val < min)
            min = val;
    }
}

void task1()
{
    cout << "Input the desired amount of elements : " << endl;
    int n;
    cin >> n;

    char arr[n];
    cout << "Input the elements: " << endl;
    for (int i = 0; i < n; ++i)
    {
        char element;
        cin >> element;
        arr[i] = element;
    }

    char minValue = 'z';
    min(arr, n, minValue);
    cout << "Minimum found - " << minValue << endl;
}