#include "Task3.h"
#include <iostream>

using namespace std;

template <typename T> class Matrix
{
    int rows;
    int cols;
    T** data;

    void allocate()
    {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]{};
    }

    void deallocate()
    {
        if (data != nullptr)
        {
            for (int i = 0; i < rows; ++i)
                delete[] data[i];

            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        allocate();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
    {
        allocate();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];


    }

    ~Matrix()
    {
        deallocate();
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this == &other) return *this;

        deallocate();

        rows = other.rows;
        cols = other.cols;
        allocate();

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];

        return *this;
    }

    T* operator[](int index)
    {
        return data[index];
    }

    Matrix& operator+=(const Matrix& other)
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] += other.data[i][j];

        return *this;
    }

    Matrix operator+(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    void print() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                std::cout << data[i][j] << "\t";

            std::cout << "\n";
        }
    }
};

void task3()
{
    int x;
    cout << "Input size for square matrix: " << endl;
    cin >> x;
    Matrix<int> m1(x, x);

    for (int i = 0; i < x; ++i)
    {
        cout << "Input row " << i << ": ";
        for (int j = 0; j < x; ++j)
        {
            int element;
            cin >> element;
            m1[i][j] = element;
        }
        cout << endl;
    }
    Matrix<int> m2(2, 2);
    m2[0][0] = 5; m2[0][1] = 6;
    m2[1][0] = 7; m2[1][1] = 8;

    std::cout << "Matrix m1: " << endl;
    m1.print();

    std::cout << "Matrix m2: " << endl;
    m2.print();

    Matrix<int> m3 = m1 + m2;
    std::cout << "m3 = m1 + m2: " << endl;
    m3.print();

    m1 += m2;
    std::cout << "m1 after m1 += m2: " << endl;
    m1.print();

    Matrix<int> m4(1, 1);
    m4 = m3;
    std::cout << "m4 after m4 = m3: " << endl;
    m4.print();
}