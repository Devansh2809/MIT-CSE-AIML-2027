class Stack():
    tos=-1
    def __init__(self):
        self.stack=[]
    def push(self,x):
        self.stack.append(x)
    def pop(self):
        if not self.is_empty():
            return(self.stack.pop())
        else:
            print("Stack empty")
    def is_empty(self):
        return len(self.stack)==0
stack1=Stack()
for i in range(5):
    stack1.push(int(input("Enter element to insert to stack")))
stack2=Stack()
for i in range(5):
    stack2.push(stack1.pop())
print(stack2.stack)
print(stack2.pop())

