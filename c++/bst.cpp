#include <iostream>
using namespace std;

class BST
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;
    int currentSize;
    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            currentSize++;
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        { // assuming BST doesn't have dups
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool contains(Node *node, int value) const
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }

        if (value < node->data)
        {
            return contains(node->left, value);
        }
        else
        {
            return contains(node->right, value);
        }
    }

    Node *erase(Node *node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->data)
        {
            node->left = erase(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = erase(node->right, value);
        }
        else
        {
            // TODO: kinda complicated to remove, need some method to find parent
        }
        return node;
    }

    void clear(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        clear(node->left);
        clear(node->right);
        delete node;
    }

    void printInOrder(Node *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        printInOrder(node->left);
        cout << node->data << endl;
        printInOrder(node->right);
    }

    void printPreOrder(Node *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << endl;
        printInOrder(node->left);
        printInOrder(node->right);
    }

    void printPostOrder(Node *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        printInOrder(node->left);
        printInOrder(node->right);
        cout << node->data << endl;
    }

public:
    BST()
    {
        root = nullptr;
        currentSize = 0;
    }
    void insert(int value)
    {
        root = insert(root, value);
    }

    bool contains(int value) const
    {
        return contains(root, value);
    }

    void erase(int value)
    {
        root = erase(root, value);
    }

    void printInOrder() const
    {
        printInOrder(root);
        cout << endl;
    }

    void printPreOrder() const
    {
        printPreOrder(root);
        cout << endl;
    }

    void printPostOrder() const
    {
        printPostOrder(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);
    bst.insert(50);
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();

    return 0;
}