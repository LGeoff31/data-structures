#include <iostream>
using namespace std;

class HashMap
{
    struct Node
    {
        int key;
        int value;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    Node **buckets;
    int bucketCount;
    int currentSize;
    double maxLoadFactor;

    int hashFunction(int key) const
    {
        return (key % bucketCount + bucketCount) % bucketCount;
    }

    double loadFactor() const
    {
        return static_cast<double>(currentSize) / bucketCount;
    }

    void rehash()
    {
        int oldBucketCount = bucketCount;
        Node **oldBuckets = buckets;

        bucketCount = bucketCount * 2;
        buckets = new Node *[bucketCount];

        for (int i = 0; i < bucketCount; i++)
        {
            buckets[i] = nullptr;
        }

        int oldSize = currentSize;
        currentSize = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            Node *curr = oldBuckets[i];
            while (curr != nullptr)
            {
                put(curr->key, curr->value);
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }

        delete[] oldBuckets;
    }

public:
    HashMap()
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

    HashMap(const HashMap &other)
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
                put(curr->key, curr->value);
                curr = curr->next;
            }
        }
    }

    HashMap &operator=(const HashMap &other)
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
                put(curr->key, curr->value);
                curr = curr->next;
            }
        }

        return *this;
    }

    ~HashMap()
    {
        clear();
        delete[] buckets;
    }

    void put(int key, int value)
    {
        int index = hashFunction(key);
        Node *curr = buckets[index];

        while (curr)
        {
            if (curr->value == value)
            {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        if (loadFactor() > maxLoadFactor)
        {
            rehash();
            index = hashFunction(key);
        }

        Node *newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        currentSize++;
    }

    bool containsKey(int key) const
    {
        int index = hashFunction(key);
        Node *curr = buckets[index];
        while (curr)
        {
            if (curr->key == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    int &get(int key)
    {
        int index = hashFunction(key);
        Node *curr = buckets[index];

        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }

        throw out_of_range("Key not found");
    }

    void erase(int key)
    {
        int index = hashFunction(key);
        Node *curr = buckets[index];
        Node *prev = nullptr;

        while (curr)
        {
            if (curr->key == key)
            {
                if (prev == nullptr)
                {
                    buckets[index] = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                currentSize--;
                delete curr;
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
            while (curr)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            buckets[i] = nullptr;
        }
    }

    int size() const
    {
        return currentSize;
    }

    bool empty() const
    {
        return currentSize == 0;
    }

    void print() const
    {
        for (int i = 0; i < bucketCount; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *curr = buckets[i];

            while (curr != nullptr)
            {
                cout << "(" << curr->key << ", " << curr->value << ")";
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
    HashMap mp;
    mp.put(10, 100);
    mp.put(20, 200);
    mp.put(30, 300);
    mp.print();
    mp.erase(30);
    mp.print();
    cout << "Value associated with key 20: " << mp.get(20) << endl;

    return 0;
}