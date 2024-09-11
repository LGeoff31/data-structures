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


# HashMap Data Structure

The **HashMap** is a highly efficient data structure for storing and retrieving key-value pairs. It provides constant time complexity on average for basic operations like insertion, search, and deletion.

## 🚀 Key Features

- **Key-Value Pair Storage:**  
  Maps unique keys to specific values, allowing for efficient retrieval based on the key.
  
- **Fast Lookups and Modifications:**  
  Performs lookups, insertions, and deletions in **O(1)** time on average, thanks to its use of hashing.

## ⚙️ HashMap Operations

1. **`put(key: str, value: any)`**  
   Inserts a key-value pair into the HashMap. If the key already exists, updates its value.  
   **Time Complexity:** O(1) on average.

2. **`get(key: str)`**  
   Retrieves the value associated with a key.  
   **Time Complexity:** O(1) on average.

3. **`remove(key: str)`**  
   Deletes the key-value pair from the HashMap.  
   **Time Complexity:** O(1) on average.

## 🛠️ Space Complexity

The space complexity of a HashMap depends on the number of key-value pairs.
