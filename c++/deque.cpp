#include <iostream>
#include <stdexcept>
using namespace std;

class Deque
{
    int *data;
    int currentSize;
    int currentCapacity;
    int frontIndex;

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
    }

public:
    Deque()
    {
        currentCapacity = 4;
        data = new int[currentCapacity];
        currentSize = 0;
        frontIndex = 0;
    }

    Deque(const Deque &other)
    {
        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        frontIndex = 0;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[(other.frontIndex + i) % other.currentCapacity];
        }
    }

    Deque &operator=(const Deque &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        frontIndex = 0;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[(other.frontIndex + i) % other.currentCapacity];
        }

        return *this;
    }

    ~Deque()
    {
        delete[] data;
    }

    void push_front(int value)
    {
        if (currentSize == currentCapacity)
        {
            resize(2 * currentCapacity);
        }
        frontIndex = (frontIndex - 1) % currentCapacity;
        data[frontIndex] = value;
        currentSize++;
    }

    void push_back(int value)
    {
        if (currentSize == currentCapacity)
        {
            resize(2 * currentCapacity);
        }
        int backIndex = (frontIndex + currentSize) % currentCapacity;
        data[backIndex] = value;
        currentSize++;
    }

    void pop_front()
    {
        frontIndex = (frontIndex + 1) % currentCapacity;
        currentSize--;
    }

    void pop_back()
    {
        currentSize--;
    }

    int &front()
    {
        if (currentSize == 0)
        {
            throw out_of_range("Deque is empty");
        }

        return data[frontIndex];
    }

    int &back()
    {
        if (currentSize == 0)
        {
            throw out_of_range("Deque is empty");
        }

        int backIndex = (frontIndex + currentSize - 1) % currentCapacity;
        return data[backIndex];
    }

    int size() const
    {
        return currentSize;
    }

    bool empty() const
    {
        return currentSize == 0;
    }

    void clear()
    {
        frontIndex = 0;
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
    Deque q;
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);

    q.print();
    q.pop_back();
    q.print();
    q.pop_front();
    q.print();
    return 0;
}