#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
    int *data;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity)
    {
        int *newData = new int[newCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    Stack()
    {
        currentCapacity = 2;
        currentSize = 0;
        data = new int[currentCapacity];
    }

    Stack(const Stack &other)
    {
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[i];
        }
    }

    Stack &operator=(const Stack &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(int value)
    {
        if (currentSize == currentCapacity)
        {
            resize(currentCapacity * 2);
        }
        data[currentSize] = value;
        currentSize++;
    }

    void pop()
    {
        if (currentSize == 0)
        {
            cout << "stack already empty" << endl;
            return;
        }
        currentSize--;
    }

    int &top()
    {
        if (currentSize == 0)
        {
            throw out_of_range("stack is empty");
        }
        return data[currentSize - 1];
    }

    bool empty() const
    {
        return currentSize == 0;
    }

    void clear()
    {
        currentSize = 0;
    }

    void print() const
    {
        cout << "[Bottom] ";
        for (int i = 0; i < currentSize; i++)
        {
            cout << data[i];
            if (i != currentSize - 1)
            {
                cout << " ";
            }
        }
        cout << " [Top]" << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    s.pop();
    s.print();
    return 0;
}