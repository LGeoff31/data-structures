#include <iostream>
using namespace std;

class HashSet
{
private:
    struct Node
    {
        int value;
        Node *next;

        Node(int v)
        {
            value = v;
            next = nullptr;
        }
    };

    Node **buckets;
    int bucketCount;
    int currentSize;
    double maxLoadFactor;

    int hashFunction(int value) const
    {
        return (value % bucketCount + bucketCount) % bucketCount;
    }

    void rehash()
    {
        int oldBucketCount = bucketCount;
        Node **oldBuckets = buckets;

        bucketCount *= 2;
        buckets = new Node *[bucketCount];

        for (int i = 0; i < currentSize; i++)
        {
            buckets[i] = nullptr;
        }
        currentSize = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            Node *curr = oldBuckets[i];
            while (curr)
            {
                insert(curr->value);
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }

        delete[] oldBuckets;
    }

    double loadFactor() const
    {
        return static_cast<double>(currentSize / bucketCount);
    }

public:
    HashSet()
    {
        bucketCount = 8;
        currentSize = 0;
        maxLoadFactor = 0.75;
        buckets = new Node *[bucketCount];

        for (int i = 0; i < bucketCount; i++)
        {
            buckets[i] = nullptr;
        }
    }

    HashSet(const HashSet &other)
    {
        bucketCount = other.bucketCount;
        currentSize = 0;
        maxLoadFactor = other.maxLoadFactor;
        buckets = new Node *[bucketCount];

        for (int i = 0; i < bucketCount; i++)
        {
            buckets[i] = nullptr;
        }

        for (int i = 0; i < other.bucketCount; i++)
        {
            Node *curr = other.buckets[i];
            while (curr != nullptr)
            {
                insert(curr->value);
                curr = curr->next;
            }
        }
    }

    HashSet &operator=(const HashSet &other)
    {
        if (this == &other)
        {
            return *this;
        }

        clear();
        delete[] buckets;

        bucketCount = other.bucketCount;
        currentSize = 0;
        maxLoadFactor = other.maxLoadFactor;
        buckets = new Node *[bucketCount];

        for (int i = 0; i < bucketCount; i++)
        {
            buckets[i] = nullptr;
        }

        for (int i = 0; i < other.bucketCount; i++)
        {
            Node *curr = other.buckets[i];
            while (curr != nullptr)
            {
                insert(curr->value);
                curr = curr->next;
            }
        }

        return *this;
    }

    ~HashSet()
    {
        clear();
        delete[] buckets;
    }

    void insert(int value)
    {
        if (loadFactor() > maxLoadFactor)
        {
            rehash();
        }

        int index = hashFunction(value);
        Node *newNode = new Node(value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        currentSize++;
    }

    bool contains(int value) const
    {
        int index = hashFunction(value);
        Node *curr = buckets[index];
        while (curr)
        {
            if (curr->value == value)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void erase(int value)
    {
        int index = hashFunction(value);
        Node *curr = buckets[index];
        Node *prev = nullptr;

        while (curr)
        {
            if (curr->value == value)
            {
                if (prev == nullptr)
                {
                    buckets[index] = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                currentSize--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void clear()
    {
        for (int i = 0; i < bucketCount; i++)
        {
            Node *curr = buckets[i];
            while (curr != nullptr)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            buckets[i] = nullptr;
        }
        currentSize = 0;
    }

    void print() const
    {
        for (int i = 0; i < bucketCount; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *curr = buckets[i];

            while (curr != nullptr)
            {
                cout << curr->value;
                if (curr->next != nullptr)
                {
                    cout << " -> ";
                }
                curr = curr->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    HashSet s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.print();
    s.erase(20);
    s.print();

    return 0;
}