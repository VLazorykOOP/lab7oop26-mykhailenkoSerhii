#include "Task4.h"
#include <iostream>

using namespace std;

template <typename T> class LinkedList
{
    struct Node
    {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push_back(T value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    class Iter
    {
    private:
        Node* current;

    public:
        Iter(Node* node) : current(node) {}

        T& operator*()
        {
            return current->data;
        }

        Iter& operator++()
        {
            if (current != nullptr)
                current = current->next;

            return *this;
        }

        bool operator!=(const Iter& other) const
        {
            return current != other.current;
        }
    };

    Iter begin()
    {
        return Iter(head);
    }

    Iter end()
    {
        return Iter(nullptr);
    }
};

void task4()
{
    LinkedList<int> myList;
    cout << "Input amount of elements to input into the iterator" << endl;
    int n;
    cin >> n;

    cout << "Enter elements for the iterator to iterate: " << endl;
    for (int i = 0; i < n; ++i)
    {
        int element;
        cin >> element;
        myList.push_back(element);
    }

    for (LinkedList<int>::Iter it = myList.begin(); it != myList.end(); ++it)
        cout << "Element: " <<  *it << " ";

    cout << endl;
}