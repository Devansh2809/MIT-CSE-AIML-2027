class Stack: 
    def __init__(self): 
        self.items = [] 
     
    def push(self, item): 
        self.items.append(item) 
     
    def pop(self): 
        return self.items.pop() if self.items else None 
     
    def peek(self): 
        return self.items[-1] if self.items else None 
     
    def is_empty(self): 
        return not self.items


if __name__ == "__main__":
    stack = Stack()
    
    stack.push(1)
    stack.push(2)
    stack.push(3)

    print("Top item:", stack.peek())  
    
    while not stack.is_empty():
        print("Popped item:", stack.pop())
    
    print("Is stack empty?", stack.is_empty())