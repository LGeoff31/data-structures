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
