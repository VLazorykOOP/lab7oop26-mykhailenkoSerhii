#include <iostream>

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
using namespace std;

int main()
{
    cout << "Lab 7";

    cout << "Choose task to run" << endl;
    cout << "Task 1: Template functions" << endl;
    cout << "Task 2: Template functions 2" << endl;
    cout << "Task 3: Template classes" << endl;
    cout << "Task 4: Iterators" << endl;

    int choice = 0;
    cin >> choice;
    if (choice == 1)
        task1();
    if (choice == 2)
        task2();
    if (choice == 3)
        task3();
    if (choice == 4)
        task4();
}


