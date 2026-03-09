#include <iostream>
using namespace std;

class Vector
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
    Vector()
    {
        currentSize = 0;
        currentCapacity = 2;
        data = new int[currentCapacity];
    }

    Vector(const Vector &other)
    { // copy constructor
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new int[currentCapacity]; // this is important so these don't point to same memory address since its dynamically allocated on the HEAPP

        for (int i = 0; i < currentCapacity; i++)
        {
            data[i] = other.data[i];
        }
    }

    Vector &operator=(const Vector &other)
    {
        if (this == &other)
            return *this; // prevents a=a; when memory is freed

        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new int[currentCapacity]; // this is important so these don't point to same memory address since its dynamically allocated on the HEAPP

        for (int i = 0; i < currentCapacity; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    ~Vector()
    {
        delete[] data;
    }

    void push_back(int elem)
    {
        if (currentSize == currentCapacity)
        {
            resize(2 * currentCapacity);
        }
        data[currentSize++] = elem;
    }

    void pop_back()
    {
        if (currentSize == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }
        currentSize--;
    }

    void insert(int index, int value)
    {
        if (index < 0 || index >= currentSize)
        {
            throw out_of_range("index out of bounds");
        }
        if (currentSize == currentCapacity)
        {
            resize(2 * currentCapacity);
        }
        for (int i = currentSize; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        currentSize++;
    }

    void erase(int index)
    {
        if (index < 0 || index >= currentSize)
        {
            throw out_of_range("index out of bounds");
        }

        for (int i = index; i < currentSize - 1; i++)
        {
            data[i] = data[i + 1];
        }

        currentSize--;
    }

    void clear()
    {
        currentSize = 0;
    }

    int find(int value)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (data[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= currentSize)
        {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int &front()
    {
        if (currentSize == 0)
        {
            throw out_of_range("Array is empty");
        }
        return data[0];
    }
    int &back()
    {
        if (currentSize == 0)
        {
            throw out_of_range("Array is empty");
        }
        return data[currentSize - 1];
    }

    int size() const
    {
        return currentSize;
    }

    int capacity() const
    {
        return currentCapacity;
    }

    bool empty() const
    {
        return currentSize == 0;
    }

    void print() const
    {
        cout << "[";
        for (int i = 0; i < currentSize; i++)
        {
            cout << data[i];
            if (i != currentSize - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
    }
};

int main()
{
    Vector arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    arr.print();

    cout << arr.size() << endl;
    cout << arr.capacity() << endl;

    arr.pop_back();
    cout << arr.size() << endl;

    arr.print();
}