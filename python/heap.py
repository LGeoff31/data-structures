class Heap:
    def __init__(self):
        self.arr = []
        pass

    def completeState(self):
        valid = True
        for i in range(len(self.arr)):
            if 2*i+1 < len(self.arr) and self.arr[i] < self.arr[2*i + 1]: valid = False 
            if 2*i+2 < len(self.arr) and self.arr[i] < self.arr[2*i + 2]: valid = False 
        return valid

    
    def peekMin(self): #O(1)
        return self.arr[0]
    
    def popMin(self): #O(logn)
        idx = 0
        while idx < len(arr):
            if self.arr[2*idx + 1] < self.arr[2*idx + 2]:
                self.arr[idx], self.arr[2*idx + 1] = self.arr[2*idx + 1], self.arr[idx]
                idx = 2*idx + 1
            else:
                self.arr[idx], self.arr[2*idx + 2] = self.arr[2*idx + 2], self.arr[idx]
                idx = 2*idx + 2
        return self.arr.pop()
        
    
    def push(self, val): #O(logn)
        self.arr.append(val)
        idx = -1
        while not self.completeState():
            self.arr[idx], self.arr[(idx-1)//2] = self.arr[(idx-1)//2], self.arr[idx]
            idx = (idx-1)//2
