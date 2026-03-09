#include <iostream>
#include <stdexcept>
using namespace std;

class Queue
{
    int *data;
    int currentSize;
    int currentCapacity;
    int frontIndex;
    int backIndex;

    void resize(int newCapacity)
    {
        int *newData = new int[newCapacity];
        for (int i = 0; i < currentSize; i++)
        {
            newData[i] = data[(frontIndex + i) % currentCapacity];
        }

        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
        frontIndex = 0;
        backIndex = currentSize;
    }

public:
    Queue()
    {
        currentCapacity = 4;
        data = new int[currentCapacity];
        currentSize = 0;
        frontIndex = 0;
        backIndex = 0;
    }

    Queue(const Queue &other)
    {
        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        frontIndex = 0;
        backIndex = currentSize;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[(other.frontIndex + i) % other.currentCapacity];
        }
    }

    Queue &operator=(const Queue &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        frontIndex = 0;
        backIndex = currentSize;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[(other.frontIndex + i) % other.currentCapacity];
        }

        return *this;
    }

    ~Queue()
    {
        delete[] data;
    }

    void push(int value)
    {
        if (currentSize == currentCapacity)
        {
            resize(2 * currentCapacity);
        }
        data[backIndex] = value;
        backIndex = (backIndex + 1) % currentCapacity;
        currentSize++;
    }

    void pop()
    {
        frontIndex = (frontIndex + 1) % currentCapacity;
        currentSize--;
    }

    int &front()
    {
        return data[frontIndex];
    }

    int &back()
    {
        backIndex = (backIndex - 1) % currentCapacity;
        return data[backIndex];
    }

    void clear()
    {
        frontIndex = 0;
        backIndex = 0;
        currentSize = 0;
    }

    void print() const
    {
        cout << "[Front]";
        for (int i = 0; i < currentSize; i++)
        {
            cout << data[(frontIndex + i) % currentCapacity];
            if (i != currentSize - 1)
            {
                cout << " ";
            }
        }
        cout << "[Back]";
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.print();
    q.pop();
    q.print();
    return 0;
}