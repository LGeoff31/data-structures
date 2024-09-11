# Trie (Prefix Tree) Data Structure

The **Trie**, or **Prefix Tree**, is a powerful and efficient data structure used for string operations, such as word search, insertion, and prefix matching. It’s perfect for handling large collections of words, making it a great choice for applications like autocomplete, dictionary storage, and spell-checking.

## 🚀 Key Features

- **Efficient Word Storage:** 
  Organizes strings by their prefixes, minimizing redundant storage.
  
- **Fast Search and Insertion:** 
  Performs searches, insertions, and prefix lookups in **O(n)** time, where **n** is the length of the input.

## ⚙️ Trie Operations

1. **`insert(word: str)`**  
   Adds a word to the Trie.  
   **Time Complexity:** O(n), where n is the length of the word.

2. **`search(word: str)`**  
   Checks if a word exists in the Trie.  
   **Time Complexity:** O(n), where n is the length of the word.

3. **`startsWith(prefix: str)`**  
   Determines if any word in the Trie starts with the given prefix.  
   **Time Complexity:** O(p), where p is the length of the prefix.

## 🛠️ Space Complexity

In the worst case, inserting **n** words, each of length **m**, results in a space complexity of **O(nm)**.
