'''
Hasdic Data Structure

The hasdic is an efficient data structure for storing key value pairs, allowing for efficient lookup, insertion, and removal.

Functions:

- 'get(key)': 
    -  Retrieves the value associated with the key
    -  O(1) average case

- 'put(key, value)': 
    -  Inserts or updates key with new value
    -  O(1) average case

- 'remove(key)': 
    -  Removes the key-value pair if the key exists
    -  O(1) average case
- '__len__()': 
    -  Returns the size of the hasdic
    -  O(1)

Space complexity:
    - O(n), where n is the number of key-value pairs
'''


class HashMap():
    def __init__(self, size):
        self.size = size
        self.dictionary = [[] for _ in range(self.size)]

    def _hash(self, key):
        return hash(key) % self.size

    def get(self, key):
        index = self._hash(key)
        bucket = self.dictionary[index]

        for i, (k, v) in enumerate(bucket):
            if key == k:
                return v
        return None

    def put(self, key, value):
        index = self._hash(key)
        bucket = self.dictionary[index]
        for i, (k, v) in enumerate(bucket):
            if key == k:
                # Already exists therefore we just update the value
                bucket[i][1] = value
                return
        bucket.append([key, value])
        return

    def remove(self, key):
        index = self._hash(key)
        bucket = self.dictionary[index]

        for i, (k, v) in enumerate(bucket):
            if key == k:
                del bucket[i]
                return True
        return False

    def __len__(self):
        return sum(len(bucket) for bucket in self.dictionary)


dic = HashMap(100)

# Test insertion and length
dic.put("apple", 1)
assert dic.get("apple") == 1
assert len(dic) == 1

# Test updating an existing key
dic.put("apple", 10)
assert dic.get("apple") == 10
assert len(dic) == 1

# Test adding another key
dic.put("banana", 2)
assert dic.get("banana") == 2
assert len(dic) == 2

# Test removing a key
dic.remove("apple")
assert dic.get("apple") is None
assert len(dic) == 1

# Test removing a non-existing key
assert not dic.remove("nonexistent")
assert len(dic) == 1

# Test edge case: retrieving a non-existent key
assert dic.get("grape") is None
