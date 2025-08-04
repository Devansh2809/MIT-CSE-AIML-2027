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
    stack1 = Stack()
    stack2=Stack()
    stack1.push(1)
    stack1.push(2)
    stack1.push(3)
    print(stack1.items)
    while not stack1.is_empty():
        stack2.push(stack1.pop())
    
    print("Queue front")
    print(stack2.pop())
    