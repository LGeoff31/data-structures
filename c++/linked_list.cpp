#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    int currentSize;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        currentSize = 0;
    }

    LinkedList(const LinkedList &other)
    {
        head = nullptr;
        tail = nullptr;
        currentSize = 0;

        Node *curr = other.head;
        while (curr != nullptr)
        {
            push_back(curr->data);
            curr = curr->next;
        }
    }

    LinkedList &operator=(const LinkedList &other)
    {
        if (this == &other)
        {
            return *this;
        }

        clear();

        Node *curr = other.head;
        while (curr != nullptr)
        {
            push_back(curr->data);
            curr = curr->next;
        }

        return *this;
    }

    ~LinkedList()
    {
        clear();
    }

    void push_front(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr)
        {
            tail = newNode;
        }
        currentSize++;
    }

    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "list empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        currentSize--;
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            cout << "list empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            currentSize = 0;
            return;
        }
        Node *curr = head;
        while (curr->next != tail)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = nullptr;
        delete temp;
        currentSize--;
    }

    void insert(int index, int value)
    {
        Node *cur = head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        Node *newNode = new Node(value);
        newNode->next = cur->next;
        cur->next = newNode;
        currentSize++;
    }

    void erase(int index)
    {
        if (index < 0 || index >= currentSize)
        {
            throw out_of_range("Index out of bounds");
        }

        if (index == 0)
        {
            pop_front();
            return;
        }

        Node *curr = head;
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        Node *nodeToDelete = curr->next;
        curr->next = nodeToDelete->next;

        if (nodeToDelete == tail)
        {
            tail = curr;
        }

        delete nodeToDelete;
        currentSize--;
    }

    int find(int value) const
    {
        Node *curr = head;
        int index = 0;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                return index;
            }
            curr = curr->next;
            index++;
        }

        return -1;
    }

    void clear()
    {
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr;
            delete curr;
            curr = temp->next;
        }
        head = nullptr;
        tail = nullptr;
        currentSize = 0;
    }

    int &back()
    {
        if (tail == nullptr)
        {
            throw out_of_range("List is empty");
        }

        return tail->data;
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
        Node *curr = head;
        cout << "[";

        while (curr != nullptr)
        {
            cout << curr->data;
            if (curr->next != nullptr)
            {
                cout << " -> ";
            }
            curr = curr->next;
        }

        cout << "]" << endl;
    }
};

int main()
{
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.print();
    list.erase(1);
    list.print();
    list.pop_back();
    list.print();
    return 0;
}