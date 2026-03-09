'''
Trie Data Structure

The Trie (prefix-tree) is an efficient data structure for storing strings, allowing for efficient searching, insertion, and prefix lookups.

Functions:

- 'insert(word: str)': 
    -  Inserting a word into the Trie.
    -  O(n), where n is the length of the word.

- 'search(word: str)': 
    -  Determining if a word exists in the Trie.
    -  O(n), where n is the length of the word.

- 'startsWith(prefix: str)': 
    -  Determines if the prefix of a word exists in the Trie.
    -  O(p), where p is the length of the prefix.

Space complexity:
    - In the worst case, inserting n words, each of length m can result in O(nm) space.
'''


class TrieNode():
    def __init__(self):
        self.children = {}
        self.endWord = False


class Trie():
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endWord = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return curr.endWord

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return True


trie = Trie()

# Test Case 1: Inserting and searching a word
trie.insert("apple")
assert trie.search("apple") == True
assert trie.search("app") == False
assert trie.startsWith("app") == True
assert trie.startsWith("b") == False

# Test Case 2: Inserting a prefix and searching
trie.insert("app")
assert trie.search("app") == True
assert trie.startsWith("app") == True

# Test Case 3: Searching for words that are not in the Trie
assert trie.search("banana") == False
assert trie.startsWith("ban") == False

# Test Case 4: Inserting and testing additional words
trie.insert("banana")
trie.insert("band")
assert trie.search("banana") == True
assert trie.startsWith("ban") == True
assert trie.search("band") == True
assert trie.search("bang") == False

# Test Case 5: Case sensitivity
assert trie.search("Apple") == False

# Test Case 6: Inserting and testing longer words
trie.insert("application")
assert trie.search("application") == True
assert trie.startsWith("applic") == True

print("All test cases passed :)")
