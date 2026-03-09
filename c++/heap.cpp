#include <iostream>
#include <cassert>
using namespace std;

class MinHeap
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

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (data[index] < data[parentIndex])
            {
                int temp = data[index];
                data[index] = data[parentIndex];
                data[parentIndex] = temp;
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < currentSize && data[leftChild] < data[smallest])
            {
                smallest = leftChild;
            }

            if (rightChild < currentSize && data[rightChild] < data[smallest])
            {
                smallest = rightChild;
            }

            if (smallest != index)
            {
                int temp = data[index];
                data[index] = data[smallest];
                data[smallest] = temp;
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }

public:
    MinHeap()
    {
        currentCapacity = 4;
        currentSize = 0;
        data = new int[currentCapacity];
    }

    MinHeap(const MinHeap &other)
    {
        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[i];
        }
    }

    MinHeap &operator=(const MinHeap &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        data = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    ~MinHeap()
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
        heapifyUp(currentSize);
        currentSize++;
    }

    void pop()
    {
        assert(currentSize > 0);
        data[0] = data[currentSize - 1];
        currentSize--;
        heapifyDown(0);
    }

    int &top()
    {
        if (currentSize == 0)
        {
            throw out_of_range("Heap is empty");
        }

        return data[0];
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
        currentSize = 0;
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
        cout << "]" << endl;
    }
};

int main()
{
    MinHeap h;
    h.push(10);
    h.push(20);
    h.push(30);
    h.push(4);

    h.print();
    h.pop();
    h.print();
    return 0;
}