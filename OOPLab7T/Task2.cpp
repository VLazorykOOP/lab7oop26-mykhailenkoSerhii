#include "Task2.h"
#include <iostream>

using namespace std;

template<typename t> void shellSort(t* arr, int n)
{
    int gap = 1;
    while (gap < n / 3)
        gap = gap * 3 + 1;

    for (; gap > 0; gap /= 3)
    {
        for (int i = gap; i < n; i++)
        {
            t temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

template<> void shellSort(char* arr, int n)
{
    int gap = 1;
    while (gap < n / 3)
        gap = gap * 3 + 1;

    for (; gap > 0; gap /= 3)
    {
        for (int i = gap; i < n; i++)
        {
            char temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void task2()
{
    cout << "Input how many elements: " << endl;
    int n;
    cin >> n;

    cout << "Input your elements: " << endl;
    char arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    shellSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << "Element " << i << " : " << arr[i] << endl;
}
