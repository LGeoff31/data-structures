#include <iostream>
using namespace std;

class Trie
{
    struct Node
    {
        Node *children[26];
        bool isEndOfWord;
        Node()
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
            isEndOfWord = false;
        }
    };

    Node *root;
    int wordCount;

    void clear(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            clear(node->children[i]);
        }
        delete node;
    }

    bool hasNoChildren(Node *node) const
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                return false;
            }
        }
        return true;
    }

    bool erase(Node *node, const string &word, int depth)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (depth == word.size())
        {
            if (!node->isEndOfWord)
            {
                return false;
            }
            node->isEndOfWord = false;
            wordCount--;
            return hasNoChildren(node);
        }

        int index = word[depth] - 'a';
        if (erase(node->children[index], word, depth + 1))
        {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isEndOfWord && hasNoChildren(node);
        }
        return false;
    }

public:
    Trie()
    {
        root = new Node();
        wordCount = 0;
    }

    ~Trie()
    {
        clear(root);
    }
    void insert(const string &word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }

        if (!curr->isEndOfWord)
        {
            curr->isEndOfWord = true;
            wordCount++;
        }
    }

    bool contains(const string &word) const
    {
        Node *curr = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(const string &prefix) const
    {
        Node *curr = root;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                return false;
            }

            curr = curr->children[index];
        }
        return true;
    }

    void erase(const string &word)
    {
        erase(root, word, 0);
    }

    void clear()
    {
        clear(root);
        root = new Node();
        wordCount = 0;
    }

    bool empty() const
    {
        return wordCount == 0;
    }

    int size() const
    {
        return wordCount;
    }
};

int main()
{
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    cout << "Contains cat: " << trie.contains("cat") << endl;
    cout << "Contains car: " << trie.contains("car") << endl;
    cout << "Contains can: " << trie.contains("can") << endl;

    cout << "Starts with ca: " << trie.startsWith("ca") << endl;
    cout << "Starts with do: " << trie.startsWith("do") << endl;
    cout << "Starts with z: " << trie.startsWith("z") << endl;

    trie.erase("car");
    cout << "After erasing car:" << endl;
    cout << "Contains car: " << trie.contains("car") << endl;
    cout << "Contains cat: " << trie.contains("cat") << endl;
    return 0;
}
