class Queue: 
    def __init__(self): 
        self.queue = [] 
     
    def enqueue(self, item): 
        self.queue.append(item) 
     
    def dequeue(self): 
        if not self.is_empty(): 
            return self.queue.pop(0) 
     
    def is_empty(self): 
        return len(self.queue) == 0 
     
    def size(self): 
        return len(self.queue)

if __name__ == "__main__":

    q = Queue()

    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)

    print("Queue size after enqueuing 3 items:", q.size())

    print("Dequeued item:", q.dequeue())

    print("Queue size after dequeuing an item:", q.size())

    print("Is the queue empty?", q.is_empty())
